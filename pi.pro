DESTDIR=./
TARGET = pi
OBJECTS_DIR=./obj
MOC_DIR=./obj

mac {
  QT += macextras
  QMAKE_MAC_SDK = macosx10.12
}

CFLAGS+=-Wall                     \
        -fdiagnostics-show-option \
        -Wno-format               \
        -Wno-parentheses          \
        -Wno-sign-compare         \
        -Wno-uninitialized        \
        -Wno-unused-variable      \
        -Wno-unused-function      \
        -Wno-empty-body

QMAKE_CXXFLAGS_WARN_ON += $${CFLAGS}
QMAKE_CFLAGS_WARN_ON += $${CFLAGS}

HEADERS += pi.h
SOURCES += pi.cpp

equals(QT_MAJOR_VERSION, 5) {
  DEFINES += __QT5__
  QT += widgets
}

CONFIG -= release release_and_debug
CONFIG += debug
