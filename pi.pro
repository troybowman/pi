DESTDIR=./
TARGET = pi
OBJECTS_DIR=./obj
MOC_DIR=./obj

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

mac {
  lessThan(QT_MAJOR_VERSION, 5) {
    HEADERS += macintegration.h
    OBJECTIVE_SOURCES += macintegration.mm
    QMAKE_LFLAGS += -framework Cocoa
  }
  else {
    DEFINES += __QT5__
    QMAKE_LFLAGS += -framework QtWidgets
  }
}

CONFIG -= release release_and_debug
CONFIG += debug
