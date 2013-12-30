#include "keypress.h"

#include <QApplication>
#include <QKeyEvent>

KeyPress::KeyPress(QWidget *parent)
  : QWidget(parent)
{

}

void KeyPress::keyPressEvent(QKeyEvent *event)
{
  if (event->key() == Qt::Key_Escape) {  
    qApp->quit();
  } 
}

