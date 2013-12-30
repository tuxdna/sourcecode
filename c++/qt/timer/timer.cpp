#include "timer.h"

#include <QTime>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFont>
#include <QSlider>

Timer::Timer(QWidget *parent)
  : QWidget(parent)
{

  label = new QLabel("", this);
  label->move(50, 50);

  QTime qtime = QTime::currentTime();
  QString stime = qtime.toString(Qt::ISODate);
  label->setText(stime);

  startTimer(1000);

  QString lyrics = "Who doesn't long for someone to hold\n\
Who knows how to love you without being told\n\
Somebody tell me why I'm on my own\n\
If there's a soulmate for everyone\n\
\n\
Here we are again, circles never end\n\
How do I find the perfect fit\n\
There's enough for everyone\n\
But I'm still waiting in line\n\
\n\
Who doesn't long for someone to hold\n\
Who knows how to love you without being told\n\
Somebody tell me why I'm on my own\n\
If there's a soulmate for everyone";

  label2 = new QLabel(lyrics, this);
  label2->setFont(QFont("Purisa", 10));

  slider_label = new QLabel("0", this);
  slider = new QSlider(Qt::Horizontal, this);

  QHBoxLayout *slider_hbox = new QHBoxLayout();
  slider_hbox->addWidget(slider);
  slider_hbox->addWidget(slider_label);
  connect(slider, SIGNAL(valueChanged(int)), slider_label, SLOT(setNum(int)));

  spinbox = new QSpinBox(this);
  connect(spinbox, SIGNAL(valueChanged(int)), this, SLOT(setTitle(int)));
  
  QVBoxLayout *vbox = new QVBoxLayout();
  vbox->addWidget(label);
  vbox->addWidget(label2);
  vbox->addLayout(slider_hbox);
  vbox->addWidget(spinbox);

  setLayout(vbox);

}

void Timer::timerEvent(QTimerEvent *event)
{
  QTime qtime = QTime::currentTime();
  QString stime = qtime.toString(Qt::ISODate);
  label->setText(stime);
}
