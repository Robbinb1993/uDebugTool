#-------------------------------------------------
#
# Project created by QtCreator 2018-05-22T22:04:08
#
#-------------------------------------------------

QT       += core gui network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = uDebugTool
TEMPLATE = app

RC_ICONS += icon.ico

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    networkmanager.cpp \
    outputhandler.cpp \
    codeeditor.cpp \
    highlighter.cpp \
    editor.cpp \
    inputchainchecker.cpp \
    lineedit.cpp \
    rigchecker.cpp \
    hintswindow.cpp \
    infotable.cpp \
    sourcecode.cpp

HEADERS += \
        mainwindow.h \
    networkmanager.h \
    outputhandler.h \
    codeeditor.h \
    highlighter.h \
    editor.h \
    inputchainchecker.h \
    lineedit.h \
    rigchecker.h \
    hintswindow.h \
    hintswindow.h \
    infotable.h \
    sourcecode.h

FORMS += \
        mainwindow.ui \
    codeeditor.ui \
    inputchainchecker.ui \
    rigchecker.ui \
    hintswindow.ui


