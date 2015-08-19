#include "pi.h"

PiWin *win = NULL;

//-------------------------------------------------------------------------
void MyTextEdit::msg(const char *format, ...)
{
  va_list va;
  va_start(va, format);
  QString text;
  text.vsprintf(format, va);
  moveCursor(QTextCursor::End);
  insertPlainText(text);
  va_end(va);
}

//-------------------------------------------------------------------------
PiWin::PiWin(QWidget *parent) : inherited(parent)
{
  te = new MyTextEdit;
  te->setAttribute(Qt::WA_InputMethodEnabled, false);
  te->setReadOnly(true);
  setCentralWidget(te);
  setObjectName("PiWin");

  QMenu *file = new QMenu("File");
  menuBar()->addMenu(file);

  fuckYou = new QAction("fuck you!", this);
  fuckYou->setShortcut(tr("Ctrl+F"));
  connect(fuckYou, SIGNAL(triggered()), this, SLOT(fuckYouToo()));

  file->addAction(fuckYou);
}

//-------------------------------------------------------------------------
void PiWin::keyPressEvent(QKeyEvent *e)
{
  te->msg("key pressed: 0x%08x\n", e->key());
  te->msg("  modifiers: 0x%08x\n", (int)e->modifiers());
}

//-------------------------------------------------------------------------
void PiWin::fuckYouToo()
{
  te->msg("fuck you too!\n");
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
