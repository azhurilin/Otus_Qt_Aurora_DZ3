
#include "calcengine.h"
#include "cybercalc52.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    CalcEngine *CEngine = new CalcEngine();

    CyberCalc52 w;

    w.setEngine(CEngine);

    w.show();
    return a.exec();
}
