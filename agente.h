#ifndef AGENTE_H
#define AGENTE_H

#include <QGraphicsItem>

class Agente : public QGraphicsItem
{
public:
    Agente();

protected:
    QPolygon vista;
    QList<QGraphicsItem*> enVista();

    virtual void caminar() = 0; //random
    virtual void caminar(QPoint punto) = 0; //ir hacia punto
    void caminar(int x, int y); //overload
};

#endif // AGENTE_H
