#include <QApplication>
#include <QDesktopWidget>
#include <QWidget>
#include <QIcon>
#include <iostream>
#include <QFrame>
#include <QGridLayout>


class Cursors: public QWidget
{
public:
  Cursors(QWidget *parent = 0);
};

void center(QWidget &widget, int w, int h) {
  QDesktopWidget *desktop = QApplication::desktop();
  int screenWidth = desktop->width();
  int screenHeight = desktop->height();
  int x = (screenWidth - w) / 2;
  int y = (screenHeight - h) / 2;
  widget.move(x,y);
}

Cursors::Cursors(QWidget *parent) : QWidget(parent)
{
  int WIDTH = 350;
  int HEIGHT = 150;
  resize (WIDTH, HEIGHT);
  QFrame *frame1 = new QFrame(this);
  frame1->setFrameStyle(QFrame::Box);
  frame1->setCursor(Qt::SizeAllCursor);

  QFrame *frame2 = new QFrame(this);
  frame2->setFrameStyle(QFrame::Box);
  frame2->setCursor(Qt::WaitCursor);

  QFrame *frame3 = new QFrame(this);
  frame3->setFrameStyle(QFrame::Box);
  frame3->setCursor(Qt::PointingHandCursor);

  QGridLayout *grid = new QGridLayout(this);
  grid->addWidget(frame1, 0, 0);
  grid->addWidget(frame2, 0, 1);
  grid->addWidget(frame3, 0, 2);

  setLayout(grid);

  center(*this, WIDTH, HEIGHT);
}

int main ( int argc, char *argv[]) {
  QApplication app(argc, argv);
  Cursors window;
  window.setWindowTitle("Cursors");
  window.show();

  return app.exec();
}

