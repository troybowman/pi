#ifndef MAC_INTEGRATION_H
#define MAC_INTEGRATION_H

#include <QWidget>

class MacIntegration : public QObject
{
  Q_OBJECT

public:
  MacIntegration();
  ~MacIntegration();
};

#endif // MAC_INTEGRATION_H
