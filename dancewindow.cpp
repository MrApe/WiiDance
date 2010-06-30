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

    ConnectionWizard wizard(&m_board,this);
    bool connected = false;
    connected =  wizard.connectToBoard();

    if (connected)
    {
        m_board.SetLEDs(0x01);
        QTimer ledTimer(this);
        connect(&ledTimer,SIGNAL(timeout()),this,SLOT(toggleLED()));
        ledTimer.start(1000);
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
        QMessageBox warn;
        warn.setText("No Connection!");
        warn.setInformativeText("No board found or connection canceled by user.");
        warn.setIcon(QMessageBox::Information);
        warn.setDetailedText("However, you can play by typing left and right arrow keys.");
        warn.setStandardButtons(QMessageBox::Ok|QMessageBox::Cancel);

        int ret = warn.exec();
        if (ret == QMessageBox::Rejected)
        {
            close();
        }
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
    double total = m_board.BalanceBoard.Kg.Total;
    double left = m_board.BalanceBoard.Kg.TopL+m_board.BalanceBoard.Kg.BottomL;
    double right = m_board.BalanceBoard.Kg.TopR+m_board.BalanceBoard.Kg.BottomR;

    //if (m_board.RefreshState() == BALANCE_CHANGED)
    //{

    if (total > _THR)
    {

        double diff = left -right;

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
    emit totalChanged(total);
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
        ui->boardLeft->setStyleSheet("background-color: rgb(0, 85, 255);background-image: url();");
        ui->boardRight->setStyleSheet("background-image: url();background-color: rgba(255, 255, 255, 0);");
        break;
    case RIGHT:
        ui->boardRight->setStyleSheet("background-color: rgb(0, 85, 255);background-image: url();");
        ui->boardLeft->setStyleSheet("background-image: url();background-color: rgba(255, 255, 255, 0);");
        break;
    case BOTH:
        ui->boardLeft->setStyleSheet("background-color: rgb(0, 85, 255);background-image: url();");
        ui->boardRight->setStyleSheet("background-color: rgb(0, 85, 255);background-image: url();");
        break;
    case NONE:
        ui->boardLeft->setStyleSheet("background-image: url();background-color: rgba(255, 255, 255, 0);");
        ui->boardRight->setStyleSheet("background-image: url();background-color: rgba(255, 255, 255, 0);");
        break;
    default:
        ui->boardLeft->setStyleSheet("background-color: rgb(255, 0, 0);");
        ui->boardRight->setStyleSheet("background-color: rgb(255, 0, 0);");
    }
}
