#include "lines.h"
#include "shapes.h"
#include "gradients.h"
#include "puff.h"
#include <QDesktopWidget>
#include <QApplication>

void center(QWidget &widget)
{
  int x, y;
  int screenWidth;
  int screenHeight;

  int WIDTH = 350*2;
  int HEIGHT = 350*2;


  QDesktopWidget *desktop = QApplication::desktop();

  screenWidth = desktop->width();
  screenHeight = desktop->height();

  x = (screenWidth - WIDTH) / 2;
  y = (screenHeight - HEIGHT) / 2;

  widget.setGeometry(x, y, WIDTH, HEIGHT);
}


int main(int argc, char *argv[])
{
  QApplication app(argc, argv);  

  Lines lines_window;
  lines_window.setWindowTitle("Lines");
  lines_window.show();
  center(lines_window);

  Shapes shapes_window;
  shapes_window.show();
  center(shapes_window);

  Gradient gradient_window;
  gradient_window.show();
  center(gradient_window);

  Puff puff_window;
  puff_window.show();
  center(puff_window);
  return app.exec();
}
