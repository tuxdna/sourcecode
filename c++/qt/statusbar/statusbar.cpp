#include "statusbar.h"
#include <QGridLayout>
#include <QFrame>
#include <QLabel>
#include <QStatusBar>
#include <QCheckBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QInputDialog>

Statusbar::Statusbar(QWidget *parent)
  : QMainWindow(parent)
{
  QHBoxLayout *hbox_main = new QHBoxLayout(this);

  QVBoxLayout *vbox_left = new QVBoxLayout();
  ok = new QPushButton("OK");
  apply = new QPushButton("Apply");

  QCheckBox *cb = new QCheckBox("Show Title");
  cb->setCheckState(Qt::Checked);

  vbox_left->addWidget(ok);
  vbox_left->addWidget(apply);
  vbox_left->addWidget(cb);

  connect(ok, SIGNAL(clicked()), this, SLOT(OnOkPressed()));
  connect(apply, SIGNAL(clicked()), this, SLOT(OnApplyPressed()));
  connect(cb, SIGNAL(stateChanged(int)), SLOT(showTitle(int)));

  hbox_main->addLayout(vbox_left);


  lw = new QListWidget(this);
  lw->addItem("The Omen"); 
  lw->addItem("The Exorcist");
  lw->addItem("Notes on a scandal");
  lw->addItem("Fargo");
  lw->addItem("Capote");

  add = new QPushButton("Add");
  rename = new QPushButton("Rename");
  remove = new QPushButton("Remove");
  removeAll = new QPushButton("Remove All");

  QVBoxLayout *vbox = new QVBoxLayout();
  vbox->setSpacing(10);

  vbox->setSpacing(3);
  vbox->addStretch(1);
  vbox->addWidget(add);
  vbox->addWidget(rename);
  vbox->addWidget(remove);
  vbox->addWidget(removeAll);
  vbox->addStretch(1);

  // must add it to another layout.
  QHBoxLayout *hbox = new QHBoxLayout();

  hbox->addWidget(lw);
  hbox->addSpacing(15);
  hbox->addLayout(vbox);

  connect(add, SIGNAL(clicked()), this, SLOT(addItem()));
  connect(rename, SIGNAL(clicked()), this, SLOT(renameItem()));
  connect(remove, SIGNAL(clicked()), this, SLOT(removeItem()));
  connect(removeAll, SIGNAL(clicked()), this, SLOT(clearItems()));

  // hbox_main->addLayout(hbox);

  setLayout(hbox_main);
  statusBar();
}


void Statusbar::OnOkPressed() {
  statusBar()->showMessage("Ok button pressed", 2000);
}

void Statusbar::OnApplyPressed(){
  statusBar()->showMessage("Apply button pressed", 2000);
}

void Statusbar::showTitle(int state) {
  if(state ==  Qt::Checked) {
    setWindowTitle("QCheckBox");
  }else{
    setWindowTitle("");
  }
}

void Statusbar::addItem()
{
  QString item = QInputDialog::getText(this, "Item",
				       "Enter new item");
  item = item.simplified();
  if (!item.isEmpty()) {
    lw->addItem(item);
    int r = lw->count() - 1;
    lw->setCurrentRow(r);
  }
}

void Statusbar::renameItem()
{
  QListWidgetItem *curitem = lw->currentItem();
  int r = lw->row(curitem);
  QString text = curitem->text();
  QString item = QInputDialog::getText(this, "Item", 
				       "Enter new item", QLineEdit::Normal, text);
  item = item.simplified();
  if (!item.isEmpty()) {
    lw->takeItem(r);
    delete curitem;
    lw->insertItem(r, item);
    lw->setCurrentRow(r);
  }
}

void Statusbar::removeItem()
{
  QListWidgetItem *item = lw->currentItem();

  if (item) {
    int r = lw->row(item);
    lw->takeItem(r);
    delete item;
  }
}

void Statusbar::clearItems()
{
  if (lw->count() != 0)
    lw->clear();
}
