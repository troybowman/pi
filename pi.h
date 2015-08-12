#include <QtWidgets/QtWidgets>

//-------------------------------------------------------------------------
class PiApp : public QApplication
{
  Q_OBJECT
  typedef QApplication inherited;

public:
  PiApp(int &argc, char **argv) : inherited(argc, argv) {}
};

//-------------------------------------------------------------------------
class PiWin : public QMainWindow
{
  Q_OBJECT
  typedef QMainWindow inherited;

  QBasicTimer timer;

protected:
  virtual void timerEvent(QTimerEvent *e);

public:
  PiWin(QWidget *parent = 0);
};
