#ifndef STATUSBAR_H
#define STATUSBAR_H

#include <QMainWindow>
#include <QPushButton>
#include <QListWidget>
class Statusbar : public QMainWindow
{
  Q_OBJECT  
    ;
 public:
  Statusbar(QWidget *parent = 0);

  private slots:
  // for buttons
  void OnOkPressed();
  void OnApplyPressed();

  // for checkbox
  void showTitle(int);

  // for list widget
  void addItem();
  void renameItem();
  void removeItem();
  void clearItems();

 private:
  QPushButton *ok;
  QPushButton *apply;

  QListWidget *lw;
  QPushButton *add;
  QPushButton *rename;
  QPushButton *remove;
  QPushButton *removeAll;
};

#endif
