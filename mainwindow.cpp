#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "punto.h" //TODO: implementarlo con esta clase

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);   

    escena = new QGraphicsScene(0, 0, 450, 650); // dimensiones (xOrigen, yOrigen, width, height)
    ui->graphicsView->setScene(escena);

    QPixmap backgroundImage(":/new/prefix1/backkk.png");
    //ui->label->setPixmap(backgroundImage);
    ui->graphicsView->scene()->addPixmap(backgroundImage);


    puntosTot = 0;

    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(animar())); // Conectar la señal del timeout del timer con el slot animar
    timer->start(25); // Iniciar el timer con un timeout de 33ms


// *********************************************************************
// Crear puntos en donde pacman puede cambiar de dirección
// *********************************************************************
// -------------------------------------------------fila 1
    QPointF point(0, 0);
    std::vector<int> opens; // Vector que guarda la información sobre las direcciones en que se puede mover pacMan
    opens.push_back(0);
    opens.push_back(1);
    opens.push_back(0);
    opens.push_back(1);
    trigPoints.push_back(std::make_pair(point, opens));

    point.setX(50);
    point.setY(0);
    opens[0] = 0;
    opens[1] = 1;
    opens[2] = 1;
    opens[3] = 1;
    trigPoints.push_back(std::make_pair(point, opens));

    point.setX(170);
    point.setY(0);
    opens[0] = 0;
    opens[1] = 1;
    opens[2] = 1;
    opens[3] = 0;
    trigPoints.push_back(std::make_pair(point, opens));

    point.setX(210);
    point.setY(0);
    opens[0] = 0;
    opens[1] = 1;
    opens[2] = 0;
    opens[3] = 1;
    trigPoints.push_back(std::make_pair(point, opens));

    point.setX(330);
    point.setY(0);
    opens[0] = 0;
    opens[1] = 1;
    opens[2] = 1;
    opens[3] = 1;
    trigPoints.push_back(std::make_pair(point, opens));

    point.setX(380);
    point.setY(0);
    opens[0] = 0;
    opens[1] = 1;
    opens[2] = 1;
    opens[3] = 0;
    trigPoints.push_back(std::make_pair(point, opens));
// -------------------------------------------------fila 2
    point.setY(80);
    point.setX(0);
    opens[0] = 1;
    opens[1] = 1;
    opens[2] = 0;
    opens[3] = 1;
    trigPoints.push_back(std::make_pair(point, opens));

    point.setX(50);
    opens[0] = 1;
    opens[1] = 1;
    opens[2] = 1;
    opens[3] = 1;
    trigPoints.push_back(std::make_pair(point, opens));

    point.setX(90);
    opens[0] = 0;
    opens[1] = 1;
    opens[2] = 1;
    opens[3] = 1;
    trigPoints.push_back(std::make_pair(point, opens));

    point.setX(170);
    opens[0] = 1;
    opens[1] = 0;
    opens[2] = 1;
    opens[3] = 1;
    trigPoints.push_back(std::make_pair(point, opens));

    point.setX(210);
    opens[0] = 1;
    opens[1] = 0;
    opens[2] = 1;
    opens[3] = 1;
    trigPoints.push_back(std::make_pair(point, opens));

    point.setX(290);
    opens[0] = 0;
    opens[1] = 1;
    opens[2] = 1;
    opens[3] = 1;
    trigPoints.push_back(std::make_pair(point, opens));

    point.setX(330);
    opens[0] = 1;
    opens[1] = 1;
    opens[2] = 1;
    opens[3] = 1;
    trigPoints.push_back(std::make_pair(point, opens));

    point.setX(380);
    opens[0] = 1;
    opens[1] = 1;
    opens[2] = 1;
    opens[3] = 0;
    trigPoints.push_back(std::make_pair(point, opens));
// -------------------------------------------------fila 3
        point.setY(120);

        point.setX(90);
        opens[0] = 1;
        opens[1] = 0;
        opens[2] = 0;
        opens[3] = 1;
        trigPoints.push_back(std::make_pair(point, opens));

        point.setX(170);
        opens[0] = 0;
        opens[1] = 1;
        opens[2] = 1;
        opens[3] = 0;
        trigPoints.push_back(std::make_pair(point, opens));

        point.setX(210);
        opens[0] = 0;
        opens[1] = 1;
        opens[2] = 0;
        opens[3] = 1;
        trigPoints.push_back(std::make_pair(point, opens));

        point.setX(290);
        opens[0] = 1;
        opens[1] = 0;
        opens[2] = 1;
        opens[3] = 0;
        trigPoints.push_back(std::make_pair(point, opens));

