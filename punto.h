#ifndef PUNTO_H
#define PUNTO_H

#include <QGraphicsEllipseItem>
#include <QRectF> // Para crear un rectángulo que necesita paint() para dibujar la elipse
#include <QPainter>

class punto : public QGraphicsEllipseItem
{
public:
    punto(bool tam = 0);
    QRectF boundingRect() const; // Hitbox del objeto
    bool grande;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // PUNTO_H
