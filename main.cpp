#include <QApplication>
#include <QWidget>
#include <calcui.h>

int main(int argc, char ** argv){
    QApplication app(argc,argv);
    CalcUI calc(true);
    calc.resize(400,400);
    calc.setWindowIcon(QIcon("://img/icon.png"));
    calc.show();
    return app.exec();
}
