#include "pi.h"

PiWin *win = NULL;

//-------------------------------------------------------------------------
PiWin::PiWin(QWidget *parent) : inherited(parent)
{
  resize(QDesktopWidget().availableGeometry(this).size() * 0.3);
  setObjectName("PiWin");

  QMenu *file = new QMenu("File");
  menuBar()->addMenu(file);

  message = new QAction(this);
  message->setShortcut(tr("M"));
  connect(message, SIGNAL(triggered()), this, SLOT(messageTriggered()));
  file->addAction(message);
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
int main(int argc, char *argv[])
{
  PiApp a(argc, argv);
  win = new PiWin;

  win->show();
  a.exec();

  return 0;
}
