#import <Cocoa/Cocoa.h>
#import <objc/runtime.h>

#include "pi.h"
#include "macintegration.h"

static QMenu *dockMenu;

NSMenu *prepareDockMenu(id self, SEL _cmd)
{
  Q_UNUSED(self);
  Q_UNUSED(_cmd);

  win->prepareHistory(dockMenu);
  return dockMenu->macMenu();
}

MacIntegration::MacIntegration() : QObject(NULL)
{
  dockMenu = new QMenu;

  Class cls = [[[NSApplication sharedApplication] delegate] class];

  if (!class_addMethod(cls, @selector(applicationDockMenu:), (IMP) prepareDockMenu, "v@:"))
      NSLog(@"MacIntegration::MacIntegration() : class_addMethod(prepareDockMenu) failed!");
}

MacIntegration::~MacIntegration()
{
  delete dockMenu;
}
