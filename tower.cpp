#include "tower.h"
#include "floppy.h"
#include "scene.h"
#include <QRandomGenerator>
#include <QGraphicsScene>

tower::tower(int xAnimDuration):
    xAnimDur(xAnimDuration),
    topTower(new QGraphicsPixmapItem(QPixmap(":/images/tower.png"))),
    bottomTower(new QGraphicsPixmapItem(QPixmap(":/images/tower.png"))),
    behindTow(false)
{

    yPos = QRandomGenerator::global()->bounded(160);

    topTower->setPos(445, -550 + yPos);
    bottomTower->setPos(445, 390 + yPos);

    xAnim = new QPropertyAnimation(this, "x", this);
    xAnim->setStartValue(650);
    xAnim->setEndValue(0);
    xAnim->setEasingCurve(QEasingCurve::Linear);
    xAnim->setDuration(xAnimDur);

    connect(xAnim, &QPropertyAnimation::finished,[=]{
        scene()->removeItem(this);
        delete this;
    });

    xAnim->start();

    addToGroup(topTower);
    addToGroup(bottomTower);
}

tower::~tower()
{
    delete topTower;
    delete bottomTower;
}

qreal tower::x() const
{
    return m_x;
}

void tower::stopSpawn()
{
    xAnim->stop();
}

int tower::getXAnimDur() const
{
    return xAnimDur;
}

void tower::setXAnimDur(int value)
{
    xAnimDur = value;
}

void tower::setX(qreal x)
{
    m_x = x;

    if (x < 165 && !behindTow)
    {
        behindTow = true;
        QGraphicsScene *mScene = scene();
        Scene *myScene = dynamic_cast<Scene*>(mScene);
        if(myScene)
        {
            myScene->incrementScore();
        }
    }

    if (collision())
        emit collideFail();

    setPos(x, yPos);

}

bool tower::collision()
{
    QList<QGraphicsItem*> collidedItems = topTower->collidingItems();
    collidedItems.append(bottomTower->collidingItems());

    foreach (QGraphicsItem *item, collidedItems)
    {
        floppy *flopp = dynamic_cast<floppy*>(item);
        if(flopp)
            return true;
    }
    return false;
}
