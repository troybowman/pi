#include "pi.h"

PiWin *win = NULL;
PiDialog *dialog = NULL;

//-------------------------------------------------------------------------
PiWin::PiWin(QWidget *parent) : inherited(parent)
{
  te = new PiTextEdit;
  te->setAttribute(Qt::WA_InputMethodEnabled, false);
  te->setReadOnly(true);
  setCentralWidget(te);

  QMenu *fileMenu = new QMenu("File");
  menuBar()->addMenu(fileMenu);

#define ADD_ACT(act_name, shortcut, desc)                                    \
do                                                                           \
{                                                                            \
  QAction *act_name = new QAction(desc, this);                               \
  act_name->setShortcut(tr(shortcut));                                       \
  connect(act_name, SIGNAL(triggered()), this, SLOT(act_name##Triggered())); \
  fileMenu->addAction(act_name);                                             \
} while ( false )

  ADD_ACT(msg, "1", "Show a delayed message");
  ADD_ACT(dlg, "2", "Show an updating dialog");

#undef ADD_ACT

  timer1.start(1100, this);
  timer2.start(1700, this);
}

//-------------------------------------------------------------------------
void PiWin::timerEvent(QTimerEvent *e)
{
  if ( e->timerId() == msgTimer.timerId() )
  {
    msgTimer.stop();
    QMessageBox msgBox;
    msgBox.setText("message");
    msgBox.exec();
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
PiDialog::PiDialog(QWidget *parent) : inherited(parent), counter(0)
{
  QVBoxLayout *mainLayout = new QVBoxLayout;
  label = new QLabel;
  mainLayout->addWidget(label);
  setLayout(mainLayout);
  timer = new QTimer(this);
  timer->setInterval(10);
  connect(timer, SIGNAL(timeout()), this, SLOT(updateLabel()));
}

//-------------------------------------------------------------------------
void PiDialog::updateLabel()
{
  QString text = QString("counter: %1").arg(counter++);
  label->setText(text);
  resize(QSize(fontMetrics().width(text) + 40, 40));
}

//-------------------------------------------------------------------------
void PiDialog::showEvent(QShowEvent *)
{
  timer->start();
}

//-------------------------------------------------------------------------
void PiWin::msgTriggered()
{
  msgTimer.start(1000, this);
  te->msg("waiting...\n");
}

//-------------------------------------------------------------------------
void PiWin::dlgTriggered()
{
  dialog = new PiDialog(this);
  dialog->show();
}

//-------------------------------------------------------------------------
void PiTextEdit::msg(const char *format, ...)
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
int main(int argc, char *argv[])
{
  PiApp a(argc, argv);
  win = new PiWin;

  win->show();
  a.exec();

  return 0;
}
