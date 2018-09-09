TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    tweet.cpp \
    profile.cpp

HEADERS += \
    tweet.h \
    profile.h

DISTFILES += \
    100-user-tweets.csv \
    25-user-tweets.csv \
    5-user-tweets.csv \
    500-user-tweets.csv

SUBDIRS += \
    Sprint1.pro