// -------------------------------------------------fila 4
        point.setY(140);

        point.setX(0);
        opens[0] = 1;
        opens[1] = 0;
        opens[2] = 0;
        opens[3] = 1;
        trigPoints.push_back(std::make_pair(point, opens));

        point.setX(50);
        opens[0] = 1;
        opens[1] = 1;
        opens[2] = 1;
        opens[3] = 0;
        trigPoints.push_back(std::make_pair(point, opens));

        point.setX(330);
        opens[0] = 1;
        opens[1] = 1;
        opens[2] = 0;
        opens[3] = 1;
        trigPoints.push_back(std::make_pair(point, opens));

        point.setX(380);
        opens[0] = 1;
        opens[1] = 0;
        opens[2] = 1;
        opens[3] = 0;
        trigPoints.push_back(std::make_pair(point, opens));

// -------------------------------------------------fila 5
        point.setY(160);

        point.setX(90);
        opens[0] = 0;
        opens[1] = 1;
        opens[2] = 0;
        opens[3] = 1;
        trigPoints.push_back(std::make_pair(point, opens));

        point.setX(170);
        opens[0] = 1;
        opens[1] = 0;
        opens[2] = 1;
        opens[3] = 1;
        trigPoints.push_back(std::make_pair(point, opens));

        point.setX(210);
        opens[0] = 1;
        opens[1] = 0;
        opens[2] = 1;
        opens[3] = 1;
        trigPoints.push_back(std::make_pair(point, opens));

        point.setX(290);
        opens[0] = 0;
        opens[1] = 1;
        opens[2] = 1;
        opens[3] = 0;
        trigPoints.push_back(std::make_pair(point, opens));


// -------------------------------------------------fila 6
        point.setY(240);

        point.setX(0);
        opens[0] = 0;
        opens[1] = 0;
        opens[2] = 0;
        opens[3] = 1;
        trigPoints.push_back(std::make_pair(point, opens));

        point.setX(50);
        opens[0] = 1;
        opens[1] = 1;
        opens[2] = 1;
        opens[3] = 1;
        trigPoints.push_back(std::make_pair(point, opens));

        point.setX(90);
        opens[0] = 1;
        opens[1] = 1;
        opens[2] = 1;
        opens[3] = 0;
        trigPoints.push_back(std::make_pair(point, opens));

        point.setX(290);
        opens[0] = 1;
        opens[1] = 1;
        opens[2] = 0;
        opens[3] = 1;
        trigPoints.push_back(std::make_pair(point, opens));

        point.setX(330);
        opens[0] = 1;
        opens[1] = 1;
        opens[2] = 1;
        opens[3] = 1;
        trigPoints.push_back(std::make_pair(point, opens));

        point.setX(380);
        opens[0] = 0;
        opens[1] = 0;
        opens[2] = 1;
        opens[3] = 0;
        trigPoints.push_back(std::make_pair(point, opens));

// -------------------------------------------------fila 7
        point.setY(300);

        point.setX(90);
        opens[0] = 1;
        opens[1] = 1;
        opens[2] = 0;
        opens[3] = 1;
        trigPoints.push_back(std::make_pair(point, opens));

        point.setX(290);
        opens[0] = 1;
        opens[1] = 1;
        opens[2] = 1;
        opens[3] = 0;
        trigPoints.push_back(std::make_pair(point, opens));

