TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CFLAGS += -std=c++11

SOURCES += main.cpp \
    lib/test_my_unordered_set.cpp

HEADERS += \
    lib/my_unordered_set.h \
    lib/test_my_unordered_set.h \
    lib/my_iterator.h
