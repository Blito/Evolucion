#include "camara.h"

Camara::Camara()
{
    setWindowFlags(Qt::Window);
    setRenderHint(QPainter::Antialiasing);
    setBackgroundBrush(QPixmap("../images/pasto.jpg"));
    setCacheMode(QGraphicsView::CacheBackground);
}
