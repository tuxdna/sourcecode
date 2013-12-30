#ifndef BUTTONS_H
#define BUTTONS_H

#include <QWidget>
#include <QPushButton>

class Buttons: public QWidget
{
 public:
  Buttons(QWidget *parent = 0);
  
 private:
  QPushButton *ok;
  QPushButton *apply;

};

#endif
