#include "connectionwizard.h"
#include "ui_connectionwizard.h"

ConnectionWizard::ConnectionWizard(wiimote* board, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConnectionWizard),
    m_connected(false),
    m_board(board),
    m_timer(this)
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
    if (!m_connected)
    {
        m_connected = m_board->Connect(wiimote::FIRST_AVAILABLE);
    } else {
        m_timer.stop();
    }
}

bool ConnectionWizard::connectToBoard()
{
    connect(&m_timer,SIGNAL(timeout()),this,SLOT(connectBoard()));
    m_timer.start(10);

    show();

    while (!(m_connected || result()==QDialog::Rejected)){
    }
    return m_connected;
}
