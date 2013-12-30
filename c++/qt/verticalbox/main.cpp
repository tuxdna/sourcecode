#include "verticalbox.h"
#include <QDesktopWidget>
#include <QApplication>

void center(QWidget *widget) {
  int w=200;
  int h=250;
  QDesktopWidget *desktop = QApplication::desktop();
  int screenWidth = desktop->width();
  int screenHeight = desktop->height();
  int x = (screenWidth - w) / 2;
  int y = (screenHeight - h) / 2;
  widget->move(x,y);
}

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);

  VerticalBox window;

  window.setWindowTitle("VerticalBox");
  window.show();
  center(&window);
  return app.exec();

}
