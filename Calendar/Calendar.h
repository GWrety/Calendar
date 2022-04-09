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
//������
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

    //-------�ڶ��ε����¼���������------

    void labelpress(int y, int m,int d);
    void reciveOK();

private:

    Ui::CalendarClass ui;
    //��ǰ������---------
    int current_year; 
    int current_month;
    int current_day;
    //�������飨6��7�У�---------
    MyLabel** date;
    QLabel* headLine;
    QLabel* bar;


    //-------�ڶ��ε����¼���������------
    map<string,string>t;
    
    schedule schedule_window;

signals:
    void sendto_schdule(string s);

protected:

   
  

};
