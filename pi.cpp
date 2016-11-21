#include "pi.h"

PiWin *win = NULL;

//-------------------------------------------------------------------------
PiWin::PiWin(QWidget *parent) : inherited(parent)
{
  resize(QDesktopWidget().availableGeometry(this).size() * 0.3);

  QMenu *menu = new QMenu("File");
  menuBar()->addMenu(menu);

  QAction *action = new QAction(this);
  action->setShortcut(tr("F"));
  connect(action, SIGNAL(triggered()), this, SLOT(actionTriggered()));
  menu->addAction(action);
}

//-------------------------------------------------------------------------
void PiWin::actionTriggered()
{
  QFileDialog::getOpenFileName(this, "title");
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
