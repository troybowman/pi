#include "pi.h"

PiWin *win = NULL;

//-------------------------------------------------------------------------
PiWin::PiWin(QWidget *parent) : inherited(parent) {}

//-------------------------------------------------------------------------
void PiWin::closeEvent(QCloseEvent *e)
{
  e->accept();
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
