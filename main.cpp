#include "calculator.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    //app.setStyleSheet("background-color:black;");

    calculator w;
    w.show();
    return app.exec();
}
