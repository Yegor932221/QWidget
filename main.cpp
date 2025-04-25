#include "win.h"
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    win win(0);
    win.show();
    return app.exec();
}
