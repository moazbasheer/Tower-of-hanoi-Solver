QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

INCLUDEPATH += $$PWD
FORMS += \
    MainWindow.ui

SOURCES += \
    main.cpp \
    MainWindow.cpp

HEADERS += \
    MainWindow.h
