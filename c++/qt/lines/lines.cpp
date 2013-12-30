#include "lines.h"
#include <QApplication>
#include <QPainter>


Lines::Lines(QWidget *parent)
  : QWidget(parent)
{

}

void Lines::paintEvent(QPaintEvent *event) 
{
  QPen pen(Qt::black, Qt::SolidLine);
  QPainter painter(this);
  painter.setPen(pen);
  painter.drawLine(20,40,250,40);
  
  pen.setStyle(Qt::DashLine);
  painter.setPen(pen);
  painter.drawLine(20,80,250,80);

  pen.setStyle(Qt::DashDotLine);
  painter.setPen(pen);
  painter.drawLine(20,120,250,120);

  pen.setStyle(Qt::DotLine);
  painter.setPen(pen);
  painter.drawLine(20,160,250,160);

  pen.setStyle(Qt::DashDotLine);
  painter.setPen(pen);
  painter.drawLine(20, 200, 250, 200);

  QVector<qreal> dashes;
  qreal space = 4;
  dashes << 1 << space << 5 << space;
  pen.setStyle(Qt::CustomDashLine);
  pen.setDashPattern(dashes);
  painter.setPen(pen);
  painter.drawLine(20, 240, 250, 240);

  painter.setPen(QColor("#d4d4d4"));

  painter.setBrush(QBrush("#c56c00"));
  painter.drawRect(10, 15, 90, 60);

  painter.setBrush(QBrush("#1ac500"));
  painter.drawRect(130, 15, 90, 60);

  painter.setBrush(QBrush("#539e47"));
  painter.drawRect(250, 15, 90, 60);

  painter.setBrush(QBrush("#004fc5"));
  painter.drawRect(10, 105, 90, 60);

  painter.setBrush(QBrush("#c50024"));
  painter.drawRect(130, 105, 90, 60);

  painter.setBrush(QBrush("#9e4757"));
  painter.drawRect(250, 105, 90, 60);

  painter.setBrush(QBrush("#5f3b00"));
  painter.drawRect(10, 195, 90, 60);

  painter.setBrush(QBrush("#4c4c4c"));
  painter.drawRect(130, 195, 90, 60);

  painter.setBrush(QBrush("#785f36"));
  painter.drawRect(250, 195, 90, 60);


  painter.setPen(Qt::NoPen);

  painter.setBrush(Qt::HorPattern);
  painter.drawRect(350+10, 15, 350+90, 60);

  painter.setBrush(Qt::VerPattern);
  painter.drawRect(350+130, 15, 350+90, 60);

  painter.setBrush(Qt::CrossPattern);
  painter.drawRect(350+250, 15, 350+90, 60);

  painter.setBrush(Qt::Dense7Pattern);
  painter.drawRect(350+10, 105, 350+90, 60);

  painter.setBrush(Qt::Dense6Pattern);
  painter.drawRect(350+130, 105, 350+90, 60);

  painter.setBrush(Qt::Dense5Pattern);
  painter.drawRect(350+250, 105, 350+90, 60);

  painter.setBrush(Qt::BDiagPattern);
  painter.drawRect(350+10, 195, 350+90, 60);

  painter.setBrush(Qt::FDiagPattern);
  painter.drawRect(350+130, 195, 350+90, 60);

  painter.setBrush(Qt::DiagCrossPattern);
  painter.drawRect(350+250, 195, 350+90, 60);

  painter.setPen(QPen(QBrush("#535353"), 0.5));

  painter.setRenderHint(QPainter::Antialiasing);

  int h = height();
  int w = width();

  painter.translate(QPoint(w/2, h/2));

  for (qreal rot=0; rot < 360.0; rot+=5.0 ) {
    painter.drawEllipse(-125, -40, 250, 80);
    painter.rotate(5.0);
  }

}


