#include <communicate.h>

#include <QDesktopWidget>

void center(QWidget *widget, int w, int h) {
  QDesktopWidget *desktop = QApplication::desktop();
  int screenWidth = desktop->width();
  int screenHeight = desktop->height();
  int x = (screenWidth - w) / 2;
  int y = (screenHeight - h) / 2;
  widget->move(x,y);
}

Communicate::Communicate(QWidget *parent)
  : QWidget(parent)
{
  int WIDTH = 350;
  int HEIGHT = 190;
  resize(WIDTH, HEIGHT);

  QPushButton *plus = new QPushButton("+", this);
  plus->setGeometry(50,40,75,30);

  QPushButton *minus = new QPushButton("-", this);
  minus->setGeometry(50,80,75,30);

  label = new QLabel("0", this);
  label->setGeometry(190,80,20,30);

  connect(plus, SIGNAL(clicked()), this, SLOT(OnPlus()));
  connect(minus, SIGNAL(clicked()), this, SLOT(OnMinus()));

  center(this, WIDTH, HEIGHT);

}

void Communicate::OnPlus()
{
  int val = label->text().toInt();
  val++;
  label->setText(QString::number(val));
}

void Communicate::OnMinus()
{
  int val = label->text().toInt();
  val--;
  label->setText(QString::number(val));
}

