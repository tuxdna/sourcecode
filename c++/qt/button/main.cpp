#include "buttons.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QWidget>
#include <QPushButton>

void center(QWidget *widget, int w=-1, int h=-1) {
  int WIDTH = 290;
  int HEIGHT = 170;
  if(w==-1) {
    w=WIDTH;
  }
  if(h==-1) {
    h=HEIGHT;
  }
  QDesktopWidget *desktop = QApplication::desktop();
  int screenWidth = desktop->width();
  int screenHeight = desktop->height();
  int x = (screenWidth - w) / 2;
  int y = (screenHeight - h) / 2;
  widget->move(x,y);
}

// class MyButton: public QWidget {
// public:
//   MyButton(QWidget *parent = 0);
// };

// MyButton::MyButton(QWidget *parent): QWidget(parent)
// {
//   int WIDTH = 250;
//   int HEIGHT = 150;
//   setFixedSize(WIDTH, HEIGHT);
//   QPushButton *quit = new QPushButton("Quit", this);
//   quit->setGeometry(50, 40, 75, 30);
//   center(this, WIDTH, HEIGHT);
//   connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));
// }

int main ( int argc, char *argv[]) {
  QApplication app(argc, argv);
  Buttons window;
  window.setWindowTitle("Buttons");
  window.show();
  center(&window);
  return app.exec();
}


