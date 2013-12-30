#ifndef BURNING_H
#define BURNING_H

#include <QWidget>
#include <QSlider>

#include "widget.h"

class Burning : public QFrame
{
  Q_OBJECT;

 public:
  Burning(QWidget *parent = 0);

  public slots:
  void valueChanged(int);
  int getCurrentWidth();

 private:
  QSlider *slider;
  Widget *widget;
  int cur_width;

};

#endif

