#ifndef PI_H
#define PI_H

#ifdef __QT5__
#include <QtWidgets/QtWidgets>
#else
#include <QtGui>
#endif

#if defined(__GNUC__)
#define AS_PRINTF(format_idx, varg_idx) __attribute__((format(printf, format_idx, varg_idx)))
#else
#define AS_PRINTF(format_idx, varg_idx)
#endif

class PiWin;
extern PiWin *win;

//-------------------------------------------------------------------------
class PiDialog : public QDialog
{
  Q_OBJECT
  typedef QDialog inherited;

  int counter;
  QLabel *label;
  QTimer *timer;

public:
  PiDialog(QWidget *parent);

protected:
  void showEvent(QShowEvent *);

public slots:
  void updateLabel();
};

//-------------------------------------------------------------------------
class PiApp : public QApplication
{
  Q_OBJECT
  typedef QApplication inherited;

public:
  PiApp(int &argc, char **argv) : inherited(argc, argv) {}
  virtual ~PiApp(void) {}
};

//-------------------------------------------------------------------------
class PiTextEdit : public QTextEdit
{
  Q_OBJECT
  typedef QTextEdit inherited;

public:
  PiTextEdit(QWidget *parent = 0) : inherited(parent) {}
  virtual ~PiTextEdit() {}

  AS_PRINTF(2, 3) void msg(const char *format, ...);
};

//-------------------------------------------------------------------------
class PiWin : public QMainWindow
{
  Q_OBJECT
  typedef QMainWindow inherited;

  PiTextEdit *te;

  QBasicTimer timer1;
  QBasicTimer timer2;
  QBasicTimer msgTimer;

protected:
  virtual void timerEvent(QTimerEvent *e);

public:
  PiWin(QWidget *parent = 0);
  virtual ~PiWin() {}

public slots:
  void msgTriggered();
  void dlgTriggered();
};

#endif // PI_H
