TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    tweets.cpp

HEADERS += \
    tweets.h \

DISTFILES += \
    100-user-tweets.csv \
    25-user-tweets.csv \
    5-user-tweets.csv \
    500-user-tweets.csv

SUBDIRS += \
    Sprint1.pro
