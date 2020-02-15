#ifndef TOWER_H
#define TOWER_H

#include <QGraphicsItemGroup>
#include <QGraphicsPixmapItem>
#include <QPropertyAnimation>

class tower : public QObject,  public QGraphicsItemGroup
{
    Q_OBJECT
    Q_PROPERTY(qreal x READ x WRITE setX)
public:
    explicit tower(int xAnimDuration = 2000);
    ~tower();

    qreal x() const;

    void stopSpawn();

    int xAnimDur;

    int getXAnimDur() const;
    void setXAnimDur(int value);



signals:
    void collideFail();

public slots:

    void setX(qreal x);

private:
    bool collision();


    QGraphicsPixmapItem *bottomTower;
    QPropertyAnimation *xAnim;

    int yPos;

    qreal m_x;

    bool behindTow;

    QGraphicsPixmapItem *topTower;
};

#endif // TOWER_H
