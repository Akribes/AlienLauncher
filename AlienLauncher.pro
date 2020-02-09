QT       += core gui network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = app
CONFIG += c++11
DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    accountmanager.cpp \
    instance.cpp \
    instancemanager.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    accountmanager.h \
    globals.h \
    instance.h \
    instancemanager.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

DISTFILES += \
    alienlauncher.desktop
    alienlauncher.svg

unix {
    target.path = /usr/bin

    desktopfile.path = /usr/share/applications
    desktopfile.files = alienlauncher.desktop

    icon.path = /usr/share/icons
    icon.files = alienlauncher.svg

    INSTALLS += target desktopfile icon
}
