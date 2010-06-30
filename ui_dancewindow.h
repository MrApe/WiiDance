/********************************************************************************
** Form generated from reading UI file 'dancewindow.ui'
**
** Created: Thu 17. Jun 14:01:13 2010
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
#include <QtGui/QMainWindow>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DanceWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QFrame *boardLeft;
    QFrame *boardRight;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *DanceWindow)
    {
        if (DanceWindow->objectName().isEmpty())
            DanceWindow->setObjectName(QString::fromUtf8("DanceWindow"));
        DanceWindow->resize(600, 400);
        centralWidget = new QWidget(DanceWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setMinimumSize(QSize(400, 200));
        frame->setFrameShape(QFrame::Panel);
        frame->setFrameShadow(QFrame::Raised);
        frame->setLineWidth(2);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        boardLeft = new QFrame(frame);
        boardLeft->setObjectName(QString::fromUtf8("boardLeft"));
        boardLeft->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 85, 255);"));
        boardLeft->setFrameShape(QFrame::NoFrame);
        boardLeft->setFrameShadow(QFrame::Plain);
        boardLeft->setLineWidth(0);

        horizontalLayout->addWidget(boardLeft);

        boardRight = new QFrame(frame);
        boardRight->setObjectName(QString::fromUtf8("boardRight"));
        boardRight->setFrameShape(QFrame::NoFrame);
        boardRight->setFrameShadow(QFrame::Plain);
        boardRight->setLineWidth(0);

        horizontalLayout->addWidget(boardRight);


        gridLayout->addWidget(frame, 1, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 2, 1, 1, 1);

        DanceWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(DanceWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        DanceWindow->setStatusBar(statusBar);

        retranslateUi(DanceWindow);

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
