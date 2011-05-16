#include "escenario.h"

Escenario::Escenario(QObject * parent) :
        QGraphicsScene(parent)
{

    setSceneRect(-300, -300, 600, 600);

}

Bicho * Escenario::addBicho() {

    Bicho * bicho = new Bicho();
    bicho->setPos(0,0);
    addItem(bicho);

    return bicho;

}

Bicho * Escenario::addBicho(qreal x, qreal y) {

    Bicho * bicho = new Bicho();
    bicho->setPos(x,y);
    addItem(bicho);

    return bicho;

}

Objeto * Escenario::addObjeto(QString filename) {

    Objeto * objeto = new Objeto(QPixmap(filename));
    objeto->setPos(0,0);
    addItem(objeto);

    return objeto;

}

Objeto * Escenario::addObjeto(qreal x, qreal y, QString filename) {

    Objeto * objeto = new Objeto(QPixmap(filename));
    objeto->setPos(x,y);
    addItem(objeto);

    return objeto;

}
