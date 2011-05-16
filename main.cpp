#include <QtGui>
#include <math.h>
#include "Bicho.h"
#include "camara.h"
#include "escenario.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

    Camara camara;
    camara.resize(500,500);
    camara.show();

    Escenario escenario(&camara);
    escenario.addBicho(50,50);
    escenario.addBicho(-50,-50);
    escenario.addObjeto("../images/manzana.png");

    camara.setScene(&escenario);

    QTimer timer;
    QObject::connect(&timer, SIGNAL(timeout()), &escenario, SLOT(advance()));
    timer.start(1000/33);

    return app.exec();
}
