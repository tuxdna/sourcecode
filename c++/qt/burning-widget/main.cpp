#include "burning.h"
#include <QDesktopWidget>
#include <QApplication>

void center(QWidget &widget)
{
  int x,y;
  int screenWidth;
  int screenHeight;
  int WIDTH = 370;
  int HEIGHT = 200;

  QDesktopWidget * desktop = QApplication::desktop();
  screenWidth = desktop->width();
  screenHeight = desktop->height();

  x = (screenWidth - WIDTH)/2;
  y = (screenHeight - HEIGHT)/2;
  widget.setGeometry(x,y,WIDTH, HEIGHT);
}

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  Burning window;
  window.setWindowTitle("The Burning widget");
  window.show();
  center(window);
  return app.exec();
}


  
