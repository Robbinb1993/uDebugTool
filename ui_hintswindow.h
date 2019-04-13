/********************************************************************************
** Form generated from reading UI file 'hintswindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HINTSWINDOW_H
#define UI_HINTSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <infotable.h>

QT_BEGIN_NAMESPACE

class Ui_HintsWindow
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    InfoTable *hintTable;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QTextBrowser *hintText;

    void setupUi(QDialog *HintsWindow)
    {
        if (HintsWindow->objectName().isEmpty())
            HintsWindow->setObjectName(QStringLiteral("HintsWindow"));
        HintsWindow->resize(644, 377);
        QFont font;
        font.setFamily(QStringLiteral("Microsoft Sans Serif"));
        font.setPointSize(12);
        HintsWindow->setFont(font);
        HintsWindow->setStyleSheet(QLatin1String("#HintsWindow {\n"
"        background: #39464d;\n"
"}\n"
"\n"
"QTableWidget QTableCornerButton::section {\n"
"    background-color: #242e33;\n"
"}\n"
"\n"
""));
        gridLayout = new QGridLayout(HintsWindow);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(HintsWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(106, 30));
        label->setFont(font);
        label->setLayoutDirection(Qt::LeftToRight);
        label->setStyleSheet(QLatin1String("border: 1px solid #333333;\n"
"border-top-left-radius: 5px;\n"
"border-top-right-radius: 5px;\n"
"background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #797979, stop:0.48 #696969, stop:0.52 #5e5e5e, stop:1 #4f4f4f);\n"
"padding: 1px 23px 1px 3px;\n"
"min-width: 6em;\n"
"color: #ffffff;\n"
"text-align: center;"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        hintTable = new InfoTable(HintsWindow, "Hint");
        hintTable->setObjectName(QStringLiteral("hintTable"));
        QFont font1;
        font1.setFamily(QStringLiteral("DejaVu Sans"));
        font1.setPointSize(12);
        hintTable->setFont(font1);

        verticalLayout->addWidget(hintTable);


        horizontalLayout->addLayout(verticalLayout);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_2 = new QLabel(HintsWindow);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(106, 30));
        label_2->setFont(font);
        label_2->setStyleSheet(QLatin1String("border: 1px solid #333333;\n"
"border-top-left-radius: 5px;\n"
"border-top-right-radius: 5px;\n"
"background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #797979, stop:0.48 #696969, stop:0.52 #5e5e5e, stop:1 #4f4f4f);\n"
"padding: 1px 23px 1px 3px;\n"
"min-width: 6em;\n"
"color: #ffffff;\n"
"text-align: center;"));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_2);

        hintText = new QTextBrowser(HintsWindow);
        hintText->setObjectName(QStringLiteral("hintText"));
        hintText->setFont(font1);

        verticalLayout_2->addWidget(hintText);


        gridLayout->addLayout(verticalLayout_2, 0, 1, 1, 1);


        retranslateUi(HintsWindow);

        QMetaObject::connectSlotsByName(HintsWindow);
    } // setupUi

    void retranslateUi(QDialog *HintsWindow)
    {
        HintsWindow->setWindowTitle(QApplication::translate("HintsWindow", "Dialog", nullptr));
        label->setText(QApplication::translate("HintsWindow", "Select hint", nullptr));
        label_2->setText(QApplication::translate("HintsWindow", "Hint", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HintsWindow: public Ui_HintsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HINTSWINDOW_H
