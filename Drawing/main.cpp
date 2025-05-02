#include "win.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    win window;
    window.show();
    return app.exec();
}
