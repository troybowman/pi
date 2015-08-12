#include "pi.h"

PiWin *win = NULL;

//-------------------------------------------------------------------------
void PiWin::timerEvent(QTimerEvent *)
{
  statusBar()->update();
}

//-------------------------------------------------------------------------
PiWin::PiWin(QWidget *parent) : inherited(parent)
{
  resize(QDesktopWidget().availableGeometry(this).size() * 0.9);

  statusBar()->addWidget(new QLabel("test"));

  timer.start(100, this);
}

//-------------------------------------------------------------------------
int main(int argc, char *argv[])
{
  PiApp a(argc, argv);
  win = new PiWin;

  win->show();
  a.exec();

  return 0;
}
