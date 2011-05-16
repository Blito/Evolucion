#include "agente.h"
#include "escenario.h"

Agente::Agente()
{
}

void Agente::caminar(int x, int y) {
    caminar(QPoint(x,y));
}

QList<QGraphicsItem*> Agente::enVista() {
    Escenario * escenario = (Escenario*)scene();
    return escenario->items(mapToScene(vista));
}
