﻿#pragma once
#include <QtWidgets/QMainWindow>
#include <QDate>
#include<QLabel>
#include<QPushButton>
#include<QTextEdit>
#include<QDebug>
#include<QFile>
#include<QTimer>
#include<QPainter>
#include<QtCore5Compat/QTextCodec>
#include "ui_Calendar.h"
#include"todolist.h"
#include"MyLabel.h"
#include"expr.h"
#include"forget.h"
#include"DailypicLabel.h"
#include"schedule.h"
#include"widget.h"
#include"Daily.h"
#include"answerwidget.h"
#include"eatthing.h"
#include"Drink.h"
//窗口类2
class Calendar : public QMainWindow
{
    Q_OBJECT
public:
    Calendar(QWidget *parent = Q_NULLPTR);//构造
    ~Calendar();//析构
    void  initWidget();//初始化窗口
    void addMonth();
    void subMonth();
    bool isLoopYaer(int);
    int getTotalMonthDays(int , int);
    int CaculateWeekDay(int, int, int);
    char* output(int , int , int );
    int LunarCalendar(int, int, int);
    int getMonthDays(int, int);
    void UpdateSaying();
    void ts();
    void sx();
    void wit();
    //查看日程
    void labelpress(int y, int m, int d);
    void reciveOK(string s);
    //添加日程
    void show_adddaily();
    //记账
    void show_addzhang();
 
    void show_dailyhealth();
    void show_whateat();
    void show_whatans();
    void paintEvent(QPaintEvent *);
public  slots:
    void picshow();
    void picclose();
signals:
    void sendto_schdule(string s);
    void sendwhto_schdule(int w, int h);

private:
    //Ui::CalendarClass ui;
    QTimer* timer = new QTimer(this);//计时器
    QtWidgetsClass* a = new QtWidgetsClass;//子窗口用于显示todolist
    Widget* w=new Widget;//备忘录窗口
    expr* calculator =new expr;//计算器窗口
    Daily* daily;//添加日程窗口
    Drink* drinkwidget;
    zhangWidget* jizhang;
    QWidget* picture;
    AnswerWidget* answerwidget;
    eatthing* eatwidget;
    //图片
    DailyLabel* Dailytpic;
    //当前年月日---------
    int current_year; //当前年
    int current_month;//当前月
    int current_day;//当前日
    //日期数组（6行7列）---------
    MyLabel** date;//数据label
    QLabel* headLine;//星期label
    QLabel* bar;//当前月份label
    //每日内容
    QString saying[200];
    QString word[10];
    //todolist
    QPushButton* Todo;
    //备忘录
    QPushButton* waiting;
    //查看日程
    map<string, string>t;
    schedule schedule_window;
    //添加日程
    QPushButton* adddaily;
    //添加记账
    QPushButton* addzhang;
    //计算器
    QPushButton* Calculator;
    //今天吃什么
    QPushButton* Whateat;
    // 答案之镜
    QPushButton* Whatans;
    // 每日健康
    QPushButton* dailyhealth;
    //拆分农历时使用
    char str[14];
    char s[14];
    unsigned int LunarCalendarDay=0;
    int MonthAdd[12] = { 0,31,59,90,120,151,181,212,243,273,304,334 };
    unsigned int LunarCalendarTable[199] =
    {
    0x04AE53,0x0A5748,0x5526BD,0x0D2650,0x0D9544,0x46AAB9,0x056A4D,0x09AD42,0x24AEB6,0x04AE4A
    ,/*1901-1910*/
    0x6A4DBE,0x0A4D52,0x0D2546,0x5D52BA,0x0B544E,0x0D6A43,0x296D37,0x095B4B,0x749BC1,0x049754
    ,/*1911-1920*/
    0x0A4B48,0x5B25BC,0x06A550,0x06D445,0x4ADAB8,0x02B64D,0x095742,0x2497B7,0x04974A,0x664B3E
    ,/*1921-1930*/
    0x0D4A51,0x0EA546,0x56D4BA,0x05AD4E,0x02B644,0x393738,0x092E4B,0x7C96BF,0x0C9553,0x0D4A48
    ,/*1931-1940*/
    0x6DA53B,0x0B554F,0x056A45,0x4AADB9,0x025D4D,0x092D42,0x2C95B6,0x0A954A,0x7B4ABD,0x06CA51
    ,/*1941-1950*/
    0x0B5546,0x555ABB,0x04DA4E,0x0A5B43,0x352BB8,0x052B4C,0x8A953F,0x0E9552,0x06AA48,0x6AD53C
    ,/*1951-1960*/
    0x0AB54F,0x04B645,0x4A5739,0x0A574D,0x052642,0x3E9335,0x0D9549,0x75AABE,0x056A51,0x096D46
    ,/*1961-1970*/
    0x54AEBB,0x04AD4F,0x0A4D43,0x4D26B7,0x0D254B,0x8D52BF,0x0B5452,0x0B6A47,0x696D3C,0x095B50
    ,/*1971-1980*/
    0x049B45,0x4A4BB9,0x0A4B4D,0xAB25C2,0x06A554,0x06D449,0x6ADA3D,0x0AB651,0x093746,0x5497BB
    ,/*1981-1990*/
    0x04974F,0x064B44,0x36A537,0x0EA54A,0x86B2BF,0x05AC53,0x0AB647,0x5936BC,0x092E50,0x0C9645
    ,/*1991-2000*/
    0x4D4AB8,0x0D4A4C,0x0DA541,0x25AAB6,0x056A49,0x7AADBD,0x025D52,0x092D47,0x5C95BA,0x0A954E
    ,/*2001-2010*/
    0x0B4A43,0x4B5537,0x0AD54A,0x955ABF,0x04BA53,0x0A5B48,0x652BBC,0x052B50,0x0A9345,0x474AB9
    ,/*2011-2020*/
    0x06AA4C,0x0AD541,0x24DAB6,0x04B64A,0x69573D,0x0A4E51,0x0D2646,0x5E933A,0x0D534D,0x05AA43
    ,/*2021-2030*/
    0x36B537,0x096D4B,0xB4AEBF,0x04AD53,0x0A4D48,0x6D25BC,0x0D254F,0x0D5244,0x5DAA38,0x0B5A4C
    ,/*2031-2040*/
    0x056D41,0x24ADB6,0x049B4A,0x7A4BBE,0x0A4B51,0x0AA546,0x5B52BA,0x06D24E,0x0ADA42,0x355B37
    ,/*2041-2050*/
    0x09374B,0x8497C1,0x049753,0x064B48,0x66A53C,0x0EA54F,0x06B244,0x4AB638,0x0AAE4C,0x092E42
    ,/*2051-2060*/
    0x3C9735,0x0C9649,0x7D4ABD,0x0D4A51,0x0DA545,0x55AABA,0x056A4E,0x0A6D43,0x452EB7,0x052D4B
    ,/*2061-2070*/
    0x8A95BF,0x0A9553,0x0B4A47,0x6B553B,0x0AD54F,0x055A45,0x4A5D38,0x0A5B4C,0x052B42,0x3A93B6
    ,/*2071-2080*/
    0x069349,0x7729BD,0x06AA51,0x0AD546,0x54DABA,0x04B64E,0x0A5743,0x452738,0x0D264A,0x8E933E
    ,/*2081-2090*/
    0x0D5252,0x0DAA47,0x66B53B,0x056D4F,0x04AE45,0x4A4EB9,0x0A4D4C,0x0D1541,0x2D92B5
     /*2091-2099*/
    };
};
