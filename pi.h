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

  AS_PRINTF(2, 3) void msg(const char *format, ...);
};

//-------------------------------------------------------------------------
class PiWin : public QMainWindow
{
  Q_OBJECT
  typedef QMainWindow inherited;

  MyTextEdit *te;

protected:
  virtual void keyPressEvent(QKeyEvent *e);

public:
  PiWin(QWidget *parent = 0);
  virtual ~PiWin() {}

public slots:
#define DECLARE_SLOT(act) void act##Triggered()

  DECLARE_SLOT(test1);
  DECLARE_SLOT(test2);
  DECLARE_SLOT(test3);
  DECLARE_SLOT(test4);
  DECLARE_SLOT(test5);
  DECLARE_SLOT(test6);
  DECLARE_SLOT(test7);
  DECLARE_SLOT(test8);
  DECLARE_SLOT(test9);
  DECLARE_SLOT(test10);
  DECLARE_SLOT(test11);
  DECLARE_SLOT(test12);
  DECLARE_SLOT(test13);
  DECLARE_SLOT(test14);
  DECLARE_SLOT(test15);
  DECLARE_SLOT(test16);
  DECLARE_SLOT(test17);
  DECLARE_SLOT(test18);
  DECLARE_SLOT(test19);
  DECLARE_SLOT(test20);
  DECLARE_SLOT(test21);
  DECLARE_SLOT(test22);
  DECLARE_SLOT(test23);
  DECLARE_SLOT(test24);
  DECLARE_SLOT(test25);
  DECLARE_SLOT(test26);
  DECLARE_SLOT(test27);
  DECLARE_SLOT(test28);
  DECLARE_SLOT(test29);
  DECLARE_SLOT(test30);
  DECLARE_SLOT(test31);
  DECLARE_SLOT(test32);
  DECLARE_SLOT(test33);
  DECLARE_SLOT(test34);
  DECLARE_SLOT(test35);
  DECLARE_SLOT(test36);
  DECLARE_SLOT(test37);
  DECLARE_SLOT(test38);
  DECLARE_SLOT(test39);
  DECLARE_SLOT(test40);
  DECLARE_SLOT(test41);
  DECLARE_SLOT(test42);
  DECLARE_SLOT(test43);
  DECLARE_SLOT(test44);
  DECLARE_SLOT(test45);
  DECLARE_SLOT(test46);
  DECLARE_SLOT(test47);
  DECLARE_SLOT(test48);
  DECLARE_SLOT(test49);
  DECLARE_SLOT(test50);
  DECLARE_SLOT(test51);
  DECLARE_SLOT(test52);
  DECLARE_SLOT(test53);
  DECLARE_SLOT(test54);
  DECLARE_SLOT(test55);
  DECLARE_SLOT(test56);
  DECLARE_SLOT(test57);
  DECLARE_SLOT(test58);

#undef DECLARE_SLOT
};

#endif // PI_H
