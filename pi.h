#ifndef PI_H
#define PI_H

#include <QtWidgets/QtWidgets>

class PiWin;
extern PiWin *win;

//-------------------------------------------------------------------------
class PiApp : public QApplication
{
  Q_OBJECT
  typedef QApplication inherited;

public:
  PiApp(int &argc, char **argv) : inherited(argc, argv) {}
};

//-------------------------------------------------------------------------
class PiWin : public QMainWindow
{
  Q_OBJECT
  typedef QMainWindow inherited;

  QTextEdit *te;

public:
  PiWin(QWidget *parent = NULL);

public slots:
  void chooseFont();
};

//-------------------------------------------------------------------------
class PiFontDialog : public QFontDialog
{
  Q_OBJECT
  typedef QFontDialog inherited;

public:
  QFont selectedFont;
  PiFontDialog(const QFont &font);

public slots:
  void onFontSelected(const QFont &font);
};

#endif // PI_H
