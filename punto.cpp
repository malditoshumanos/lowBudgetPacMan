

#include "punto.h"

punto::punto(bool tam)
{
    if(tam) grande = true;
    else this->grande = false;
}

QRectF punto::boundingRect() const
{
    if(grande) return QRectF(-10,-10,20,20); // Rectángulo de lado
    else return QRectF(-5,-5,10,10);
}

void punto::paint(QPainter * painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    QRectF rect(-2, -2, 4, 4);
    if(grande) rect.adjust(-3, -3, 6, 6);
    painter->setBrush(Qt::red);
    painter->drawEllipse(boundingRect());
}