// -------------------------------------------------fila 8
        point.setY(340);

        point.setX(0);
        opens[0] = 0;
        opens[1] = 1;
        opens[2] = 0;
        opens[3] = 1;
        trigPoints.push_back(std::make_pair(point, opens));

        point.setX(50);
        opens[0] = 1;
        opens[1] = 1;
        opens[2] = 1;
        opens[3] = 1;
        trigPoints.push_back(std::make_pair(point, opens));

        point.setX(90);
        opens[0] = 1;
        opens[1] = 0;
        opens[2] = 1;
        opens[3] = 1;
        trigPoints.push_back(std::make_pair(point, opens));

        point.setX(170);
        opens[0] = 0;
        opens[1] = 1;
        opens[2] = 1;
        opens[3] = 0;
        trigPoints.push_back(std::make_pair(point, opens));

        point.setX(210);
        opens[0] = 0;
        opens[1] = 1;
        opens[2] = 0;
        opens[3] = 1;
        trigPoints.push_back(std::make_pair(point, opens));

        point.setX(290);
        opens[0] = 1;
        opens[1] = 0;
        opens[2] = 1;
        opens[3] = 1;
        trigPoints.push_back(std::make_pair(point, opens));

        point.setX(330);
        opens[0] = 1;
        opens[1] = 1;
        opens[2] = 1;
        opens[3] = 1;
        trigPoints.push_back(std::make_pair(point, opens));

        point.setX(380);
        opens[0] = 0;
        opens[1] = 1;
        opens[2] = 1;
        opens[3] = 0;
        trigPoints.push_back(std::make_pair(point, opens));

// -------------------------------------------------fila 9
        point.setY(380);

        point.setX(0);
        opens[0] = 1;
        opens[1] = 0;
        opens[2] = 0;
        opens[3] = 1;
        trigPoints.push_back(std::make_pair(point, opens));

        point.setX(20);
        opens[0] = 0;
        opens[1] = 1;
        opens[2] = 1;
        opens[3] = 0;
        trigPoints.push_back(std::make_pair(point, opens));

        point.setX(50);
        opens[0] = 1;
        opens[1] = 1;
        opens[2] = 0;
        opens[3] = 1;
        trigPoints.push_back(std::make_pair(point, opens));

        point.setX(90);
        opens[0] = 0;
        opens[1] = 1;
        opens[2] = 1;
        opens[3] = 1;
        trigPoints.push_back(std::make_pair(point, opens));

        point.setX(170);
        opens[0] = 1;
        opens[1] = 0;
        opens[2] = 1;
        opens[3] = 1;
        trigPoints.push_back(std::make_pair(point, opens));

        point.setX(210);
        opens[0] = 1;
        opens[1] = 0;
        opens[2] = 1;
        opens[3] = 1;
        trigPoints.push_back(std::make_pair(point, opens));

        point.setX(290);
        opens[0] = 0;
        opens[1] = 1;
        opens[2] = 1;
        opens[3] = 1;
        trigPoints.push_back(std::make_pair(point, opens));

        point.setX(330);
        opens[0] = 1;
        opens[1] = 1;
        opens[2] = 1;
        opens[3] = 0;
        trigPoints.push_back(std::make_pair(point, opens));

        point.setX(360);
        opens[0] = 0;
        opens[1] = 1;
        opens[2] = 0;
        opens[3] = 1;
        trigPoints.push_back(std::make_pair(point, opens));

        point.setX(380);
        opens[0] = 1;
        opens[1] = 0;
        opens[2] = 1;
        opens[3] = 0;
        trigPoints.push_back(std::make_pair(point, opens));

// -------------------------------------------------fila 10
        point.setY(440);

        point.setX(0);
        opens[0] = 0;
        opens[1] = 1;
        opens[2] = 0;
        opens[3] = 1;
        trigPoints.push_back(std::make_pair(point, opens));

        point.setX(20);
        opens[0] = 1;
        opens[1] = 0;
        opens[2] = 1;
        opens[3] = 1;
        trigPoints.push_back(std::make_pair(point, opens));

        point.setX(50);
        opens[0] = 1;
        opens[1] = 0;
        opens[2] = 1;
        opens[3] = 0;
        trigPoints.push_back(std::make_pair(point, opens));

        point.setX(90);
        opens[0] = 1;
        opens[1] = 0;
        opens[2] = 0;
        opens[3] = 1;
        trigPoints.push_back(std::make_pair(point, opens));

        point.setX(170);
        opens[0] = 0;
        opens[1] = 1;
        opens[2] = 1;
        opens[3] = 0;
        trigPoints.push_back(std::make_pair(point, opens));

        point.setX(210);
        opens[0] = 0;
        opens[1] = 1;
        opens[2] = 0;
        opens[3] = 1;
        trigPoints.push_back(std::make_pair(point, opens));

        point.setX(290);
        opens[0] = 1;
        opens[1] = 0;
        opens[2] = 1;
        opens[3] = 0;
        trigPoints.push_back(std::make_pair(point, opens));

        point.setX(330);
        opens[0] = 1;
        opens[1] = 0;
        opens[2] = 0;
        opens[3] = 1;
        trigPoints.push_back(std::make_pair(point, opens));

        point.setX(360);
        opens[0] = 1;
        opens[1] = 0;
        opens[2] = 1;
        opens[3] = 1;
        trigPoints.push_back(std::make_pair(point, opens));

        point.setX(380);
        opens[0] = 0;
        opens[1] = 1;
        opens[2] = 1;
        opens[3] = 0;
        trigPoints.push_back(std::make_pair(point, opens));

