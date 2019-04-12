/********************************************************************************
** Form generated from reading UI file 'codeeditor.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CODEEDITOR_H
#define UI_CODEEDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include "editor.h"

QT_BEGIN_NAMESPACE

class Ui_CodeEditor
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *horizontalLayout_3;
    QComboBox *languageSelect;
    QPushButton *loaderButton;
    QLineEdit *flagLine;
    QPushButton *submitCodeButton;
    QSpacerItem *verticalSpacer;
    QLabel *label;
    Editor *codeEditor;
    QLabel *loaderLabel;
    QPlainTextEdit *loaderOutput;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_2;

    void setupUi(QDialog *CodeEditor)
    {
        if (CodeEditor->objectName().isEmpty())
            CodeEditor->setObjectName(QStringLiteral("CodeEditor"));
        CodeEditor->resize(928, 632);
        QFont font;
        font.setFamily(QStringLiteral("Microsoft Sans Serif"));
        CodeEditor->setFont(font);
        CodeEditor->setStyleSheet(QLatin1String("QDialog {\n"
"        background: #39464d;\n"
"}\n"
"\n"
"QMessageBox {\n"
"        background: rgb(220, 220, 220);\n"
"}"));
        gridLayout = new QGridLayout(CodeEditor);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        languageSelect = new QComboBox(CodeEditor);
        languageSelect->addItem(QString());
        languageSelect->addItem(QString());
        languageSelect->addItem(QString());
        languageSelect->addItem(QString());
        languageSelect->addItem(QString());
        languageSelect->addItem(QString());
        languageSelect->setObjectName(QStringLiteral("languageSelect"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(languageSelect->sizePolicy().hasHeightForWidth());
        languageSelect->setSizePolicy(sizePolicy);
        languageSelect->setMinimumSize(QSize(104, 30));
        languageSelect->setMaximumSize(QSize(16777215, 16777215));
        QFont font1;
        font1.setFamily(QStringLiteral("Microsoft Sans Serif"));
        font1.setPointSize(12);
        languageSelect->setFont(font1);
        languageSelect->setLayoutDirection(Qt::LeftToRight);
        languageSelect->setStyleSheet(QLatin1String("border-radius: 5px;\n"
"background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #797979, stop:0.48 #696969, stop:0.52 #5e5e5e, stop:1 #4f4f4f);\n"
"padding: 1px 23px 1px 3px;\n"
"min-width: 6em;\n"
"color: #ffffff;\n"
"border: none;\n"
"\n"
""));

        horizontalLayout_3->addWidget(languageSelect);

        loaderButton = new QPushButton(CodeEditor);
        loaderButton->setObjectName(QStringLiteral("loaderButton"));
        loaderButton->setMinimumSize(QSize(80, 30));
        loaderButton->setMaximumSize(QSize(120, 16777215));
        loaderButton->setFont(font1);
        loaderButton->setStyleSheet(QLatin1String("QPushButton {\n"
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

        horizontalLayout_3->addWidget(loaderButton);

        flagLine = new QLineEdit(CodeEditor);
        flagLine->setObjectName(QStringLiteral("flagLine"));
        flagLine->setMinimumSize(QSize(80, 30));
        flagLine->setFont(font1);
        flagLine->setStyleSheet(QLatin1String("QLineEdit {\n"
"border: 1px solid #333333;\n"
"        border-radius: 5px;\n"
"        background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #797979, stop:0.48 #696969, stop:0.52 #5e5e5e, stop:1 #4f4f4f);\n"
"        min-width: 6em;\n"
"        color: #ffffff;\n"
"\n"
"padding: 0px;\n"
"text-align: center;\n"
"}"));

        horizontalLayout_3->addWidget(flagLine);

        submitCodeButton = new QPushButton(CodeEditor);
        submitCodeButton->setObjectName(QStringLiteral("submitCodeButton"));
        submitCodeButton->setMinimumSize(QSize(0, 30));
        submitCodeButton->setMaximumSize(QSize(16777215, 30));
        submitCodeButton->setFont(font1);
        submitCodeButton->setStyleSheet(QLatin1String("QPushButton {\n"
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

        horizontalLayout_3->addWidget(submitCodeButton);

        horizontalLayout_3->setStretch(0, 4);
        horizontalLayout_3->setStretch(1, 3);
        horizontalLayout_3->setStretch(2, 4);
        horizontalLayout_3->setStretch(3, 3);

        horizontalLayout->addLayout(horizontalLayout_3);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 6, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        label = new QLabel(CodeEditor);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(106, 20));
        label->setFont(font1);
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

        codeEditor = new Editor(CodeEditor);
        codeEditor->setObjectName(QStringLiteral("codeEditor"));
        QFont font2;
        font2.setFamily(QStringLiteral("Courier"));
        font2.setPointSize(12);
        font2.setBold(false);
        font2.setWeight(50);
        codeEditor->setFont(font2);
        codeEditor->setStyleSheet(QLatin1String("QPlainTextEdit {\n"
"background: white;\n"
"}"));
        codeEditor->setTabStopWidth(30);

        verticalLayout->addWidget(codeEditor);

        loaderLabel = new QLabel(CodeEditor);
        loaderLabel->setObjectName(QStringLiteral("loaderLabel"));
        loaderLabel->setMinimumSize(QSize(106, 20));
        loaderLabel->setFont(font1);
        loaderLabel->setStyleSheet(QLatin1String("border: 1px solid #333333;\n"
"background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #797979, stop:0.48 #696969, stop:0.52 #5e5e5e, stop:1 #4f4f4f);\n"
"padding: 1px 23px 1px 3px;\n"
"min-width: 6em;\n"
"color: #ffffff;\n"
"text-align: center;"));
        loaderLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(loaderLabel);

        loaderOutput = new QPlainTextEdit(CodeEditor);
        loaderOutput->setObjectName(QStringLiteral("loaderOutput"));
        loaderOutput->setFont(font2);
        loaderOutput->setStyleSheet(QLatin1String("QPlainTextEdit {\n"
"background: white;\n"
"}"));
        loaderOutput->setReadOnly(true);

        verticalLayout->addWidget(loaderOutput);

        verticalSpacer_2 = new QSpacerItem(20, 2, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));

        verticalLayout->addLayout(horizontalLayout_2);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(3, 15);
        verticalLayout->setStretch(5, 4);

        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(CodeEditor);

        QMetaObject::connectSlotsByName(CodeEditor);
    } // setupUi

    void retranslateUi(QDialog *CodeEditor)
    {
        CodeEditor->setWindowTitle(QApplication::translate("CodeEditor", "Dialog", nullptr));
        languageSelect->setItemText(0, QApplication::translate("CodeEditor", "Programming language", nullptr));
        languageSelect->setItemText(1, QApplication::translate("CodeEditor", "C", nullptr));
        languageSelect->setItemText(2, QApplication::translate("CodeEditor", "C++", nullptr));
        languageSelect->setItemText(3, QApplication::translate("CodeEditor", "C#", nullptr));
        languageSelect->setItemText(4, QApplication::translate("CodeEditor", "Java", nullptr));
        languageSelect->setItemText(5, QApplication::translate("CodeEditor", "Python", nullptr));

        loaderButton->setText(QApplication::translate("CodeEditor", "Load", nullptr));
        flagLine->setPlaceholderText(QApplication::translate("CodeEditor", "Insert flags", nullptr));
        submitCodeButton->setText(QApplication::translate("CodeEditor", "Open code file", nullptr));
        label->setText(QApplication::translate("CodeEditor", "Editor", nullptr));
        loaderLabel->setText(QApplication::translate("CodeEditor", "Output", nullptr));
        loaderOutput->setPlainText(QString());
    } // retranslateUi

};

namespace Ui {
    class CodeEditor: public Ui_CodeEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CODEEDITOR_H
