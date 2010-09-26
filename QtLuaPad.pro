#-------------------------------------------------
#
# Project created by QtCreator 2010-09-22T18:15:27
#
#-------------------------------------------------

QT       += core gui

TARGET = QtLuaPad
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    luaeditor.cpp

HEADERS  += mainwindow.h \
    luaeditor.h

FORMS    += mainwindow.ui

LIBS += -lqscintilla2

RESOURCES += \
    icons/res_icon.qrc
