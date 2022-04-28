#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Drink.h"
#include<QPainter>
#include<fstream>
#include<QDate>
using namespace std;
class Drink : public QMainWindow
{
    Q_OBJECT

public:
    Drink(QWidget *parent = Q_NULLPTR);
    ~Drink();
    void drink_cli();
    void more_cli();
    void make_cli();
   
    int time=5;//间隔时间
    int allneed=2400;  //总共喝水量
    int once=500;  //一杯喝水量
    int havedrunk = 0;
    int m_persent = 0;
    int weight = 60;
    FILE* file=NULL;
private:
    Ui::DrinkClass ui;
signals:
    void sendTime(int time);
protected:
    void paintEvent(QPaintEvent*);
public slots:
    void time_change(int index);
};
