#include "burning.h"
#include <QApplication>
#include <QPainter>
#include <QVBoxLayout>
#include <QFrame>
#include <QPushButton>

Burning::Burning(QWidget *parent)
  : QFrame(parent)
{
  slider = new QSlider(Qt::Horizontal, this);
  slider->setMaximum(750);
  slider->setGeometry(50, 50, 130, 30);

  connect(slider, SIGNAL(valueChanged(int)), this, SLOT(valueChanged(int)));

  QVBoxLayout *vbox = new QVBoxLayout(this);
  QHBoxLayout *hbox = new QHBoxLayout();

  vbox->addStretch(1);

  widget = new Widget(this);
  hbox->addWidget(widget, 0);
  vbox->addLayout(hbox);
  setLayout(vbox);
}

void Burning::valueChanged(int val)
{
  cur_width = val;
  widget->repaint();
}

int Burning::getCurrentWidth()
{
  return cur_width;
}
