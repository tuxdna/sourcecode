#ifndef LINES_H
#define LINES_H

#include <QWidget>

class Lines : public QWidget
{
  Q_OBJECT  

    public:
  Lines(QWidget *parent = 0);

 protected:
  void paintEvent(QPaintEvent *event);

};

#endif
