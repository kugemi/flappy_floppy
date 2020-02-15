#include "widget.h"
#include "ui_widget.h"
#include <QGraphicsPixmapItem>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    scene = new Scene(this);
    scene->setSceneRect(0, 0, 450, 800);

    QGraphicsPixmapItem *pixItem = new QGraphicsPixmapItem(QPixmap(":/images/background.png"));
    scene->addItem(pixItem);


    ui->graphicsView->setScene(scene);

    scene->floppyShow();
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_startButton_clicked()
{
    scene->startGame();
}

void Widget::on_slowButton_clicked()
{
//    flopp->setYAnimDur1(30000);
//    flopp->setYAnimDur2(7500);
//    flopp->setRotAnimDur1(6000);
//    flopp->setRotAnimDur2(34500);
    scene->setXAnimDur(6000);
    scene->setTowTimerValue(3000);
}

void Widget::on_normalButton_clicked()
{
//    flopp->setYAnimDur1(1000);
//    flopp->setYAnimDur2(250);
//    flopp->setRotAnimDur1(200);
//    flopp->setRotAnimDur2(1150);
    scene->setXAnimDur(2000);
    scene->setTowTimerValue(1000);
}

void Widget::on_fastButton_clicked()
{
//    flopp->setYAnimDur1(500);
//    flopp->setYAnimDur2(125);
//    flopp->setRotAnimDur1(100);
//    flopp->setRotAnimDur2(675);
    scene->setXAnimDur(1000);
    scene->setTowTimerValue(500);
}
