#include "pi.h"

PiWin *win = NULL;

//-------------------------------------------------------------------------
PiWin::PiWin(QWidget *parent) : inherited(parent)
{
  w = new QLabel;
  setCentralWidget(w);

  file = new QMenu("File");
  menuBar()->addMenu(file);

  save = new QAction("Save Pixmaps", this);
  connect(save, SIGNAL(triggered()), this, SLOT(savePixmaps()), Qt::DirectConnection);
  file->addAction(save);
}

//-------------------------------------------------------------------------
void PiWin::savePixmaps()
{
  QRect r(QPoint(30, 10), QPoint(35, 50));

  // gray out the whole window, except one special region
  QRect wr = w->rect();
  QPixmap wp = w->grab(wr);

  QPainter painter(&wp);
  painter.setClipRect(r);

  QRegion inverse = QRegion(wr).subtracted(painter.clipRegion());
  painter.setClipRegion(inverse);
  painter.fillRect(wr, QBrush(QColor(0, 0, 0, 0x80)));

  wp.save("/tmp/test1.png");

  // grab the special region and save it
  QPixmap test = w->grab(r);
  test.save("/tmp/test2.png");
}

//-------------------------------------------------------------------------
void PiWin::paintEvent(QPaintEvent *e)
{
  inherited::paintEvent(e);

  QPixmap pm(w->size());
  pm.fill(QColor(Qt::blue));

  QPainter p(&pm);
  QRect r(QPoint(20, 20), QPoint(40, 40));
  p.fillRect(r, QColor(Qt::white));

  w->setPixmap(pm);
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
