#include "karenina.h"

#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>

Karenina::Karenina(QWidget *parent)
  : QWidget(parent)
{
  QGridLayout *grid = new QGridLayout(this);
  grid->setSpacing(20);

  QLabel *title = new QLabel("Title", this);
  grid->addWidget(title, 0,0,1,1);
  QLineEdit *edit1 = new QLineEdit(this);
  grid->addWidget(edit1, 0,1,1,1);

  QLabel *author = new QLabel("Author", this);
  grid->addWidget(author, 1,0,1,1);
  QLineEdit *edit2 = new QLineEdit(this);
  grid->addWidget(edit2, 1,1,1,1);

  QLabel *review = new QLabel("Review", this);
  grid->addWidget(review, 2,0,1,1);
  QTextEdit *edit3 = new QTextEdit(this);
  grid->addWidget(edit3, 2,1,3,1);

  setLayout(grid);
}

  
