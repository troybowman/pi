DESTDIR = ./
TARGET = pi
OBJECTS_DIR = ./obj
MOC_DIR = ./obj

HEADERS += pi.h
SOURCES += pi.cpp

QT += widgets

win32 {
  # so far we only have release builds of squish working on windows.
  # thus, the app must be a release build as well.
  # don't forget to run C:\Qt\5.5.1\bin\windeployqt pi.exe
  CONFIG += release
} else {
  CFLAGS += -Wall                     \
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

  CONFIG -= release release_and_debug
  CONFIG += debug
}
