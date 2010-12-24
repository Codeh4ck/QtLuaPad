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
    options.cpp \
    finddialog.cpp \
    questcreator.cpp \
    about.cpp

HEADERS  += mainwindow.h \
    luaeditor.h \
    definitions.h \
    options.h \
    finddialog.h \
    questcreator.h \
    about.h

FORMS    += mainwindow.ui \
    options.ui \
    finddialog.ui \
    questcreator.ui \
    about.ui

LIBS += -lqscintilla2 -lxml2

RESOURCES += \
    icons/res_icon.qrc

RC_FILE += icon.rc
