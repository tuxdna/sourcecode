#ifndef MOVE_H
#define MOVE_H

#include <QMainWindow>

class Move : public QWidget
{

 public:
  Move(QWidget *parent = 0);
 
 protected:
  void moveEvent(QMoveEvent *event);

};

#endif
