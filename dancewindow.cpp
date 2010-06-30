#include "dancewindow.h"
#include "ui_dancewindow.h"
#include <QMessageBox>
#include "connectionwizard.h"

#define _THR 20

DanceWindow::DanceWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DanceWindow),
    m_state(NONE),
    m_board(),
    m_updateTimer(this),
    m_ledOn(false)
{
    ui->setupUi(this);

    //ConnectionWizard wizard(&m_board,this);
    bool connected = false;
    //connected =  wizard.connectToBoard();

    while (!connected)
    {
        connected = m_board.Connect(wiimote::FIRST_AVAILABLE);
    }

    if (connected)
    {
        m_board.SetLEDs(0x01);
//        QTimer ledTimer(this);
//        connect(&ledTimer,SIGNAL(timeout()),this,SLOT(toggleLED()));
//        ledTimer.start(1000);
        if (m_board.IsConnected())
        {
            QMessageBox::information(this,
                                     "Success!",
                                     "Connection to Wii Balance Board established.",
                                     QMessageBox::Ok,
                                     QMessageBox::Ok);
            connect(&m_updateTimer,SIGNAL(timeout()),this,SLOT(calcState()));
            m_updateTimer.start(100);
            connect(this,SIGNAL(stateChanged(boardStateType)),this,SLOT(updateState(boardStateType)));
        }
    } else {
        QMessageBox::warning(this,
                             "Aborted!",
                             "Connection canceled by user.\n Have a nice Day!",
                             QMessageBox::Ok,
                             QMessageBox::Ok);
    }
}

DanceWindow::~DanceWindow()
{
    m_board.Disconnect();
    delete ui;
}

void DanceWindow::toggleLED()
{
    if (m_board.IsConnected())
    {
        if (m_ledOn)
        {
            m_board.SetLEDs(OFF);
            m_ledOn = false;
        } else {
            m_board.SetLEDs(ON);
            m_ledOn = true;
        }
    }
}

void DanceWindow::calcState()
{
    m_board.RefreshState();
    float total = m_board.BalanceBoard.Kg.Total;
    float left = m_board.BalanceBoard.Kg.TopL+m_board.BalanceBoard.Kg.BottomL;
    float right = m_board.BalanceBoard.Kg.TopR+m_board.BalanceBoard.Kg.BottomR;

    //if (m_board.RefreshState() == BALANCE_CHANGED)
    //{

    if (total > _THR)
    {

        float diff = left -right;

        if (diff > _THR )
        {
            m_state = LEFT;
        } else
        if (diff < -_THR )
        {
            m_state = RIGHT;
        } else
        {
            m_state = BOTH;
        }

    } else
    {
        m_state = NONE;
    }

    emit stateChanged(m_state);
    //}

    QString message = "Left: "+QString::number(left)+", Right: "+QString::number(right)+"Total: "+QString::number(total);
    ui->statusBar->showMessage(message);

    if (m_board.ConnectionLost())
    {
        emit stateChanged(ERR);
        m_updateTimer.stop();
        ui->statusBar->showMessage("Connection Lost!");
    }

}

void DanceWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void DanceWindow::updateState(boardStateType state)
{
    switch (state)
    {
    case LEFT:
        ui->boardLeft->setStyleSheet("background-color: rgb(0, 85, 255);");
        ui->boardRight->setStyleSheet("");
        break;
    case RIGHT:
        ui->boardRight->setStyleSheet("background-color: rgb(0, 85, 255);");
        ui->boardLeft->setStyleSheet("");
        break;
    case BOTH:
        ui->boardLeft->setStyleSheet("background-color: rgb(0, 85, 255);");
        ui->boardRight->setStyleSheet("background-color: rgb(0, 85, 255);");
        break;
    case NONE:
        ui->boardLeft->setStyleSheet("");
        ui->boardRight->setStyleSheet("");
        break;
    default:
        ui->boardLeft->setStyleSheet("background-color: rgb(255, 0, 0);");
        ui->boardRight->setStyleSheet("background-color: rgb(255, 0, 0);");
    }
}
