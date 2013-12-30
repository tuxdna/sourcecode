#ifndef ANOTHERMENU_H
#define ANOTHERMENU_H

#include <QMainWindow>

class AnotherMenu: public QMainWindow
{
  Q_OBJECT;
 public:
  AnotherMenu(QWidget *parent = 0);

  private slots:
  void toggleStatusbar();

 private:
  QAction *viewst;

};



#endif