// -------------------------------------------------fila 11
        point.setY(480);

        point.setX(0);
        opens[0] = 1;
        opens[1] = 0;
        opens[2] = 0;
        opens[3] = 1;
        trigPoints.push_back(std::make_pair(point, opens));

        point.setX(170);
        opens[0] = 1;
        opens[1] = 0;
        opens[2] = 1;
        opens[3] = 1;
        trigPoints.push_back(std::make_pair(point, opens));

        point.setX(210);
        opens[0] = 1;
        opens[1] = 0;
        opens[2] = 1;
        opens[3] = 1;
        trigPoints.push_back(std::make_pair(point, opens));

        point.setX(380);
        opens[0] = 1;
        opens[1] = 0;
        opens[2] = 1;
        opens[3] = 0;
        trigPoints.push_back(std::make_pair(point, opens));


    // Crear personaje
    pacMan = new QGraphicsEllipseItem(0, 0, tamPacMan, tamPacMan);
    pacMan->setPos(0, 0);
    escena->addItem(pacMan); // Pacman comienza mirando hacia abajo
    dirMov = 'D';
    tipoMov = 'Y';
    dirPacMan = 'D';
    puntosTot = 0;


    //ellipsePrueba = new QGraphicsEllipseItem(100, 0, 10, 10);
    //escena->addItem(ellipsePrueba);

    QGraphicsEllipseItem * ptrEllipse;
    for(int i = 9; i <= 189; i+=10){
        ptrEllipse = new QGraphicsEllipseItem(i, 9, 2, 2);
        vectPuntos.push_back(ptrEllipse);
    }
    for(int i = 219; i <= 389; i+=10){
        ptrEllipse = new QGraphicsEllipseItem(i, 9, 2, 2);
        vectPuntos.push_back(ptrEllipse);
    }

    for(int i = 9; i <= 389; i+=10){
        ptrEllipse = new QGraphicsEllipseItem(i, 89, 2, 2);
        vectPuntos.push_back(ptrEllipse);
    }

    for(int i = 99; i <= 179; i+=10){
        ptrEllipse = new QGraphicsEllipseItem(i, 129, 2, 2);
        vectPuntos.push_back(ptrEllipse);
    }

    for(int i = 219; i <= 299; i+=10){
        ptrEllipse = new QGraphicsEllipseItem(i, 129, 2, 2);
        vectPuntos.push_back(ptrEllipse);
    }

    for(int i = 9; i <= 59; i+=10){
        ptrEllipse = new QGraphicsEllipseItem(i, 149, 2, 2);
        vectPuntos.push_back(ptrEllipse);
    }

    for(int i = 339; i <= 389; i+=10){
        ptrEllipse = new QGraphicsEllipseItem(i, 149, 2, 2);
        vectPuntos.push_back(ptrEllipse);
    }

    for(int i = 99; i <= 299; i+=10){
        ptrEllipse = new QGraphicsEllipseItem(i, 169, 2, 2);
        vectPuntos.push_back(ptrEllipse);
    }

    for(int i = 9; i <= 99; i+=10){
        ptrEllipse = new QGraphicsEllipseItem(i, 249, 2, 2);
        vectPuntos.push_back(ptrEllipse);
    }

    for(int i = 299; i <= 399; i+=10){
        ptrEllipse = new QGraphicsEllipseItem(i, 249, 2, 2);
        vectPuntos.push_back(ptrEllipse);
    }

    for(int i = 99; i <= 299; i+=10){
        ptrEllipse = new QGraphicsEllipseItem(i, 309, 2, 2);
        vectPuntos.push_back(ptrEllipse);
    }

    for(int i = 9; i <= 179; i+=10){
        ptrEllipse = new QGraphicsEllipseItem(i, 349, 2, 2);
        vectPuntos.push_back(ptrEllipse);
    }

    for(int i = 219; i <= 389; i+=10){
        ptrEllipse = new QGraphicsEllipseItem(i, 349, 2, 2);
        vectPuntos.push_back(ptrEllipse);
    }

    for(int i = 9; i <= 29; i+=10){
        ptrEllipse = new QGraphicsEllipseItem(i, 389, 2, 2);
        vectPuntos.push_back(ptrEllipse);
    }

    for(int i = 59; i <= 339; i+=10){
        ptrEllipse = new QGraphicsEllipseItem(i, 389, 2, 2);
        vectPuntos.push_back(ptrEllipse);
    }

    for(int i = 369; i <= 389; i+=10){
        ptrEllipse = new QGraphicsEllipseItem(i, 389, 2, 2);
        vectPuntos.push_back(ptrEllipse);
    }

    for(int i = 9; i <= 59; i+=10){
        ptrEllipse = new QGraphicsEllipseItem(i, 449, 2, 2);
        vectPuntos.push_back(ptrEllipse);
    }

    for(int i = 99; i <= 179; i+=10){
        ptrEllipse = new QGraphicsEllipseItem(i, 449, 2, 2);
        vectPuntos.push_back(ptrEllipse);
    }

    for(int i = 219; i <= 299; i+=10){
        ptrEllipse = new QGraphicsEllipseItem(i, 449, 2, 2);
        vectPuntos.push_back(ptrEllipse);
    }

    for(int i = 339; i <= 389; i+=10){
        ptrEllipse = new QGraphicsEllipseItem(i, 449, 2, 2);
        vectPuntos.push_back(ptrEllipse);
    }

    for(int i = 9; i <= 389; i+=10){
        ptrEllipse = new QGraphicsEllipseItem(i, 489, 2, 2);
        vectPuntos.push_back(ptrEllipse);
    }

    for(int i = 9; i <= 149; i+=10){
        ptrEllipse = new QGraphicsEllipseItem(9, i, 2, 2);
        vectPuntos.push_back(ptrEllipse);
    }

    for(int i = 349; i <= 389; i+=10){
        ptrEllipse = new QGraphicsEllipseItem(9, i, 2, 2);
        vectPuntos.push_back(ptrEllipse);
    }

    for(int i = 449; i <= 489; i+=10){
        ptrEllipse = new QGraphicsEllipseItem(9, i, 2, 2);
        vectPuntos.push_back(ptrEllipse);
    }

    for(int i = 9; i <= 449; i+=10){
        ptrEllipse = new QGraphicsEllipseItem(60, i, 2, 2);
        vectPuntos.push_back(ptrEllipse);
    }

    for(int i = 89; i <= 129; i+=10){
        ptrEllipse = new QGraphicsEllipseItem(100, i, 2, 2);
        vectPuntos.push_back(ptrEllipse);
    }

    for(int i = 169; i <= 349; i+=10){
        ptrEllipse = new QGraphicsEllipseItem(100, i, 2, 2);
        vectPuntos.push_back(ptrEllipse);
    }

    for(int i = 389; i <= 449; i+=10){
        ptrEllipse = new QGraphicsEllipseItem(100, i, 2, 2);
        vectPuntos.push_back(ptrEllipse);
    }

    for(int i = 9; i <= 89; i+=10){
        ptrEllipse = new QGraphicsEllipseItem(180, i, 2, 2);
        vectPuntos.push_back(ptrEllipse);
    }

    for(int i = 129; i <= 169; i+=10){
        ptrEllipse = new QGraphicsEllipseItem(180, i, 2, 2);
        vectPuntos.push_back(ptrEllipse);
    }

    for(int i = 349; i <= 389; i+=10){
        ptrEllipse = new QGraphicsEllipseItem(180, i, 2, 2);
        vectPuntos.push_back(ptrEllipse);
    }

    for(int i = 449; i <= 489; i+=10){
        ptrEllipse = new QGraphicsEllipseItem(180, i, 2, 2);
        vectPuntos.push_back(ptrEllipse);
    }

    for(int i = 9; i <= 89; i+=10){
        ptrEllipse = new QGraphicsEllipseItem(220, i, 2, 2);
        vectPuntos.push_back(ptrEllipse);
    }

    for(int i = 129; i <= 169; i+=10){
        ptrEllipse = new QGraphicsEllipseItem(220, i, 2, 2);
        vectPuntos.push_back(ptrEllipse);
    }

    for(int i = 349; i <= 389; i+=10){
        ptrEllipse = new QGraphicsEllipseItem(220, i, 2, 2);
        vectPuntos.push_back(ptrEllipse);
    }

    for(int i = 449; i <= 489; i+=10){
        ptrEllipse = new QGraphicsEllipseItem(220, i, 2, 2);
        vectPuntos.push_back(ptrEllipse);
    }

    for(int i = 89; i <= 129; i+=10){
        ptrEllipse = new QGraphicsEllipseItem(300, i, 2, 2);
        vectPuntos.push_back(ptrEllipse);
    }

    for(int i = 169; i <= 349; i+=10){
        ptrEllipse = new QGraphicsEllipseItem(300, i, 2, 2);
        vectPuntos.push_back(ptrEllipse);
    }

    for(int i = 389; i <= 449; i+=10){
        ptrEllipse = new QGraphicsEllipseItem(300, i, 2, 2);
        vectPuntos.push_back(ptrEllipse);
    }

    for(int i = 9; i <= 449; i+=10){
        ptrEllipse = new QGraphicsEllipseItem(340, i, 2, 2);
        vectPuntos.push_back(ptrEllipse);
    }

    for(int i = 9; i <= 149; i+=10){
        ptrEllipse = new QGraphicsEllipseItem(390, i, 2, 2);
        vectPuntos.push_back(ptrEllipse);
    }

    for(int i = 349; i <= 389; i+=10){
        ptrEllipse = new QGraphicsEllipseItem(390, i, 2, 2);
        vectPuntos.push_back(ptrEllipse);
    }

    for(int i = 449; i <= 489; i+=10){
        ptrEllipse = new QGraphicsEllipseItem(390, i, 2, 2);
        vectPuntos.push_back(ptrEllipse);
    }



    for(auto punt : vectPuntos){
        escena->addItem(punt);
    }

    lcdNumber = new QLCDNumber();
    // Conectar el slot de recoger puntos con el slot de aumentar putuación
    connect(this,SIGNAL(emitirS(int)),this,SLOT(aumentarPunt(int))); // de esta clase - la señal emitirS asignamos a - de esta clase - el slot aumentar puntuación

    connect(this, SIGNAL(gameOverSig()), this, SLOT(gameOverSlo()));

}


