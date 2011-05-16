#ifndef ESCENARIO_H
#define ESCENARIO_H

#include <QGraphicsScene>
#include "Bicho.h"
#include "objeto.h"

class Escenario : public QGraphicsScene
{
public:
    Escenario(QObject *parent);

    Bicho * addBicho();
    Bicho * addBicho(qreal x, qreal y);
    Objeto * addObjeto(QString filename);
    Objeto * addObjeto(qreal x, qreal y, QString filename);
};

#endif // ESCENARIO_H
