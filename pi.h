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
class PiWin : public QMainWindow
{
  Q_OBJECT
  typedef QMainWindow inherited;

  QAction *message;

public:
  PiWin(QWidget *parent = 0);
  virtual ~PiWin() {}

public slots:
  void messageTriggered();
};

#endif // PI_H
