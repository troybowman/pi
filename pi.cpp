#include "pi.h"

PiWin *win = NULL;

//-------------------------------------------------------------------------
PiWin::PiWin(QWidget *parent) : inherited(parent)
{
  viewport = new QLabel;
  setCentralWidget(viewport);

  file = new QMenu("File");
  menuBar()->addMenu(file);

  save = new QAction("Save Pixmaps", this);
  connect(save, SIGNAL(triggered()), this, SLOT(savePixmaps()), Qt::DirectConnection);
  file->addAction(save);
}

//-------------------------------------------------------------------------
void PiWin::savePixmaps()
{
  QRect r(QPoint(30, 10), QPoint(30, 50));

  // grey-out the view everywhere except r
  QPixmap ctx = rendered_screen.copy();
  QPainter p(&ctx);
  p.fillRect(ctx.rect(), QBrush(QColor(0, 0, 0, 0x80)));
  p.drawPixmap(r, rendered_screen, r);

  ctx.save("/tmp/test1.png");

  // get a pixmap for r and save it
  QPixmap pm = rendered_screen.copy(r);
  pm.save("/tmp/test2.png");
}

//-------------------------------------------------------------------------
void PiWin::paintEvent(QPaintEvent *e)
{
  inherited::paintEvent(e);

  QPixmap pm(viewport->size());
  pm.fill(QColor(Qt::blue));
  {
    // this is in a scope block to prevent a QPixmap::copy()
    // when assigning to rendered_screen
    QPainter p(&pm);
    QRect r(QPoint(20, 20), QPoint(40, 40));
    p.fillRect(r, QColor(Qt::white));
  }
  rendered_screen = pm;

  viewport->setPixmap(rendered_screen);
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
