#include <QApplication>
#include <QDesktopWidget>
#include <QWidget>
#include <QIcon>
#include <iostream>

void center(QWidget &widget, int w, int h) {
  QDesktopWidget *desktop = QApplication::desktop();
  int screenWidth = desktop->width();
  int screenHeight = desktop->height();
  int x = (screenWidth - w) / 2;
  int y = (screenHeight - h) / 2;
  widget.move(x,y);
}

int main ( int argc, char *argv[]) {
  int WIDTH = 250;
  int HEIGHT = 150;

  // int screenWidth;
  // int screenHeight;
  // int x,y;

  QApplication app(argc, argv);
  QWidget window;
  // int numScreens = QApplication::desktop()->numScreens();
  // int primaryScreen = QApplication::desktop()->primaryScreen();

  // int holdingScreen = QApplication::desktop()->screenNumber(&window);
  // std::cout << "Number of screens: " << numScreens << std::endl;
  // std::cout << "Primary screen: " << primaryScreen << std::endl;
  // std::cout << "Holding screen: " << holdingScreen << std::endl;

  // QDesktopWidget *desktop = QApplication::desktop();
  // screenWidth = desktop->width();
  // screenHeight = desktop->height();
  // x = (screenWidth - WIDTH) / 2;
  // y = (screenHeight - HEIGHT) / 2;
  // std::cout << screenHeight << std::endl;
  // std::cout << screenWidth << std::endl;
  // std::cout << HEIGHT << std::endl;
  // std::cout << WIDTH << std::endl;
  // std::cout << x << std::endl;
  // std::cout << y << std::endl;
  window.resize(WIDTH, HEIGHT);
  center(window, WIDTH, HEIGHT);
  window.setWindowTitle("Simple example: Center: ToolTip: Icon");
  window.setToolTip("QWidget");
  window.setWindowIcon(QIcon("/data/dev/Armstrong-IDE/src/main-logo.gif"));
  window.show();

  return app.exec();
}

