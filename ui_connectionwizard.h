/********************************************************************************
** Form generated from reading UI file 'connectionwizard.ui'
**
** Created: Thu 17. Jun 11:11:34 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNECTIONWIZARD_H
#define UI_CONNECTIONWIZARD_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QProgressBar>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ConnectionWizard
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QProgressBar *progressBar;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ConnectionWizard)
    {
        if (ConnectionWizard->objectName().isEmpty())
            ConnectionWizard->setObjectName(QString::fromUtf8("ConnectionWizard"));
        ConnectionWizard->resize(400, 93);
        verticalLayout = new QVBoxLayout(ConnectionWizard);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(ConnectionWizard);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        progressBar = new QProgressBar(ConnectionWizard);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setMinimum(0);
        progressBar->setValue(100);
        progressBar->setTextVisible(false);

        verticalLayout->addWidget(progressBar);

        buttonBox = new QDialogButtonBox(ConnectionWizard);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(ConnectionWizard);
        QObject::connect(buttonBox, SIGNAL(accepted()), ConnectionWizard, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ConnectionWizard, SLOT(reject()));

        QMetaObject::connectSlotsByName(ConnectionWizard);
    } // setupUi

    void retranslateUi(QDialog *ConnectionWizard)
    {
        ConnectionWizard->setWindowTitle(QApplication::translate("ConnectionWizard", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ConnectionWizard", "Connecting to Wii Balance Board. This may take a while...", 0, QApplication::UnicodeUTF8));
        progressBar->setFormat(QString());
    } // retranslateUi

};

namespace Ui {
    class ConnectionWizard: public Ui_ConnectionWizard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECTIONWIZARD_H
