#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Calendar.h"
#include <QDate>
#include<QLabel>
#include<QPushButton>
#include<QMap>
#include"MyLabel.h"
#include<fstream>
#include"schedule.h"


using namespace std;
//窗口类
class Calendar : public QMainWindow
{
    Q_OBJECT

public:
    Calendar(QWidget *parent = Q_NULLPTR);
    ~Calendar();
    void showCalendar();
    void  initWidget();
    void addMonth();
    void subMonth();

    //-------第二次迭代新加内容如下------

    void labelpress(int y, int m,int d);
    void reciveOK();

private:

    Ui::CalendarClass ui;
    //当前年月日---------
    int current_year; 
    int current_month;
    int current_day;
    //日期数组（6行7列）---------
    MyLabel** date;
    QLabel* headLine;
    QLabel* bar;


    //-------第二次迭代新加内容如下------
    map<string,string>t;
    
    schedule schedule_window;

signals:
    void sendto_schdule(string s);

protected:

   
  

};
