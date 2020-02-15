#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QTimer>
#include "tower.h"
#include "floppy.h"

class Scene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit Scene(QObject *parent = nullptr);

    void floppyShow();

    void startGame();

    bool getGameOn() const;
    void setGameOn(bool value);

    void incrementScore();

    int getScore() const;
    void setScore(int value);

    int towTimerValue;

    int getTowTimerValue() const;
    void setTowTimerValue(int value);

    QTimer *towTimer;


    int xAnimDur;

    int getXAnimDur() const;
    void setXAnimDur(int value);

signals:

private:
    void setUpTowerTimer();

    void freezeAll();

    void cleanTower();

    void gameOverMess();
    void hideOverMess();

    void currentScore();

    floppy *flopp;

    bool gameOn;

    int score;
    int bestScore;

    QGraphicsTextItem *finalScore;
    QGraphicsTextItem *curScore;




    // QGraphicsScene interface
protected:
    void keyPressEvent(QKeyEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // SCENE_H
