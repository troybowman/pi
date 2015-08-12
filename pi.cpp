#include "pi.h"

PiWin *win = NULL;

#define C_STR(s) s.toLocal8Bit().constData()

static QStringList history;

//-------------------------------------------------------------------------
void MyTextEdit::msg(const char *format, ...)
{
  va_list va;
  va_start(va, format);
  QString text;
  text.vsprintf(format, va);

  QByteArray bytes(C_STR(text));

  moveCursor(QTextCursor::End);
  insertPlainText(text);
  va_end(va);

  history.push_back(text);
}

//-------------------------------------------------------------------------
void PiWin::prepareHistory(QMenu *menu)
{
  menu->clear();
  int size = history.size();
  for ( int i = 0; i < size; i++ )
    menu->addAction(history[i]);
}

//-------------------------------------------------------------------------
void PiWin::prepareFileMenu()
{
  prepareHistory(fileMenu);
}

//-------------------------------------------------------------------------
PiWin::PiWin(QWidget *parent) : inherited(parent)
{
  te = new MyTextEdit;
  te->setAttribute(Qt::WA_InputMethodEnabled, false);
  te->setReadOnly(true);
  setCentralWidget(te);
  setObjectName("PiWin");

  fileMenu = new QMenu("File");
  connect(fileMenu, SIGNAL(aboutToShow()), this, SLOT(prepareFileMenu()), Qt::DirectConnection);
  menuBar()->addMenu(fileMenu);
}

//-------------------------------------------------------------------------
void PiWin::keyPressEvent(QKeyEvent *e)
{
  te->msg("key pressed: 0x%08x\n", e->key());
}

//-------------------------------------------------------------------------
int main(int argc, char *argv[])
{
  PiApp a(argc, argv);
  win = new PiWin;

#ifndef __QT5__
  // this is the only way I can get the app to start up in the foreground
  // when invoked from the command line on mac.
  // setModal(true); ?
  win->setVisible(true);
  win->raise();
#endif

  win->show();
  a.exec();
  return 0;
}
