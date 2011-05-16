#include "Bicho.h"
#include <math.h>
#include "escenario.h"
#include <iostream>

using namespace std;

static const double Pi = 3.14159265358979323846264338327950288419717;
static double TwoPi = 2.0 * Pi;

int Bicho::xasd = 0;
int Bicho::yasd = 0;

static qreal normalizeAngle(qreal angle)
{
    while (angle < 0)
        angle += TwoPi;
    while (angle > TwoPi)
        angle -= TwoPi;
    return angle;
}

Bicho::Bicho() {
    angulo = qrand() % 360;
    xasd = 0;
    yasd = 0;
    setRotation(0);
    velocidad = 1;
    color.setRgb(qrand() % 256, qrand() % 256, qrand() % 256, 255);
    vista << QPoint(0, 0) << QPoint(300, 120) << QPoint(300, -120);
}

QRectF Bicho::boundingRect() const {
    return QRectF(-20, -200, 300, 400);
}

QPainterPath Bicho::shape() const {
    QPainterPath path;
    path.addEllipse(-20, -20, 40, 40);
    return path;
}

void Bicho::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {

    //vision
    QLinearGradient gradiente(0, 0, 300, 0);
    gradiente.setColorAt(0, Qt::black);
    gradiente.setColorAt(1, Qt::yellow);
    QBrush pincel(gradiente);
    painter->setOpacity(0.3);
    painter->setBrush(pincel);
    painter->setPen(Qt::NoPen);
    painter->drawPolygon(vista);
    painter->setOpacity(1);

    //cuerpo
    QPen pen;
    pen.setWidth(3);
    pen.setColor(Qt::black);
    painter->setBrush(color);
    painter->setPen(pen);
    painter->drawEllipse(-20, -20, 40, 40);

    //ojos
    painter->setBrush(Qt::white);
    //if (enVista().size() > 1)
      //  painter->setBrush(Qt::red);
    QPointF ojoIzquierdo(14, -10);
    QPointF ojoDerecho(14, 10);
    painter->drawEllipse(ojoIzquierdo, 5, 5);
    painter->drawEllipse(ojoDerecho, 5, 5);

    //pupilas
    painter->setBrush(Qt::black);
    if (enVista().size() > 1) {
        painter->setPen(Qt::red);
        painter->setBrush(Qt::red);
    }
    QPointF pupilaIzq(16, -10);
    QPointF pupilaDer(16, 10);
    painter->drawEllipse(pupilaIzq, 2, 2);
    painter->drawEllipse(pupilaDer, 2, 2);

}

void Bicho::advance(int step) {

    if (step == 0)
        return;

    qreal r = qrand() % 200;
    if (r < 2){
        xasd = qrand()%500;
        yasd = qrand()%500;
    }

    caminar(QPoint(xasd,yasd));

}

void Bicho::caminar() {

    qreal dr = 0;
        dr = (qrand() % 26) - 13;
    angulo += dr;

    qreal aceleracion = (qrand() % 3) - 1;
    velocidad += aceleracion;

    if (velocidad > 3) velocidad = 3;
    if (velocidad < 0) velocidad = 0;

    setPos(mapToParent(velocidad, 0));
    setRotation(angulo);
}

void Bicho::caminar(QPoint punto) {
    QPointF destino = mapFromScene(punto);

    if (destino.manhattanLength() < 10)
        return;

    if ((destino.y() < 20) && (destino.y() > -20)) {
        if ((destino.x() >30) && (velocidad < 3))
            velocidad++;
        if ((destino.x() < 30) && (velocidad > 0))
            velocidad--;
    }

    if (destino.x()<0 && destino.y()>0)
        angulo += 5;
    if (destino.x()<0 && destino.y()<0)
        angulo -= 5;
    if (destino.x()>0)
        angulo += destino.y()/20;

    setPos(mapToParent(velocidad, 0));
    setRotation(angulo);
}
