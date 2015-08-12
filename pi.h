#ifndef PI_H
#define PI_H

#ifdef __QT5__
#include <QtWidgets/QtWidgets>
#else
#include <QtGui>
#endif

#if defined(__GNUC__)
#define AS_PRINTF(format_idx, varg_idx) __attribute__((format(printf, format_idx, varg_idx)))
#else
#define AS_PRINTF(format_idx, varg_idx)
#endif

class PiWin;
extern PiWin *win;

//-------------------------------------------------------------------------
class PiApp : public QApplication
{
  Q_OBJECT
  typedef QApplication inherited;

public:
  PiApp(int &argc, char **argv) : inherited(argc, argv) {}
  virtual ~PiApp(void) {}
};

//-------------------------------------------------------------------------
class PiWin : public QMainWindow
{
  Q_OBJECT
  typedef QMainWindow inherited;

  QLabel *w;
  QAction *save;
  QMenu *file;

protected:
  virtual void paintEvent(QPaintEvent *e);

public:
  PiWin(QWidget *parent = 0);
  virtual ~PiWin() {}

public slots:
  void savePixmaps();
};

#endif // PI_H
