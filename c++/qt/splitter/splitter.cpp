#include "splitter.h"
#include <QFrame>
#include <QSplitter>
#include <QHBoxLayout>
#include <QTableWidget>

Splitter::Splitter(QWidget *parent)
  : QWidget(parent)
{
  QHBoxLayout *hbox = new QHBoxLayout(this);

  QFrame *topleft = new QFrame(this);
  topleft->setFrameShape(QFrame::StyledPanel);

  QFrame *topright = new QFrame(this);
  topright->setFrameShape(QFrame::StyledPanel);

  QSplitter *splitter1 = new QSplitter(Qt::Horizontal, this);
  splitter1->addWidget(topleft);
  splitter1->addWidget(topright);

  QFrame *bottom = new QFrame(this);
  bottom->setFrameShape(QFrame::StyledPanel);

  QSplitter *splitter2 = new QSplitter(Qt::Vertical, this);
  splitter2->addWidget(splitter1);
  splitter2->addWidget(bottom);

  QTableWidget *table = new QTableWidget(25,25,bottom);
  // bottom->addWidget(table);

  hbox->addWidget(splitter2);
  setLayout(hbox);

}
