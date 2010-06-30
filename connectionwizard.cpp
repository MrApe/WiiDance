#define _MAX 100

#include "connectionwizard.h"
#include "ui_connectionwizard.h"

ConnectionWizard::ConnectionWizard(wiimote* board, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConnectionWizard),
    m_connected(false),
    m_board(board),
    m_timer(this),
    m_counter(0)
{
    ui->setupUi(this);
    setWindowTitle("Connecting..");

    setResult(QDialog::Accepted);
}

ConnectionWizard::~ConnectionWizard()
{
    delete ui;
}

void ConnectionWizard::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void ConnectionWizard::connectBoard()
{
    if (!m_connected && m_counter < _MAX)
    {
        m_connected = m_board->Connect(wiimote::FIRST_AVAILABLE);
        m_counter++;
        ui->progressBar->setValue((100/_MAX)*m_counter);
    } else {
        m_timer.stop();
        reject();
    }
}

bool ConnectionWizard::connectToBoard()
{
    connect(&m_timer,SIGNAL(timeout()),this,SLOT(connectBoard()));
    m_timer.start(100);

    exec();

    return m_connected;
}
