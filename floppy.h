#ifndef FLOPPY_H
#define FLOPPY_H


#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPropertyAnimation>
#include <QDebug>

class floppy : public QObject,  public QGraphicsPixmapItem
{
    Q_OBJECT
    Q_PROPERTY(qreal rotation READ rotation WRITE setRotation)
    Q_PROPERTY(qreal y READ y WRITE setY)
public:
    explicit floppy(QPixmap pixmap);

    qreal rotation() const;

    qreal y() const;

    void takeOff();

    int yAnimDur1;
    int yAnimDur2;
    int rotAnimDur1;
    int rotAnimDur2;


    int getYAnimDur1() const;
    void setYAnimDur1(int value);

    int getYAnimDur2() const;
    void setYAnimDur2(int value);

    int getRotAnimDur1() const;
    void setRotAnimDur1(int value);

    int getRotAnimDur2() const;
    void setRotAnimDur2(int value);

public slots:
    void setRotation(qreal rotation);

    void setY(qreal y);

    void rotateTo(const qreal &end, const int& duration, const QEasingCurve& curve);

    void floppyFall();

    void startFly();

    void stopFly();

signals:

private:
    enum WingPos
    {
        up,
        mid,
        down
    };
    void updatePixmap();

    WingPos wingPos;
    bool wingDirection; //0 down
    qreal m_rotation;
    qreal m_y;
    QPropertyAnimation *yAnim;
    QPropertyAnimation *rotAnim;
};


#endif // FLOPPY_H
