#include "pi.h"

PiWin *win = NULL;

//-------------------------------------------------------------------------
PiWin::PiWin(QWidget *parent) : inherited(parent)
{
  resize(QDesktopWidget().availableGeometry(this).size() * 0.3);
  setObjectName("PiWin");

  QMenu *file = new QMenu("File");
  menuBar()->addMenu(file);

#define ADD_ACT(act_name, shortcut, desc)                                    \
do                                                                           \
{                                                                            \
  QAction *act_name = new QAction(desc, this);                               \
  act_name->setShortcut(tr(shortcut));                                       \
  connect(act_name, SIGNAL(triggered()), this, SLOT(act_name##Triggered())); \
  file->addAction(act_name);                                                 \
} while ( false )

  ADD_ACT(message, "M", "Show a message");
  ADD_ACT(newinst, "N", "Launch a new instance");
}

//-------------------------------------------------------------------------
void PiWin::messageTriggered()
{
  QMessageBox msgBox;
  msgBox.setObjectName("message");
  msgBox.setText("message");
  msgBox.exec();
}

//-------------------------------------------------------------------------
void PiWin::newinstTriggered()
{
  QProcess::startDetached(qApp->applicationFilePath());
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
