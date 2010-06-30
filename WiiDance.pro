# -------------------------------------------------
# Project created by QtCreator 2010-06-17T09:28:45
# -------------------------------------------------
QT += opengl
TARGET = WiiDance
TEMPLATE = app
SOURCES += main.cpp \
    dancewindow.cpp \
    wiiyourself/wiimote.cpp \
    connectionwizard.cpp
HEADERS += dancewindow.h \
    wiiyourself/wiimote_state.h \
    wiiyourself/wiimote_common.h \
    wiiyourself/wiimote.h \
    connectionwizard.h
FORMS += dancewindow.ui \
    connectionwizard.ui
LIBS += -lwinmm \
    -lhid \
    -lsetupapi
