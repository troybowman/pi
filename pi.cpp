#include "pi.h"

PiWin *win = NULL;
static FILE *fp = NULL;

//-------------------------------------------------------------------------
void MyTextEdit::msg(const char *format, ...)
{
  va_list va;
  va_start(va, format);
  QString text;
  text.vsprintf(format, va);
  moveCursor(QTextCursor::End);
  insertPlainText(text);
  fprintf(fp, "%s", text.toLocal8Bit().constData());
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

#define SC1 "X"
#define SC2 "Alt+X"
#define SC3 ";"
#define SC4 ":"
#define SC5 "F1"
#define SC6 "F5"
#define SC7 "Shift+R"

#define ADD_ACTION(action, shortcut)                                     \
do                                                                       \
{                                                                        \
  action = new QAction(this);                                            \
  action->setShortcut(tr(shortcut));                                     \
  connect(action, SIGNAL(triggered()), this, SLOT(action##Triggered())); \
  file->addAction(action);                                               \
} while ( false )

  ADD_ACTION(action1, SC1);
  ADD_ACTION(action2, SC2);
  ADD_ACTION(action3, SC3);
  ADD_ACTION(action4, SC4);
  ADD_ACTION(action5, SC5);
  ADD_ACTION(action6, SC6);
  ADD_ACTION(action7, SC7);

#undef ADD_ACTION
}

//-------------------------------------------------------------------------
void PiWin::keyPressEvent(QKeyEvent *e)
{
  te->msg("key: 0x%08x (modifiers = 0x%08x)\n", e->key(), (int)e->modifiers());
}

//-------------------------------------------------------------------------
void PiWin::actionMessage(const char *shortcut) const
{
  te->msg("ACTION: \"%s\"\n", shortcut);
}

//-------------------------------------------------------------------------
void PiWin::action1Triggered() { actionMessage(SC1); }
void PiWin::action2Triggered() { actionMessage(SC2); }
void PiWin::action3Triggered() { actionMessage(SC3); }
void PiWin::action4Triggered() { actionMessage(SC4); }
void PiWin::action5Triggered() { actionMessage(SC5); }
void PiWin::action6Triggered() { actionMessage(SC6); }
void PiWin::action7Triggered() { actionMessage(SC7); }

//-------------------------------------------------------------------------
int main(int argc, char *argv[])
{
  fp = fopen("/tmp/pi.log", "w");

  PiApp a(argc, argv);
  win = new PiWin;

  win->show();
  a.exec();

  fclose(fp);

  return 0;
}
