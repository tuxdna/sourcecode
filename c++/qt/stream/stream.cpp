#include <iostream>
#include <QTextStream>

int main() {
  QTextStream out(stdout);
  out << "console application\n";

  std::cout << "console app" << std::endl;
}
