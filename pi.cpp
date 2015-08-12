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
void PiWin::showColorDialog()
{
  colorDlgTimer.start(1000, this);
  te->msg("waiting...\n");
}

//-------------------------------------------------------------------------
void PiWin::timerEvent(QTimerEvent *e)
{
  if ( e->timerId() == colorDlgTimer.timerId() )
  {
    colorDlgTimer.stop();
    QColorDialog::getColor();
  }
  else if ( e->timerId() == timer1.timerId() )
  {
    te->msg("timer1\n");
  }
  else if ( e->timerId() == timer2.timerId() )
  {
    te->msg("timer2\n");
  }
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
  //connect(fileMenu, SIGNAL(aboutToShow()), this, SLOT(prepareFileMenu()), Qt::DirectConnection);
  menuBar()->addMenu(fileMenu);

  colors = new QAction(this);
  colors->setText("show color dialog\n");
  connect(colors, SIGNAL(triggered()), this, SLOT(showColorDialog()), Qt::DirectConnection);
  fileMenu->addAction(colors);

  timer1.start(1100, this);
  timer2.start(1700, this);
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

  win->show();
  a.exec();

  return 0;
}
