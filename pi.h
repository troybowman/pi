#ifndef PI_H
#define PI_H

#include <QtWidgets/QtWidgets>

class PiWin;
extern PiWin *win;

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
class MyTextEdit : public QTextEdit
{
  Q_OBJECT
  typedef QTextEdit inherited;

public:
  MyTextEdit(QWidget *parent = 0) : inherited(parent) {}
  virtual ~MyTextEdit() {}

  void msg(const char *format, ...);
};

//-------------------------------------------------------------------------
class PiWin : public QMainWindow
{
  Q_OBJECT
  typedef QMainWindow inherited;

  MyTextEdit *te;

  QAction *action1;
  QAction *action2;
  QAction *action3;
  QAction *action4;
  QAction *action5;
  QAction *action6;
  QAction *action7;

  void actionMessage(const char *shortcut) const;

protected:
  virtual void keyPressEvent(QKeyEvent *e);

public:
  PiWin(QWidget *parent = 0);
  virtual ~PiWin() {}

public slots:
  void action1Triggered();
  void action2Triggered();
  void action3Triggered();
  void action4Triggered();
  void action5Triggered();
  void action6Triggered();
  void action7Triggered();
};

#endif // PI_H
