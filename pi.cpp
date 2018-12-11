#include "pi.h"

PiWin *win = NULL;

//-------------------------------------------------------------------------
PiWin::PiWin(QWidget *parent) : inherited(parent)
{
  resize(QDesktopWidget().availableGeometry(this).size() * 0.3);

  te = new QTextEdit;
  setCentralWidget(te);

  QMenu *file = new QMenu("File");
  menuBar()->addMenu(file);

  QAction *dlgact = new QAction("Open File Dialog", this);
  dlgact->setShortcut(tr("F"));
  connect(dlgact, SIGNAL(triggered()), this, SLOT(actionTriggered()));
  file->addAction(dlgact);

  QMenu *edit = new QMenu("Edit");
  menuBar()->addMenu(edit);

  QAction *copy = new QAction("Copy", this);
  copy->setShortcut(QKeySequence::Copy);
  edit->addAction(copy);

  QAction *paste = new QAction("Paste", this);
  paste->setShortcut(QKeySequence::Paste);
  edit->addAction(paste);
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