// Destructor
MainWindow::~MainWindow()
{
    delete ui;
    delete escena;
}


// *****************************************************************************
// Eventos para cuando se presiona o se suelta una tecla
// *****************************************************************************
void MainWindow::keyPressEvent(QKeyEvent *ev)
{
    if(ev->key()==Qt::Key_A) // Si la tecla presionada es la A
    {
        dirPacMan = 'L';
    }
    else if(ev->key()==Qt::Key_S)
    {
        dirPacMan = 'D';
    }
    else if(ev->key()==Qt::Key_W)
    {
        dirPacMan = 'U';
    }
    else if(ev->key()==Qt::Key_D)
    {
        dirPacMan = 'R';
    }
}
void MainWindow::keyReleaseEvent(QKeyEvent *ev){

    if(ev->key()==Qt::Key_W || ev->key()==Qt::Key_S || ev->key()==Qt::Key_A || ev->key()==Qt::Key_D) // Si la tecla presionada es la A
    {
        dirPacMan = 'N';
    }
}





// ############################       Animar            ##############################

bool MainWindow::isInTrig(QGraphicsEllipseItem* ellipse) { // Método para controlar el movimiento de pacMan
    QPointF position = ellipse->pos(); // Posición de pacMan
    for (const auto& element : trigPoints) { // Iterar sobre todos los trigPoints
        if (element.first == position) { // Si pacMan está en un trigPoint

            if(element.second[0]) openUp = true;
            if(element.second[1]) openDo = true;
            if(element.second[2]) openLe = true;
            if(element.second[3]) openRi = true;

            return true;
        }
    }
    return false;
}
void MainWindow::animar(){

     std::cout << pacMan->x() << '/' << pacMan->y() << std::endl;
    bool notInTrig;
    if(isInTrig(pacMan)){ // If pacMan is in a trigger point
        notInTrig = false;
        // Detenerlo si se encuentra una pared
        if(dirMov == 'U' && (!openUp)){
            dirMov = 'N';
        }
        if(dirMov == 'D' && (!openDo)){
            dirMov = 'N';
        }
        if(dirMov == 'L' && (!openLe)){
            dirMov = 'N';
        }
        if(dirMov == 'R' && (!openRi)){
            dirMov = 'N';
        }
    } else {
        openUp = false;
        openDo = false;
        openLe = false;
        openRi = false;
        notInTrig = true;
    }

    // Si el movimiento es vertical u horizontal
    if(tipoMov == 'X'){
        if(notInTrig && (dirPacMan == 'L' || dirPacMan == 'R') ) dirMov = dirPacMan;
        else if(dirPacMan == 'L' && openLe) dirMov = dirPacMan;
        else if(dirPacMan == 'R' && openRi) dirMov = dirPacMan;
        else if(dirPacMan == 'U' && openUp){
            dirMov = 'U';
            tipoMov = 'Y';

        }
        else if(dirPacMan == 'D' && openDo){
            dirMov = 'D';
            tipoMov = 'Y';
        }
    }else if(tipoMov == 'Y'){
        if(notInTrig && (dirPacMan == 'U' || dirPacMan == 'D') ) dirMov = dirPacMan;
        else if(dirPacMan == 'U' && openUp) dirMov = dirPacMan;
        else if(dirPacMan == 'D' && openDo) dirMov = dirPacMan;
        else if(dirPacMan == 'L' && openLe){
            dirMov = 'L';
            tipoMov = 'X';
        }
        else if(dirPacMan == 'R' && openRi){
            dirMov = 'R';
            tipoMov = 'X';
        }
    }

    // dirMov es la diración en la que realemente se está moviendo pacman
    switch(dirMov){
        case 'U':
            pacMan->setPos(pacMan->x(), pacMan->y() - 5);
            break;
        case 'D':
            pacMan->setPos(pacMan->x(), pacMan->y() + 5);
            break;
        case 'L':
            pacMan->setPos(pacMan->x() - 5, pacMan->y());
            break;
        case 'R':
            pacMan->setPos(pacMan->x() + 5, pacMan->y());
            break;
    }

    // Colisiones con los puntos
    for(auto punt : vectPuntos){
        if(pacMan->collidesWithItem(punt)){
            if(punt->isVisible()){
                punt->hide();
                emit emitirS(5);
            }
        }
    }

    //Si el juego se acaba
    if(puntosTot > 1720){
        emit gameOverSig();
    }

}

void MainWindow::aumentarPunt(int addPunt)
{
    puntosTot += addPunt;
    ui->lcdNumber->display(puntosTot);
    std::cout<<puntosTot<<std::endl;
}

void MainWindow::gameOverSlo(){
    gameoverText = new QGraphicsTextItem("GAMEOVER\nGAMEOVER\nGAMEOVER\nGAMEOVER\nGAMEOVER\nGAMEOVER\nGAMEOVER\nGAMEOVER\nGAMEOVER\nGAMEOVER\nGAMEOVER\nGAMEOVER\nGAMEOVER\nGAMEOVER\nGAMEOVER\nGAMEOVER\nGAMEOVER\nGAMEOVER\nGAMEOVER\nGAMEOVER\nGAMEOVER\nGAMEOVER\nGAMEOVER\nGAMEOVER\nGAMEOVER");
    gameoverText->setDefaultTextColor(Qt::red);
    gameoverText->setFont(QFont("Arial", 20));
    gameoverText->setPos(100, -12); // Adjust the position
    gameoverText->setVisible(true);
    escena->addItem(gameoverText);
}




