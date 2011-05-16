#ifndef OBJETO_H
#define OBJETO_H

#include <QGraphicsItem>

class Objeto : public QGraphicsPixmapItem
{
public:
    Objeto(const QPixmap & pixmap);

protected:

    void advance(int step);
};

#endif // OBJETO_H
