#ifndef TIMER_H
#define TIMER_H

#include <QWidget>
#include <QLabel>
#include <QSlider>
#include <QSpinBox>

class Timer : public QWidget
{
  Q_OBJECT
    ;

 public:
  Timer(QWidget *parent = 0);

 protected:
  void timerEvent(QTimerEvent *event);

 private:
  QLabel *label;
  QLabel *label2;

  // for slider
  QLabel *slider_label;
  QSlider *slider;

  // for spinbox
  QLabel *spinbox_label;
  QSpinBox *spinbox;
};

#endif
