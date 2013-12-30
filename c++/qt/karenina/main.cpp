#include "karenina.h"

#include <QDesktopWidget>
#include <QApplication>

void center(QWidget *widget) {
  QDesktopWidget *desktop = QApplication::desktop();
  int screenWidth = desktop->width();
  int screenHeight = desktop->height();
  int w = widget->frameGeometry().width();
  int h = widget->frameGeometry().height();
  int x = (screenWidth - w) / 2;
  int y = (screenHeight - h) / 2;
  widget->move(x,y);
}

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);

  Karenina window;
  window.setWindowTitle("Anna Karenina");
  window.show();
  center(&window);
  return app.exec();
}
