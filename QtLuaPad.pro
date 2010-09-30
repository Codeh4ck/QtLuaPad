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
    luaeditor.cpp \
    options.cpp

HEADERS  += mainwindow.h \
    luaeditor.h \
    definitions.h \
    options.h

FORMS    += mainwindow.ui \
    options.ui

LIBS += -lqscintilla2

RESOURCES += \
    icons/res_icon.qrc

RC_FILE += icon.rc
