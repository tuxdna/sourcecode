#include "disconnect.h"
#include <QTextStream>
#include <QCheckBox>


Disconnect::Disconnect(QWidget *parent)
  : QWidget(parent)
{
  click = new QPushButton("Click", this);
  click->setGeometry(50, 40, 75, 30);

  QCheckBox *cb = new QCheckBox("Connect", this);
  cb->setCheckState(Qt::Checked);
  cb->move(150, 40);

  connect(click, SIGNAL(clicked()), 
	  this, SLOT(onClick()));
  connect(cb, SIGNAL(stateChanged(int)), 
	  this, SLOT(onCheck(int)));
}

void Disconnect::onClick() 
{
  QTextStream out(stdout);
  out << "Button clicked\n";
}

void Disconnect::onCheck(int state)
{
  if (state == Qt::Checked) {
    connect(click, SIGNAL(clicked()), 
	    this, SLOT(onClick()));
  } else {
    click->disconnect(SIGNAL(clicked()));
  }
}
