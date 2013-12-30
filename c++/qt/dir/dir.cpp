#include <QTextStream>
#include <QDir>

int main() {
  QTextStream out(stdout);
  QString home = QDir::homePath();
  out << "Home Folder: " << home << endl;

  QDir dir;
  QStringList  filters;
  filters << "*.cpp" << "*.pro";

  dir.setNameFilters(filters);
  QFileInfoList list = dir.entryInfoList();
  for(int i = 0; i < list.size(); i++ ) {
    QFileInfo fileInfo = list.at(i);
    out << QString("%1").arg(fileInfo.fileName());
    out << endl;
  }

}

