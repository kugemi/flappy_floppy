#include "floppy.h"
#include <QTimer>
#include <QDebug>


floppy::floppy(QPixmap pixmap):
    yAnimDur1(1000), yAnimDur2(250), rotAnimDur1(200), rotAnimDur2(1150),
    wingPos(WingPos::up),
    wingDirection(1)
{
    m_y = 0;
    m_rotation = 0;
    setPixmap(pixmap);

    QTimer *wingTimer = new QTimer(this);
    connect(wingTimer,&QTimer::timeout,[=](){
        updatePixmap();
    });

    wingTimer->start(80);




    yAnim = new QPropertyAnimation(this,"y",this);
    yAnim->setStartValue(405);
    yAnim->setEndValue(770);
    yAnim->setEasingCurve(QEasingCurve::InQuad);
    yAnim->setDuration(yAnimDur1);

    //yAnim->start();

    rotAnim = new QPropertyAnimation(this,"rotation",this);
    //rotateTo(90, 1150, QEasingCurve::InQuad);
}

qreal floppy::rotation() const
{
    return m_rotation;
}

qreal floppy::y() const
{
    return m_y;
}



void floppy::takeOff()
{
    yAnim->stop();
    rotAnim->stop();

    qreal curY = y();
    yAnim->setStartValue(curY);
    yAnim->setEndValue(curY - 100);
    yAnim->setEasingCurve(QEasingCurve::OutQuad);
    yAnim->setDuration(yAnimDur2);

    connect(yAnim,&QPropertyAnimation::finished,[=](){
        floppyFall();
    });

    yAnim->start();

    rotateTo(-30, rotAnimDur1, QEasingCurve::OutQuad);
}

int floppy::getRotAnimDur2() const
{
    return rotAnimDur2;
}

void floppy::setRotAnimDur2(int value)
{
    rotAnimDur2 = value;
}

int floppy::getRotAnimDur1() const
{
    return rotAnimDur1;
}

void floppy::setRotAnimDur1(int value)
{
    rotAnimDur1 = value;
}

int floppy::getYAnimDur2() const
{
    return yAnimDur2;
}

void floppy::setYAnimDur2(int value)
{
    yAnimDur2 = value;
}

int floppy::getYAnimDur1() const
{
    return yAnimDur1;
}

void floppy::setYAnimDur1(int value)
{
    yAnimDur1 = value;
}

void floppy::setRotation(qreal rotation)
{
    m_rotation = rotation;

    QPointF c = boundingRect().center();

    QTransform t;

    t.translate(c.x(), c.y());
    t.rotate(rotation);
    t.translate(-c.x(), -c.y());
    setTransform(t);
}

void floppy::setY(qreal y)
{
    moveBy(0,y-m_y);
    m_y = y;
}

void floppy::rotateTo(const qreal &end, const int &duration, const QEasingCurve &curve)
{
    rotAnim->setStartValue(rotation());
    rotAnim->setEndValue(end);
    rotAnim->setEasingCurve(curve);
    rotAnim->setDuration(duration);

    rotAnim->start();
}

void floppy::floppyFall()
{
    //QPointF c = boundingRect().topLeft();
    if (y() < 770)
    {

        rotAnim->stop();
        yAnim->stop();

        yAnim->setStartValue(y());
        yAnim->setEndValue(770);
        yAnim->setEasingCurve(QEasingCurve::InQuad);
        yAnim->setDuration(yAnimDur1);
        //qDebug() << "pos: " << y();



        yAnim->start();

        rotateTo(90, rotAnimDur2, QEasingCurve::InQuad);
    }
}

void floppy::startFly()
{
    yAnim->start();
    rotateTo(90, rotAnimDur2, QEasingCurve::InQuad);
}

void floppy::stopFly()
{
    yAnim->stop();
    rotAnim->stop();
}

void floppy::updatePixmap()
{
    if (wingPos == WingPos::mid)
    {
        if (wingDirection)
        {
            setPixmap(QPixmap(":/images/floppy_up.png"));
            wingPos = WingPos::up;
            wingDirection = 0;
        }
        else
        {
            setPixmap(QPixmap(":/images/floppy_down.png"));
            wingPos = WingPos::down;
            wingDirection = 1;
        }
    }
    else
    {
        setPixmap(QPixmap(":/images/floppy_mid.png"));
        wingPos = WingPos::mid;
    }
}
