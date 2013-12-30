#include "timer.h"
#include <QDesktopWidget>
#include <QApplication>

int WIDTH = 350;
int HEIGHT = 350;

void center(QWidget &widget)
{
  int x, y;
  int screenWidth;
  int screenHeight;

  QDesktopWidget *desktop = QApplication::desktop();

  screenWidth = desktop->width();
  screenHeight = desktop->height();

  x = (screenWidth - WIDTH) / 2;
  y = (screenHeight - HEIGHT) / 2;

  widget.setGeometry(x, y, WIDTH, HEIGHT);
  widget.setFixedSize(WIDTH, HEIGHT);
}


int main(int argc, char *argv[])
{
  QApplication app(argc, argv);

  Timer window;

  window.setWindowTitle("Timer");
  window.show();
  window.resize(WIDTH, HEIGHT);
  center(window);

  return app.exec();
}
