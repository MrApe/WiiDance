/********************************************************************************
** Form generated from reading UI file 'dancewindow.ui'
**
** Created: Wed 30. Jun 11:11:44 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DANCEWINDOW_H
#define UI_DANCEWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QMainWindow>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DanceWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QFrame *boardLeft;
    QFrame *boardRight;
    QSpacerItem *horizontalSpacer_5;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_6;
    QLCDNumber *totalLCD;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *verticalSpacer_7;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *verticalSpacer_4;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *DanceWindow)
    {
        if (DanceWindow->objectName().isEmpty())
            DanceWindow->setObjectName(QString::fromUtf8("DanceWindow"));
        DanceWindow->resize(600, 400);
        DanceWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        centralWidget = new QWidget(DanceWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 2, 1, 1, 1);

        frame = new QFrame(centralWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setMinimumSize(QSize(500, 300));
        frame->setStyleSheet(QString::fromUtf8("background-image: url(:/images/images/board.jpg);\n"
"background-repeat:no-repeat;\n"
"background-position:center;"));
        frame->setFrameShape(QFrame::Panel);
        frame->setFrameShadow(QFrame::Raised);
        frame->setLineWidth(2);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(63, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 2, 0, 1, 1);

        boardLeft = new QFrame(frame);
        boardLeft->setObjectName(QString::fromUtf8("boardLeft"));
        sizePolicy.setHeightForWidth(boardLeft->sizePolicy().hasHeightForWidth());
        boardLeft->setSizePolicy(sizePolicy);
        boardLeft->setMinimumSize(QSize(130, 225));
        boardLeft->setStyleSheet(QString::fromUtf8("background-image: url();\n"
"background-color: rgba(255, 255, 255, 0);"));
        boardLeft->setFrameShape(QFrame::NoFrame);
        boardLeft->setFrameShadow(QFrame::Plain);
        boardLeft->setLineWidth(0);

        gridLayout_2->addWidget(boardLeft, 2, 1, 1, 1);

        boardRight = new QFrame(frame);
        boardRight->setObjectName(QString::fromUtf8("boardRight"));
        sizePolicy.setHeightForWidth(boardRight->sizePolicy().hasHeightForWidth());
        boardRight->setSizePolicy(sizePolicy);
        boardRight->setMinimumSize(QSize(130, 225));
        boardRight->setStyleSheet(QString::fromUtf8("background-image: url();\n"
"background-color: rgba(255, 255, 255, 0);"));
        boardRight->setFrameShape(QFrame::NoFrame);
        boardRight->setFrameShadow(QFrame::Plain);
        boardRight->setLineWidth(0);

        gridLayout_2->addWidget(boardRight, 2, 4, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_5, 2, 5, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_6 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);

        totalLCD = new QLCDNumber(frame);
        totalLCD->setObjectName(QString::fromUtf8("totalLCD"));
        sizePolicy.setHeightForWidth(totalLCD->sizePolicy().hasHeightForWidth());
        totalLCD->setSizePolicy(sizePolicy);
        totalLCD->setMinimumSize(QSize(82, 50));
        totalLCD->setMaximumSize(QSize(70, 30));
        totalLCD->setStyleSheet(QString::fromUtf8("background-image: url();\n"
"background-color: rgb(85, 170, 127);"));

        horizontalLayout->addWidget(totalLCD);

        horizontalSpacer_7 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_7);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_7);

        horizontalSpacer_4 = new QSpacerItem(108, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer_4);


        gridLayout_2->addLayout(verticalLayout, 2, 3, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 35, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_2->addItem(verticalSpacer_5, 0, 3, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_4, 3, 3, 1, 1);


        gridLayout->addWidget(frame, 1, 1, 1, 1);

        DanceWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(DanceWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        DanceWindow->setStatusBar(statusBar);

        retranslateUi(DanceWindow);
        QObject::connect(DanceWindow, SIGNAL(totalChanged(double)), totalLCD, SLOT(display(double)));

        QMetaObject::connectSlotsByName(DanceWindow);
    } // setupUi

    void retranslateUi(QMainWindow *DanceWindow)
    {
        DanceWindow->setWindowTitle(QApplication::translate("DanceWindow", "DanceWindow", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DanceWindow: public Ui_DanceWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DANCEWINDOW_H
