#ifndef DANCEWINDOW_H
#define DANCEWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "wiiyourself/wiimote.h"

namespace Ui {
    class DanceWindow;
}

class DanceWindow : public QMainWindow {
    Q_OBJECT

    enum boardStateType {
        LEFT,
        RIGHT,
        BOTH,
        NONE,
        ERR
    };

    enum ledColor {
        OFF = 0x00,
        ON = 0x0f
    };

public:
    DanceWindow(QWidget *parent = 0);
    ~DanceWindow();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::DanceWindow *ui;
    boardStateType m_state;
    wiimote m_board;
    QTimer m_updateTimer;
    bool m_ledOn;

private slots:
    void toggleLED();
    void calcState();
    void updateState(boardStateType state);

signals:
    void stateChanged(boardStateType state);
    void totalChanged(double totalWeight);

};

#endif // DANCEWINDOW_H
