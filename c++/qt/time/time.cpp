#include <QTextStream>
#include <QTime>

int main() {
  QTextStream out(stdout);
  QTime qtime = QTime::currentTime();
  QString stime = qtime.toString(Qt::LocalDate);
  out << stime << endl;

  out << "QString examples:" << endl;

  QString a = "Discipline ";
  QString b = "is ";
  QString c = "must. ";

  out << a + b + c << endl;

  QString string = "Whether I shall ";
  string.append("turn out to be the hero of my own life, \n");
  string.append("or whether that station will be held by anybody else, \n");
  string.append("these pages must show.\n");

  out << string << endl;

  QString argstring = "What if I gave you %1 red roses?";
  int num = 21;

  out << argstring.arg(num) << endl;

  out << "The string 'string' has " + QString::number(string.size()) 
    + " characters." << endl;

  out << (a+b+c).toUpper() << endl;
  out << (a+b+c).toLower() << endl;
}

