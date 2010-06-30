#ifndef CONNECTIONWIZARD_H
#define CONNECTIONWIZARD_H

#include <QDialog>
#include <QTimer>
#include "wiiyourself/wiimote.h"

namespace Ui {
    class ConnectionWizard;
}

class ConnectionWizard : public QDialog {
    Q_OBJECT
public:
    ConnectionWizard(wiimote* board, QWidget *parent = 0);
    ~ConnectionWizard();


public slots:
    bool connectToBoard();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::ConnectionWizard *ui;
    bool m_connected;
    wiimote* m_board;
    QTimer m_timer;

private slots:
    void connectBoard();
};

#endif // CONNECTIONWIZARD_H
