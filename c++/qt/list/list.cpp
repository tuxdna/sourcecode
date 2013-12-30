#include <QTextStream>
#include <QList>

int main() {
  QTextStream out(stdout);
  QList<QString> list;

  list << "One" << "There" << "Here"
       << "Why" << "horse" << "runs";

  qSort(list);

  for(int i = 0; i < list.size(); i++ ) {
    out << list.at(i) << endl;
  }
}
