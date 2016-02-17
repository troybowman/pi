#include "pi.h"

PiWin *win = NULL;

//-------------------------------------------------------------------------
PiWin::PiWin(QWidget *parent) : inherited(parent)
{
  te = new QTextEdit;
  te->setFont(QFont("Courier", 12));
  setCentralWidget(te);

  QMenu *file = new QMenu("File");
  menuBar()->addMenu(file);

  QAction *action = new QAction("Choose font", this);
  connect(action, SIGNAL(triggered()), this, SLOT(chooseFont()));
  file->addAction(action);
}

//-------------------------------------------------------------------------
PiFontDialog::PiFontDialog(const QFont &font)
{
  setOption(QFontDialog::DontUseNativeDialog);
  setOption(QFontDialog::MonospacedFonts);

  connect(this, SIGNAL(fontSelected(const QFont &)), this, SLOT(onFontSelected(const QFont &)));

  setCurrentFont(font);
}

//-------------------------------------------------------------------------
void PiFontDialog::onFontSelected(const QFont &font)
{
  selectedFont = font;
}

//-------------------------------------------------------------------------
void PiWin::chooseFont()
{
  PiFontDialog fd(te->font());
  if ( fd.exec() == QDialog::Accepted )
    te->setFont(fd.selectedFont);
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
