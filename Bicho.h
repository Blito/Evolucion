#ifndef BICHO_H
#define BICHO_H

#include <QRectF>
#include <QPainterPath>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include "agente.h"

class Bicho : public Agente {

public:
    Bicho();

    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);

protected:
    void advance(int step);

private:
    static int xasd;
    static int yasd;
    qreal angulo;
    qreal velocidad;
    QColor color;

    void caminar(); //random
    void caminar(QPoint punto); //ir hacia punto
    void caminar(int x, int y); //overload

};

#endif // BICHO_H
