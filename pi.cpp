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

#define ADD_ACTION(act_name, shortcut)                                       \
do                                                                           \
{                                                                            \
  QAction *act_name = new QAction(this);                                     \
  act_name->setShortcut(tr(shortcut));                                       \
  connect(act_name, SIGNAL(triggered()), this, SLOT(act_name##Triggered())); \
  file->addAction(act_name);                                                 \
} while ( false )

  ADD_ACTION(test1,  "Alt+A");
  ADD_ACTION(test2,  "Alt+B");
  ADD_ACTION(test3,  "Alt+C");
  ADD_ACTION(test4,  "Alt+D");
  ADD_ACTION(test5,  "Alt+E");
  ADD_ACTION(test6,  "Alt+F");
  ADD_ACTION(test7,  "Alt+G");
  ADD_ACTION(test8,  "Alt+H");
  ADD_ACTION(test9,  "Alt+I");
  ADD_ACTION(test10, "Alt+J");
  ADD_ACTION(test11, "Alt+K");
  ADD_ACTION(test12, "Alt+L");
  ADD_ACTION(test13, "Alt+M");
  ADD_ACTION(test14, "Alt+N");
  ADD_ACTION(test15, "Alt+O");
  ADD_ACTION(test16, "Alt+P");
  ADD_ACTION(test17, "Alt+Q");
  ADD_ACTION(test18, "Alt+R");
  ADD_ACTION(test19, "Alt+S");
  ADD_ACTION(test20, "Alt+T");
  ADD_ACTION(test21, "Alt+U");
  ADD_ACTION(test22, "Alt+V");
  ADD_ACTION(test23, "Alt+W");
  ADD_ACTION(test24, "Alt+X");
  ADD_ACTION(test25, "Alt+Y");
  ADD_ACTION(test26, "Alt+Z");
  ADD_ACTION(test27, "Alt+F1");
  ADD_ACTION(test28, "Alt+F2");
  ADD_ACTION(test29, "Alt+F3");
  ADD_ACTION(test30, "Alt+F4");
  ADD_ACTION(test31, "Alt+F5");
  ADD_ACTION(test32, "Alt+F6");
  ADD_ACTION(test33, "Alt+F7");
  ADD_ACTION(test34, "Alt+F8");
  ADD_ACTION(test35, "Alt+F9");
  ADD_ACTION(test36, "Alt+F10");
  ADD_ACTION(test37, "Alt+F11");
  ADD_ACTION(test38, "Alt+F12");
  ADD_ACTION(test39, "Alt+1");
  ADD_ACTION(test40, "Alt+2");
  ADD_ACTION(test41, "Alt+3");
  ADD_ACTION(test42, "Alt+4");
  ADD_ACTION(test43, "Alt+5");
  ADD_ACTION(test38, "Alt+6");
  ADD_ACTION(test44, "Alt+7");
  ADD_ACTION(test45, "Alt+8");
  ADD_ACTION(test46, "Alt+9");
  ADD_ACTION(test47, "Alt+0");
  ADD_ACTION(test48, "Alt++");
  ADD_ACTION(test49, "Alt+-");

#undef ADD_ACTION
}

//-------------------------------------------------------------------------
void PiWin::keyPressEvent(QKeyEvent *e)
{
  te->msg("key: 0x%08x (modifiers = 0x%08x)\n", e->key(), (int)e->modifiers());
}

//-------------------------------------------------------------------------
#define DEFINE_SLOT(act_name)                 \
void PiWin::act_name##Triggered()             \
{                                             \
  te->msg(" * shortcut for "#act_name" *\n"); \
}

DEFINE_SLOT(test1)
DEFINE_SLOT(test2)
DEFINE_SLOT(test3)
DEFINE_SLOT(test4)
DEFINE_SLOT(test5)
DEFINE_SLOT(test6)
DEFINE_SLOT(test7)
DEFINE_SLOT(test8)
DEFINE_SLOT(test9)
DEFINE_SLOT(test10)
DEFINE_SLOT(test11)
DEFINE_SLOT(test12)
DEFINE_SLOT(test13)
DEFINE_SLOT(test14)
DEFINE_SLOT(test15)
DEFINE_SLOT(test16)
DEFINE_SLOT(test17)
DEFINE_SLOT(test18)
DEFINE_SLOT(test19)
DEFINE_SLOT(test20)
DEFINE_SLOT(test21)
DEFINE_SLOT(test22)
DEFINE_SLOT(test23)
DEFINE_SLOT(test24)
DEFINE_SLOT(test25)
DEFINE_SLOT(test26)
DEFINE_SLOT(test27)
DEFINE_SLOT(test28)
DEFINE_SLOT(test29)
DEFINE_SLOT(test30)
DEFINE_SLOT(test31)
DEFINE_SLOT(test32)
DEFINE_SLOT(test33)
DEFINE_SLOT(test34)
DEFINE_SLOT(test35)
DEFINE_SLOT(test36)
DEFINE_SLOT(test37)
DEFINE_SLOT(test38)
DEFINE_SLOT(test39)
DEFINE_SLOT(test40)
DEFINE_SLOT(test41)
DEFINE_SLOT(test42)
DEFINE_SLOT(test43)
DEFINE_SLOT(test44)
DEFINE_SLOT(test45)
DEFINE_SLOT(test46)
DEFINE_SLOT(test47)
DEFINE_SLOT(test48)
DEFINE_SLOT(test49)

#undef DEFINE_SLOT

//-------------------------------------------------------------------------
int main(int argc, char *argv[])
{
  PiApp a(argc, argv);
  win = new PiWin;

  win->show();
  a.exec();

  return 0;
}
