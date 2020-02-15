/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGraphicsView *graphicsView;
    QPushButton *startButton;
    QPushButton *slowButton;
    QPushButton *normalButton;
    QPushButton *fastButton;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(449, 845);
        graphicsView = new QGraphicsView(Widget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 455, 805));
        startButton = new QPushButton(Widget);
        startButton->setObjectName(QString::fromUtf8("startButton"));
        startButton->setGeometry(QRect(10, 810, 151, 31));
        slowButton = new QPushButton(Widget);
        slowButton->setObjectName(QString::fromUtf8("slowButton"));
        slowButton->setGeometry(QRect(200, 810, 71, 31));
        normalButton = new QPushButton(Widget);
        normalButton->setObjectName(QString::fromUtf8("normalButton"));
        normalButton->setGeometry(QRect(280, 810, 71, 31));
        fastButton = new QPushButton(Widget);
        fastButton->setObjectName(QString::fromUtf8("fastButton"));
        fastButton->setGeometry(QRect(360, 810, 71, 31));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        startButton->setText(QCoreApplication::translate("Widget", "Start Game", nullptr));
        slowButton->setText(QCoreApplication::translate("Widget", "slow", nullptr));
        normalButton->setText(QCoreApplication::translate("Widget", "normal", nullptr));
        fastButton->setText(QCoreApplication::translate("Widget", "fast", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
