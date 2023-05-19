#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include <QGraphicsLineItem>
#include <QGraphicsEllipseItem>
#include <QKeyEvent> // Para manejar los eventos relacionados con presionar teclas
#include <QPointF> // Puntos para activar el cambio de movimiento de pacMan
#include <iostream>
#include <vector>
#include <utility>
#include <QPixmap>
#include <QBrush>
#include <QtWidgets/QLCDNumber>
#include <QGraphicsTextItem>

#include "punto.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    // Dimensiones del programaaaa
    static const int tamPacMan = 20;

    static const int xLon = 400;
    static const int yLon = 600;



private:
    Ui::MainWindow *ui;
    QGraphicsScene* escena;

    QGraphicsEllipseItem* pacMan;

    // Describen la dirección de movimiento; Hay 5 posibles valores: U, D, L ,R, N(o movement)
    char dirPacMan; // Dirección en la que se "quiere" mover pacman
    char dirMov; // Dirección en la que se está moviendo pacman
    char tipoMov; // Esto es X o Y (movimiento horizontal y vertical, respectivamente)

    // La estructura de este vector es { coordenadasPuntoTrigger, {1, 0, 1, 0} }
    // donde cada número es un bool que representa si se puede mover en la dirección U, D, L, R respectivamente
    std::vector< std::pair< QPointF, std::vector<int> > > trigPoints;
    bool isInTrig(QGraphicsEllipseItem * ellipse); // To know if pac man is in a trigger position
    bool openUp; // Para saber en qué direcciones se puede mover pacMan en cada trigPoint
    bool openDo;
    bool openLe;
    bool openRi;

    QTimer *timer;

    void keyPressEvent(QKeyEvent *ev); // Eventos de presionar y soltar teclas
    void keyReleaseEvent(QKeyEvent *ev);

    int puntosTot;
    QLCDNumber *lcdNumber;

    std::vector<QGraphicsEllipseItem*> vectPuntos;

    // Gameover text
    QGraphicsTextItem* gameoverText;



signals:
    void emitirS(int); // Señal que se emite cada que se recoge un punto y se indica cuántos puntos se recogió?
    void gameOverSig();

public slots:
    void animar();
    void aumentarPunt(int addPunt);
    void gameOverSlo();
};
#endif // MAINWINDOW_H
// this code sucks
