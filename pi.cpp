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
  resize(QDesktopWidget().availableGeometry(this).size() * 0.3);

  te = new MyTextEdit;
  te->setAttribute(Qt::WA_InputMethodEnabled, false);
  te->setReadOnly(true);
  setCentralWidget(te);
  setObjectName("PiWin");

  QMenu *file = new QMenu("File");
  menuBar()->addMenu(file);

#define ADD_ACTION(action, shortcut)                                     \
do                                                                       \
{                                                                        \
  action = new QAction(this);                                            \
  action->setShortcut(tr(shortcut));                                     \
  connect(action, SIGNAL(triggered()), this, SLOT(action##Triggered())); \
  file->addAction(action);                                               \
} while ( false )

  ADD_ACTION(test1, "Alt+S"); // works
  ADD_ACTION(test2, "Alt+X"); // doesn't work
  ADD_ACTION(test3, "Alt+P"); // doesn't work
  ADD_ACTION(test4, "Alt+T"); // works
  ADD_ACTION(test5, "Alt+M"); // doesn't work

#undef ADD_ACTION
}

//-------------------------------------------------------------------------
void PiWin::keyPressEvent(QKeyEvent *e)
{
  te->msg("key: 0x%08x (modifiers = 0x%08x)\n", e->key(), (int)e->modifiers());
}

//-------------------------------------------------------------------------
void PiWin::test1Triggered() { te->msg(" * shortcut for test1 *\n"); }
void PiWin::test2Triggered() { te->msg(" * shortcut for test2 *\n"); }
void PiWin::test3Triggered() { te->msg(" * shortcut for test3 *\n"); }
void PiWin::test4Triggered() { te->msg(" * shortcut for test4 *\n"); }
void PiWin::test5Triggered() { te->msg(" * shortcut for test5 *\n"); }

//-------------------------------------------------------------------------
int main(int argc, char *argv[])
{
  PiApp a(argc, argv);
  win = new PiWin;

  win->show();
  a.exec();

  return 0;
}
