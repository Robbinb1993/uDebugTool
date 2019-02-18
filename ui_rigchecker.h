/********************************************************************************
** Form generated from reading UI file 'rigchecker.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RIGCHECKER_H
#define UI_RIGCHECKER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include "lineedit.h"

QT_BEGIN_NAMESPACE

class Ui_RIGChecker
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *loadRIG;
    LineEdit *iterationsLine;
    QPushButton *check;

    void setupUi(QDialog *RIGChecker)
    {
        if (RIGChecker->objectName().isEmpty())
            RIGChecker->setObjectName(QStringLiteral("RIGChecker"));
        RIGChecker->resize(433, 84);
        QFont font;
        font.setFamily(QStringLiteral("DejaVu Sans"));
        RIGChecker->setFont(font);
        RIGChecker->setStyleSheet(QLatin1String("#RIGChecker {\n"
"        background: #39464d;\n"
"}\n"
""));
        gridLayout = new QGridLayout(RIGChecker);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        loadRIG = new QPushButton(RIGChecker);
        loadRIG->setObjectName(QStringLiteral("loadRIG"));
        loadRIG->setMinimumSize(QSize(0, 30));
        QFont font1;
        font1.setFamily(QStringLiteral("Microsoft Sans Serif"));
        font1.setPointSize(12);
        loadRIG->setFont(font1);
        loadRIG->setStyleSheet(QLatin1String("QPushButton {\n"
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

        horizontalLayout->addWidget(loadRIG);

        iterationsLine = new LineEdit(RIGChecker);
        iterationsLine->setObjectName(QStringLiteral("iterationsLine"));
        iterationsLine->setMinimumSize(QSize(80, 20));
        iterationsLine->setMaximumSize(QSize(16777215, 30));
        iterationsLine->setFont(font1);
        iterationsLine->setStyleSheet(QLatin1String("QLineEdit {\n"
"border: 1px solid #333333;\n"
"	border-radius: 5px;\n"
"	background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #797979, stop:0.48 #696969, stop:0.52 #5e5e5e, stop:1 #4f4f4f);\n"
"	min-width: 6em;\n"
"	color: #ffffff;\n"
"\n"
"padding: 0px;\n"
"text-align: center;\n"
"}"));

        horizontalLayout->addWidget(iterationsLine);

        check = new QPushButton(RIGChecker);
        check->setObjectName(QStringLiteral("check"));
        check->setMinimumSize(QSize(0, 30));
        check->setFont(font1);
        check->setStyleSheet(QLatin1String("QPushButton {\n"
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

        horizontalLayout->addWidget(check);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 2);
        horizontalLayout->setStretch(2, 1);

        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        retranslateUi(RIGChecker);

        QMetaObject::connectSlotsByName(RIGChecker);
    } // setupUi

    void retranslateUi(QDialog *RIGChecker)
    {
        RIGChecker->setWindowTitle(QApplication::translate("RIGChecker", "Dialog", nullptr));
        loadRIG->setText(QApplication::translate("RIGChecker", "Load RIG", nullptr));
        iterationsLine->setText(QApplication::translate("RIGChecker", "Total iterations: 1", nullptr));
        iterationsLine->setPlaceholderText(QString());
        check->setText(QApplication::translate("RIGChecker", "Check", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RIGChecker: public Ui_RIGChecker {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RIGCHECKER_H
