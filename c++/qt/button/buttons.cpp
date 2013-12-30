#include "buttons.h"
#include <QVBoxLayout>
#include <QHBoxLayout>

Buttons::Buttons(QWidget *parent)
  : QWidget(parent)
{

  QVBoxLayout *vbox = new QVBoxLayout(this);
  QHBoxLayout *hbox = new QHBoxLayout();

  ok = new QPushButton("OK", this);
  apply = new QPushButton("Appy", this);

  hbox->addWidget(ok, 1, Qt::AlignRight);
  hbox->addWidget(apply, 0, Qt::AlignRight);

  vbox->addStretch(1);
  vbox->addLayout(hbox);

}
