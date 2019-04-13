/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <infotable.h>
#include "editor.h"
#include "lineedit.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_11;
    QComboBox *judgeSelect;
    QLineEdit *problemId;
    QPushButton *hintButton;
    QLabel *loadLabel;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_6;
    QLabel *probNameLabel;
    QLabel *label_7;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *verticalSpacer_2;
    InfoTable *inputTable;
    QLabel *label_3;
    Editor *customIn;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_13;
    QPushButton *searchProb;
    QPushButton *checkIn;
    QPushButton *checkAll;
    QPushButton *checkRIG;
    QPushButton *submitCode;
    LineEdit *timeLimitIn;
    QSpacerItem *verticalSpacer_3;
    QLabel *label;
    QLineEdit *resultLine;
    QHBoxLayout *horizontalLayout_9;
    QHBoxLayout *horizontalLayout;
    QLabel *label_4;
    QLabel *acOutLabel;
    QPushButton *filter;
    QLabel *yourOutLabel;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_6;
    Editor *acOut;
    Editor *userOut;
    QSpacerItem *verticalSpacer_4;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1260, 622);
        QFont font;
        font.setFamily(QStringLiteral("Microsoft Sans Serif"));
        font.setPointSize(12);
        font.setBold(false);
        font.setWeight(50);
        MainWindow->setFont(font);
        MainWindow->setStyleSheet(QLatin1String("QMainWindow {\n"
"	background: #39464d;\n"
"}\n"
"\n"
"QComboBox {\n"
"	background: #39464d;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"	background: #39464d;\n"
"}\n"
"\n"
"QTableWidget QTableCornerButton::section {\n"
"    background-color: #242e33;\n"
"}\n"
"\n"
"QTextEdit:hover {\n"
"  border: 1px solid #3385ff;\n"
"}\n"
"\n"
"QPlainTextEdit:hover {\n"
"  border: 1px solid #3385ff;\n"
"}\n"
"\n"
"QTableWidget:hover {\n"
"  border: 1px solid #3385ff;\n"
"}\n"
"\n"
"QToolTip {\n"
"	border: none;\n"
"	background-color: #F4F9D4;\n"
"	color: black;\n"
"	font-size: 12px;\n"
"}\n"
"\n"
""));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setStyleSheet(QStringLiteral(""));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout_3->setContentsMargins(6, 6, 6, 6);
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(3);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        judgeSelect = new QComboBox(centralWidget);
        judgeSelect->addItem(QString());
        judgeSelect->addItem(QString());
        judgeSelect->addItem(QString());
        judgeSelect->addItem(QString());
        judgeSelect->addItem(QString());
        judgeSelect->addItem(QString());
        judgeSelect->addItem(QString());
        judgeSelect->addItem(QString());
        judgeSelect->addItem(QString());
        judgeSelect->addItem(QString());
        judgeSelect->setObjectName(QStringLiteral("judgeSelect"));
        judgeSelect->setMinimumSize(QSize(104, 0));
        judgeSelect->setMaximumSize(QSize(240, 40));
        QFont font1;
        font1.setFamily(QStringLiteral("Microsoft Sans Serif"));
        font1.setPointSize(12);
        judgeSelect->setFont(font1);
        judgeSelect->setLayoutDirection(Qt::LeftToRight);
        judgeSelect->setStyleSheet(QLatin1String("border-radius: 5px;\n"
"background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #797979, stop:0.48 #696969, stop:0.52 #5e5e5e, stop:1 #4f4f4f);\n"
"padding: 1px 23px 1px 3px;\n"
"min-width: 6em;\n"
"color: #ffffff;\n"
"border: none;\n"
"\n"
""));

        horizontalLayout_11->addWidget(judgeSelect);

        problemId = new QLineEdit(centralWidget);
        problemId->setObjectName(QStringLiteral("problemId"));
        problemId->setMinimumSize(QSize(80, 40));
        problemId->setFont(font1);
        problemId->setStyleSheet(QLatin1String("QLineEdit {\n"
"border: 1px solid #333333;\n"
"	border-radius: 5px;\n"
"	background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #797979, stop:0.48 #696969, stop:0.52 #5e5e5e, stop:1 #4f4f4f);\n"
"	min-width: 6em;\n"
"	color: #ffffff;\n"
"\n"
"padding: 0px;\n"
"text-align: center;\n"
"}"));
        problemId->setAlignment(Qt::AlignCenter);

        horizontalLayout_11->addWidget(problemId);

        hintButton = new QPushButton(centralWidget);
        hintButton->setObjectName(QStringLiteral("hintButton"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(hintButton->sizePolicy().hasHeightForWidth());
        hintButton->setSizePolicy(sizePolicy);
        hintButton->setMinimumSize(QSize(40, 40));
        hintButton->setMaximumSize(QSize(40, 40));
        QFont font2;
        font2.setFamily(QStringLiteral("DejaVu Sans"));
        hintButton->setFont(font2);
        hintButton->setStyleSheet(QLatin1String("QPushButton {\n"
"   background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #797979, stop:0.48 #696969, stop:0.52 #5e5e5e, stop:1 #4f4f4f);\n"
"   border-color: #545454;\n"
"   border-width: 1px;\n"
"   border-radius: 5px;\n"
"   border-style: solid;\n"
"   color: white;\n"
" }\n"
"\n"
"QPushButton:pressed {\n"
"   background: qradialgradient(cx:0.5, cy:0.5, radius:1, fx:0.5, fy:0.5, stop:0 #dddddd, stop:1 #777777);\n"
"}"));

        horizontalLayout_11->addWidget(hintButton);

        loadLabel = new QLabel(centralWidget);
        loadLabel->setObjectName(QStringLiteral("loadLabel"));
        loadLabel->setMinimumSize(QSize(40, 40));
        loadLabel->setMaximumSize(QSize(40, 40));
        loadLabel->setFont(font2);
        loadLabel->setStyleSheet(QLatin1String("   background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #797979, stop:0.48 #696969, stop:0.52 #5e5e5e, stop:1 #4f4f4f);\n"
"   border-color: #545454;\n"
"   border-width: 1px;\n"
"   border-radius: 5px;\n"
"   border-style: solid;\n"
"   color: white;"));

        horizontalLayout_11->addWidget(loadLabel);

        horizontalLayout_11->setStretch(0, 3);
        horizontalLayout_11->setStretch(1, 2);

        verticalLayout_3->addLayout(horizontalLayout_11);

        verticalSpacer = new QSpacerItem(0, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_3->addItem(verticalSpacer);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        probNameLabel = new QLabel(centralWidget);
        probNameLabel->setObjectName(QStringLiteral("probNameLabel"));
        probNameLabel->setFont(font1);
        probNameLabel->setLayoutDirection(Qt::LeftToRight);
        probNameLabel->setStyleSheet(QLatin1String("border-top-left-radius: 5px;\n"
"border-top-right-radius: 5px;\n"
"background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #797979, stop:0.48 #696969, stop:0.52 #5e5e5e, stop:1 #4f4f4f);\n"
"padding: 1px 23px 1px 3px;\n"
"min-width: 6em;\n"
"color: #ffffff;\n"
"text-align: center;"));
        probNameLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(probNameLabel);

        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setMinimumSize(QSize(0, 1));
        label_7->setMaximumSize(QSize(16777215, 1));
        label_7->setStyleSheet(QStringLiteral("background: gray;"));

        verticalLayout_6->addWidget(label_7);

        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMinimumSize(QSize(104, 20));
        label_6->setFont(font1);
        label_6->setStyleSheet(QLatin1String("background: #4f4f4f;\n"
"padding: 1px 23px 1px 3px;\n"
"min-width: 6em;\n"
"color: #ffffff;\n"
"text-align: center;"));
        label_6->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(label_6);


        verticalLayout_3->addLayout(verticalLayout_6);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(0);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));

        verticalLayout_3->addLayout(horizontalLayout_8);

        verticalSpacer_2 = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_3->addItem(verticalSpacer_2);

        inputTable = new InfoTable(centralWidget, "Test case");
        inputTable->setObjectName(QStringLiteral("inputTable"));
        inputTable->setFont(font1);
        inputTable->setStyleSheet(QStringLiteral(""));

        verticalLayout_3->addWidget(inputTable);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font1);
        label_3->setLayoutDirection(Qt::LeftToRight);
        label_3->setStyleSheet(QLatin1String("border: 1px solid #333333;\n"
"	background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #797979, stop:0.48 #696969, stop:0.52 #5e5e5e, stop:1 #4f4f4f);\n"
"	padding: 1px 23px 1px 3px;\n"
"	min-width: 6em;\n"
"	color: #ffffff;"));
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_3);

        customIn = new Editor(centralWidget);
        customIn->setObjectName(QStringLiteral("customIn"));
        QFont font3;
        font3.setFamily(QStringLiteral("Courier"));
        font3.setPointSize(12);
        font3.setBold(false);
        font3.setWeight(50);
        customIn->setFont(font3);
        customIn->setStyleSheet(QLatin1String("QPlainTextEdit {\n"
"background: white;\n"
"}"));

        verticalLayout_3->addWidget(customIn);


        horizontalLayout_2->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(6, 6, 6, 6);
        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(3);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        searchProb = new QPushButton(centralWidget);
        searchProb->setObjectName(QStringLiteral("searchProb"));
        searchProb->setMinimumSize(QSize(0, 40));
        searchProb->setFont(font1);
        searchProb->setStyleSheet(QLatin1String("QPushButton {\n"
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

        horizontalLayout_13->addWidget(searchProb);

        checkIn = new QPushButton(centralWidget);
        checkIn->setObjectName(QStringLiteral("checkIn"));
        checkIn->setMinimumSize(QSize(0, 40));
        checkIn->setMaximumSize(QSize(16777215, 16777215));
        checkIn->setFont(font1);
        checkIn->setStyleSheet(QLatin1String("QPushButton {\n"
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

        horizontalLayout_13->addWidget(checkIn);

        checkAll = new QPushButton(centralWidget);
        checkAll->setObjectName(QStringLiteral("checkAll"));
        checkAll->setMinimumSize(QSize(0, 40));
        checkAll->setFont(font1);
        checkAll->setStyleSheet(QLatin1String("QPushButton {\n"
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

        horizontalLayout_13->addWidget(checkAll);

        checkRIG = new QPushButton(centralWidget);
        checkRIG->setObjectName(QStringLiteral("checkRIG"));
        checkRIG->setMinimumSize(QSize(0, 40));
        checkRIG->setFont(font1);
        checkRIG->setStyleSheet(QLatin1String("QPushButton {\n"
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

        horizontalLayout_13->addWidget(checkRIG);

        submitCode = new QPushButton(centralWidget);
        submitCode->setObjectName(QStringLiteral("submitCode"));
        submitCode->setMinimumSize(QSize(0, 40));
        submitCode->setFont(font1);
        submitCode->setStyleSheet(QLatin1String("QPushButton {\n"
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

        horizontalLayout_13->addWidget(submitCode);

        timeLimitIn = new LineEdit(centralWidget);
        timeLimitIn->setObjectName(QStringLiteral("timeLimitIn"));
        timeLimitIn->setMinimumSize(QSize(80, 40));
        timeLimitIn->setFont(font1);
        timeLimitIn->setStyleSheet(QLatin1String("QLineEdit {\n"
"border: 1px solid #333333;\n"
"	border-radius: 5px;\n"
"	background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #797979, stop:0.48 #696969, stop:0.52 #5e5e5e, stop:1 #4f4f4f);\n"
"	min-width: 6em;\n"
"	color: #ffffff;\n"
"\n"
"padding: 0px;\n"
"text-align: center;\n"
"}"));
        timeLimitIn->setAlignment(Qt::AlignCenter);

        horizontalLayout_13->addWidget(timeLimitIn);

        horizontalLayout_13->setStretch(0, 3);
        horizontalLayout_13->setStretch(1, 2);
        horizontalLayout_13->setStretch(2, 2);
        horizontalLayout_13->setStretch(3, 2);
        horizontalLayout_13->setStretch(4, 3);
        horizontalLayout_13->setStretch(5, 4);

        verticalLayout_2->addLayout(horizontalLayout_13);

        verticalSpacer_3 = new QSpacerItem(0, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_3);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
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

        verticalLayout_2->addWidget(label);

        resultLine = new QLineEdit(centralWidget);
        resultLine->setObjectName(QStringLiteral("resultLine"));
        resultLine->setMinimumSize(QSize(0, 21));
        resultLine->setMaximumSize(QSize(16777215, 21));
        QFont font4;
        font4.setFamily(QStringLiteral("Microsoft Sans Serif"));
        font4.setPointSize(10);
        resultLine->setFont(font4);
        resultLine->setStyleSheet(QLatin1String("QLineEdit {\n"
"background: white;\n"
"border-left: 1px solid #333333;\n"
"border-right: 1px solid #333333;\n"
"}"));
        resultLine->setReadOnly(true);

        verticalLayout_2->addWidget(resultLine);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(0);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setStyleSheet(QLatin1String("color: #242e33;\n"
"background: #242e33;\n"
"padding: 0px;\n"
"border-left: 1px solid #333333;"));

        horizontalLayout->addWidget(label_4);

        acOutLabel = new QLabel(centralWidget);
        acOutLabel->setObjectName(QStringLiteral("acOutLabel"));
        acOutLabel->setMinimumSize(QSize(0, 22));
        acOutLabel->setFont(font4);
        acOutLabel->setStyleSheet(QLatin1String("color: white;\n"
"background: #242e33;\n"
"padding: 0px;\n"
""));
        acOutLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(acOutLabel);

        filter = new QPushButton(centralWidget);
        filter->setObjectName(QStringLiteral("filter"));
        filter->setFont(font4);
        filter->setStyleSheet(QLatin1String("color: rgb(96, 189, 236);\n"
"background: #2d3a40;\n"
"text-align: center;\n"
"\n"
""));
        filter->setCheckable(true);

        horizontalLayout->addWidget(filter);

        yourOutLabel = new QLabel(centralWidget);
        yourOutLabel->setObjectName(QStringLiteral("yourOutLabel"));
        yourOutLabel->setFont(font4);
        yourOutLabel->setLayoutDirection(Qt::LeftToRight);
        yourOutLabel->setStyleSheet(QLatin1String("color: white;\n"
"background: #242e33;\n"
"padding: 0px;\n"
""));
        yourOutLabel->setScaledContents(false);
        yourOutLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(yourOutLabel);

        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setStyleSheet(QLatin1String("color: #242e33;\n"
"background: #242e33;\n"
"padding: 0px;\n"
"border-right: 1px solid #333333;\n"
""));

        horizontalLayout->addWidget(label_5);

        horizontalLayout->setStretch(1, 3);
        horizontalLayout->setStretch(2, 1);
        horizontalLayout->setStretch(3, 3);

        horizontalLayout_9->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(horizontalLayout_9);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        acOut = new Editor(centralWidget);
        acOut->setObjectName(QStringLiteral("acOut"));
        QFont font5;
        font5.setFamily(QStringLiteral("Courier"));
        font5.setPointSize(12);
        acOut->setFont(font5);
        acOut->setStyleSheet(QLatin1String("QPlainTextEdit {\n"
"background: white;\n"
"}"));
        acOut->setLineWidth(1);

        horizontalLayout_6->addWidget(acOut);

        userOut = new Editor(centralWidget);
        userOut->setObjectName(QStringLiteral("userOut"));
        userOut->setFont(font5);
        userOut->setLayoutDirection(Qt::LeftToRight);
        userOut->setStyleSheet(QLatin1String("QPlainTextEdit {\n"
"background: white;\n"
"}"));

        horizontalLayout_6->addWidget(userOut);


        verticalLayout_2->addLayout(horizontalLayout_6);

        verticalSpacer_4 = new QSpacerItem(20, 2, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_4);


        horizontalLayout_2->addLayout(verticalLayout_2);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 2);

        verticalLayout->addLayout(horizontalLayout_2);


        gridLayout_2->addLayout(verticalLayout, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1260, 21));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        judgeSelect->setItemText(0, QApplication::translate("MainWindow", "Select judge", nullptr));
        judgeSelect->setItemText(1, QApplication::translate("MainWindow", "Toph", nullptr));
        judgeSelect->setItemText(2, QApplication::translate("MainWindow", "Dev Skill", nullptr));
        judgeSelect->setItemText(3, QApplication::translate("MainWindow", "CATS Online Judge", nullptr));
        judgeSelect->setItemText(4, QApplication::translate("MainWindow", "URI Online Judge", nullptr));
        judgeSelect->setItemText(5, QApplication::translate("MainWindow", "Facebook Hacker Cup", nullptr));
        judgeSelect->setItemText(6, QApplication::translate("MainWindow", "Light Online Judge", nullptr));
        judgeSelect->setItemText(7, QApplication::translate("MainWindow", "Google Code Jam", nullptr));
        judgeSelect->setItemText(8, QApplication::translate("MainWindow", "UVa Online Judge", nullptr));
        judgeSelect->setItemText(9, QApplication::translate("MainWindow", "ACM-ICPC Live Archive", nullptr));

        judgeSelect->setCurrentText(QApplication::translate("MainWindow", "Select judge", nullptr));
        problemId->setInputMask(QString());
        problemId->setText(QString());
        problemId->setPlaceholderText(QApplication::translate("MainWindow", "Problem ID", nullptr));
        hintButton->setText(QString());
        loadLabel->setText(QString());
        probNameLabel->setText(QString());
        label_7->setText(QString());
        label_6->setText(QApplication::translate("MainWindow", "Input table", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Input", nullptr));
        searchProb->setText(QApplication::translate("MainWindow", "Search problem", nullptr));
        checkIn->setText(QApplication::translate("MainWindow", "Check input", nullptr));
        checkAll->setText(QApplication::translate("MainWindow", "Check all", nullptr));
        checkRIG->setText(QApplication::translate("MainWindow", "Check RIG", nullptr));
        submitCode->setText(QApplication::translate("MainWindow", "Load program", nullptr));
        timeLimitIn->setPlaceholderText(QString());
        label->setText(QApplication::translate("MainWindow", "    Result", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "TextLel", nullptr));
        acOutLabel->setText(QApplication::translate("MainWindow", "Accepted output", nullptr));
        filter->setText(QApplication::translate("MainWindow", "Filter off", nullptr));
        yourOutLabel->setText(QApplication::translate("MainWindow", "Your output", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "Textbel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
