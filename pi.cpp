#include "pi.h"

PiWin *win = NULL;

//-------------------------------------------------------------------------
PiWin::PiWin(QWidget *parent) : inherited(parent)
{
  QMenu *file = new QMenu("File");
  menuBar()->addMenu(file);

  QAction *action = new QAction("Show a QFontDialog", this);
  action->setShortcut(tr("F"));
  connect(action, SIGNAL(triggered()), this, SLOT(showFontDialog()));
  file->addAction(action);
}

//-------------------------------------------------------------------------
void PiWin::showFontDialog()
{
  QFontDialog fd;
  fd.exec();
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
