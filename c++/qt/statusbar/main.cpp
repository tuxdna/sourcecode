#include "statusbar.h"
#include <QDesktopWidget>
#include <QApplication>

void center(QWidget &widget)
{
  int x, y;
  int screenWidth;
  int screenHeight;

  QDesktopWidget *desktop = QApplication::desktop();
  
  screenWidth = desktop->width();
  screenHeight = desktop->height();
  int WIDTH = widget.frameGeometry().width();
  int HEIGHT = widget.frameGeometry().height();


  x = (screenWidth - WIDTH) / 2;
  y = (screenHeight - HEIGHT) / 2;
  widget.move(x,y);
  // widget.setGeometry(x, y, WIDTH, HEIGHT);
  // widget.setFixedSize(WIDTH, HEIGHT);
}


int main(int argc, char *argv[])
{
  QApplication app(argc, argv);

  Statusbar window;

  window.setWindowTitle("Timer");
  window.show();
  // window.resize(WIDTH, HEIGHT);
  center(window);

  return app.exec();
}
