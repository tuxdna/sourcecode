#include "click.h"
#include <QPushButton>
#include <QApplication>


Click::Click(QWidget *parent)
  : QWidget(parent)
{
  QPushButton *quit = new QPushButton("Quit", this);
  quit->setGeometry(50, 40, 75, 30);

  connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));
}
