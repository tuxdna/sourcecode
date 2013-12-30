#include <QtGui/QApplication>
#include "Breakout.h"


int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    Breakout foo;
    foo.show();
    return app.exec();
}
