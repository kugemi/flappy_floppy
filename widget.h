#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "scene.h"
#include "tower.h"
#include "floppy.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_startButton_clicked();

    void on_slowButton_clicked();

    void on_normalButton_clicked();

    void on_fastButton_clicked();

private:
    Ui::Widget *ui;

    Scene *scene;
    floppy *flopp;
};
#endif // WIDGET_H
