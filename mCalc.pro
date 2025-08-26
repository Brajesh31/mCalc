QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++14

SOURCES += main.cpp \
    calctheme.cpp \
    calcui.cpp \
    exprsolver.cpp \
    value.cpp

HEADERS += \
    calctheme.h \
    calcui.h \
    exprsolver.h \
    value.h

RESOURCES += \
    mCalc.qrc
