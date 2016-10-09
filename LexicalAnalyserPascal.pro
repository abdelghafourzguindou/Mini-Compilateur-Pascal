TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    cutting.c \
    automate.c \
    keyword.c

HEADERS += \
    cutting.h \
    automate.h \
    keyword.h
