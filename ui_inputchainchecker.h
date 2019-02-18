/********************************************************************************
** Form generated from reading UI file 'inputchainchecker.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INPUTCHAINCHECKER_H
#define UI_INPUTCHAINCHECKER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_InputChainChecker
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLineEdit *info;
    QProgressBar *progressBar;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *closeButton;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *InputChainChecker)
    {
        if (InputChainChecker->objectName().isEmpty())
            InputChainChecker->setObjectName(QStringLiteral("InputChainChecker"));
        InputChainChecker->resize(400, 118);
        QFont font;
        font.setFamily(QStringLiteral("Microsoft Sans Serif"));
        font.setPointSize(12);
        InputChainChecker->setFont(font);
        InputChainChecker->setStyleSheet(QLatin1String("QDialog {\n"
"        background: #39464d;\n"
"}\n"
""));
        gridLayout = new QGridLayout(InputChainChecker);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        info = new QLineEdit(InputChainChecker);
        info->setObjectName(QStringLiteral("info"));
        info->setMinimumSize(QSize(106, 25));
        QFont font1;
        font1.setFamily(QStringLiteral("Microsoft Sans Serif"));
        font1.setPointSize(10);
        info->setFont(font1);
        info->setStyleSheet(QLatin1String("border: 1px solid #333333;\n"
"background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #797979, stop:0.48 #696969, stop:0.52 #5e5e5e, stop:1 #4f4f4f);\n"
"padding: 1px 23px 1px 3px;\n"
"min-width: 6em;\n"
"color: #ffffff;\n"
"text-align: center;"));
        info->setReadOnly(true);

        verticalLayout->addWidget(info);

        progressBar = new QProgressBar(InputChainChecker);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setFont(font1);
        progressBar->setStyleSheet(QStringLiteral("color: white;"));
        progressBar->setValue(0);

        verticalLayout->addWidget(progressBar);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        closeButton = new QPushButton(InputChainChecker);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setMinimumSize(QSize(150, 30));
        closeButton->setFont(font);
        closeButton->setStyleSheet(QLatin1String("QPushButton {\n"
"   background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #797979, stop:0.48 #696969, stop:0.52 #5e5e5e, stop:1 #4f4f4f);\n"
"   border-color: #545454;\n"
"   border-width: 1px;\n"
"   border-radius: 5px;\n"
"   border-style: solid;\n"
"   color: white;\n"
"                     }\n"
"QPushButton:pressed {\n"
"   background: qradialgradient(cx:0.5, cy:0.5, radius:1, fx:0.5, fy:0.5, stop:0 #dddddd, stop:1 #777777);\n"
"}"));

        horizontalLayout->addWidget(closeButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(InputChainChecker);

        QMetaObject::connectSlotsByName(InputChainChecker);
    } // setupUi

    void retranslateUi(QDialog *InputChainChecker)
    {
        InputChainChecker->setWindowTitle(QApplication::translate("InputChainChecker", "Dialog", nullptr));
        closeButton->setText(QApplication::translate("InputChainChecker", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InputChainChecker: public Ui_InputChainChecker {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INPUTCHAINCHECKER_H
