#-------------------------------------------------
#
# Project created by QtCreator 2010-09-22T18:15:27
#
#-------------------------------------------------

QT       += core gui network

TARGET = QtLuaPad
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    luaeditor.cpp \
    options.cpp \
    finddialog.cpp \
    about.cpp \
    questcreator.cpp

HEADERS  += mainwindow.h \
    luaeditor.h \
    definitions.h \
    options.h \
    finddialog.h \
    about.h \
    questcreator.h

FORMS    += mainwindow.ui \
    options.ui \
    finddialog.ui \
    about.ui \
    questcreator.ui

LIBS += qscintilla2.lib xml2.lib

RESOURCES += \
    icons/res_icon.qrc

RC_FILE += icon.rc
