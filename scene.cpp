#include "scene.h"
#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>
#include <QDebug>

Scene::Scene(QObject *parent) : QGraphicsScene(parent),
  gameOn(false),
  score(0), bestScore(0),
  towTimerValue(1000),
  finalScore(nullptr),
  xAnimDur(2000)

{
    setUpTowerTimer();
}

void Scene::floppyShow()
{
    flopp = new floppy(QPixmap(":/images/floppy_up.png"));
    addItem(flopp);
    flopp->setY(405);
}

void Scene::startGame()
{
    if (!towTimer->isActive())
    {
        cleanTower();
        setGameOn(true);  
        setScore(0);
        hideOverMess();
        curScore = new QGraphicsTextItem();
        addItem(curScore);
        towTimer->start(towTimerValue);
    }

    flopp->startFly();
}

void Scene::setUpTowerTimer()
{
    towTimer = new QTimer(this);
    connect(towTimer, &QTimer::timeout, [=](){
        tower *tow = new tower(xAnimDur);
        connect(tow,&tower::collideFail,[=]{
            towTimer->stop();
            freezeAll();
            setGameOn(false);
            gameOverMess();
        });

        addItem(tow);
    });

}

void Scene::freezeAll()
{
    flopp->stopFly();

    QList<QGraphicsItem*> sceneItems = items();
    foreach (QGraphicsItem *item, sceneItems)
    {
        tower *tow = dynamic_cast<tower*>(item);
        if (tow)
            tow->stopSpawn();
    }
}

void Scene::cleanTower()
{
    QList<QGraphicsItem*> sceneItems = items();
    foreach (QGraphicsItem *item, sceneItems)
    {
        tower *tow = dynamic_cast<tower*>(item);
        if (tow)
        {
            removeItem(tow);
            delete tow;
        }
    }
}

void Scene::gameOverMess()
{
    finalScore = new QGraphicsTextItem();

    QString htmlString = "<p> Score : " + QString::number(score) + "</p>"
            + "<p> Best Score : " + QString::number(bestScore) + "</p>";

    QFont mFont("Consolas", 30, QFont::Bold);

    finalScore->setHtml(htmlString);
    finalScore->setFont(mFont);
    finalScore->setDefaultTextColor(Qt::blue);
    addItem(finalScore);

    finalScore->setPos(65,300);
}

void Scene::hideOverMess()
{
    if (finalScore)
    {
        removeItem(finalScore);
        delete finalScore;
        finalScore = nullptr;
        removeItem(curScore);
        delete curScore;
        curScore = nullptr;
    }
}

void Scene::currentScore()
{
    QString htmlString = QString::number(score);

    QFont mFont("Consolas", 30, QFont::Bold);

    curScore->setHtml(htmlString);
    curScore->setFont(mFont);
    curScore->setDefaultTextColor(Qt::blue);


    curScore->setPos(220, 80);
}

int Scene::getTowTimerValue() const
{
    return towTimerValue;
}

void Scene::setTowTimerValue(int value)
{
    towTimerValue = value;
}



int Scene::getXAnimDur() const
{
    return xAnimDur;
}

void Scene::setXAnimDur(int value)
{
    xAnimDur = value;
}

int Scene::getScore() const
{
    return score;
}

void Scene::setScore(int value)
{
    score = value;
}

bool Scene::getGameOn() const
{
    return gameOn;
}

void Scene::setGameOn(bool value)
{
    gameOn = value;
}

void Scene::incrementScore()
{
    score++;
    if (score > bestScore)
        bestScore = score;
    qDebug() << "score: " << score;
    currentScore();
}

void Scene::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Space)
    {
        if (gameOn)
            flopp->takeOff();
    }
    QGraphicsScene::keyPressEvent(event);
}

void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        if (gameOn)
            flopp->takeOff();
    }
    QGraphicsScene::mousePressEvent(event);
}
