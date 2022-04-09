#include "Calendar.h"
#include<QDebug>
#include<QTextCodec>
char str[6];
char s[6];
//判断某年某月某日是周几的函数
int CaculateWeekDay(int y, int m, int d)
{
    if (m == 1 || m == 2)
    {
        m += 12;
        y--;
    }
    int iWeek = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400) % 7;
    switch (iWeek)
    {
    case 0: return 1; break;
    case 1: return 2; break;
    case 2: return 3; break;
    case 3: return 4; break;
    case 4: return 5; break;
    case 5: return 6; break;
    case 6: return 7; break;
    }
}
//计算是否是闰年
bool isLoopYaer(int year)
{
    return (((0 == (year % 4)) && (0 != (year % 100))) || (0 == (year % 400)));
}
//计算
int getTotalMonthDays(int year, int month)
{
    int nDays = 0;
    int nLoopDay = isLoopYaer(year) ? 1 : 0;
    switch (month)
    {
    case  1: nDays = 0;            break;
    case  2: nDays = 31;            break;
    case  3: nDays = 59 + nLoopDay; break;
    case  4: nDays = 90 + nLoopDay; break;
    case  5: nDays = 120 + nLoopDay; break;
    case  6: nDays = 151 + nLoopDay; break;
    case  7: nDays = 181 + nLoopDay; break;
    case  8: nDays = 212 + nLoopDay; break;
    case  9: nDays = 243 + nLoopDay; break;
    case 10: nDays = 273 + nLoopDay; break;
    case 11: nDays = 304 + nLoopDay; break;
    case 12: nDays = 334 + nLoopDay; break;
    default: nDays = 0; break;
    }
    return nDays;
}


//计算某月一共有几天
int getMonthDays(int year, int month)
{
    int nDays = 0;
    int nLoopDay = isLoopYaer(year) ? 1 : 0;
    switch (month) {
    case  1: nDays = 31;            break;
    case  2: nDays = 28 + nLoopDay; break;
    case  3: nDays = 31;            break;
    case  4: nDays = 30;            break;
    case  5: nDays = 31;            break;
    case  6: nDays = 30;            break;
    case  7: nDays = 31;            break;
    case  8: nDays = 31;            break;
    case  9: nDays = 30;            break;
    case 10: nDays = 31;            break;
    case 11: nDays = 30;            break;
    case 12: nDays = 31;            break;
    default: nDays = 30;            break;
    }

    return nDays;
}
//计算农历
unsigned int LunarCalendarDay;
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
int MonthAdd[12] = { 0,31,59,90,120,151,181,212,243,273,304,334 };
int LunarCalendar(int year, int month, int day)
{
    int Spring_NY, Sun_NY, StaticDayCount;
    int index, flag;
    //Spring_NY 记录春节离当年元旦的天数。  
    //Sun_NY 记录阳历日离当年元旦的天数。  
    if (((LunarCalendarTable[year - 1901] & 0x0060) >> 5) == 1)
        Spring_NY = (LunarCalendarTable[year - 1901] & 0x001F) - 1;
    else
        Spring_NY = (LunarCalendarTable[year - 1901] & 0x001F) - 1 + 31;
    Sun_NY = MonthAdd[month - 1] + day - 1;
    if ((!(year % 4)) && (month > 2))
        Sun_NY++;
    if (Sun_NY >= Spring_NY)//阳历日在春节后（含春节那天）  
    {
        Sun_NY -= Spring_NY;
        month = 1;
        index = 1;
        flag = 0;
        if ((LunarCalendarTable[year - 1901] & (0x80000 >> (index - 1))) == 0)
            StaticDayCount = 29;
        else
            StaticDayCount = 30;
        while (Sun_NY >= StaticDayCount)
        {
            Sun_NY -= StaticDayCount;
            index++;
            if (month == ((LunarCalendarTable[year - 1901] & 0xF00000) >> 20))
            {
                flag = ~flag;
                if (flag == 0)
                    month++;
            }
            else
                month++;
            if ((LunarCalendarTable[year - 1901] & (0x80000 >> (index - 1))) == 0)
                StaticDayCount = 29;
            else
                StaticDayCount = 30;
        }
        day = Sun_NY + 1;
    }
    else //阳历日在春节前  
    {
        Spring_NY -= Sun_NY;
        year--;
        month = 12;
        if (((LunarCalendarTable[year - 1901] & 0xF00000) >> 20) == 0)
            index = 12;
        else
            index = 13;
        flag = 0;
        if ((LunarCalendarTable[year - 1901] & (0x80000 >> (index - 1))) == 0)
            StaticDayCount = 29;
        else
            StaticDayCount = 30;
        while (Spring_NY > StaticDayCount)
        {
            Spring_NY -= StaticDayCount;
            index--;
            if (flag == 0)
                month--;
            if (month == ((LunarCalendarTable[year - 1901] & 0xF00000) >> 20))
                flag = ~flag;
            if ((LunarCalendarTable[year - 1901] & (0x80000 >> (index - 1))) == 0)
                StaticDayCount = 29;
            else
                StaticDayCount = 30;
        }
        day = StaticDayCount - Spring_NY + 1;
    }
    LunarCalendarDay |= day;
    LunarCalendarDay |= (month << 6);
    if (month == ((LunarCalendarTable[year - 1901] & 0xF00000) >> 20))
        return 1;
    else
        return 0;
}
char* output(int year, int month, int day)
{
    const char* ChDay[] = { "*","初一","初二","初三","初四","初五",
                          "初六","初七","初八","初九","初十",
                          "十一","十二","十三","十四","十五",
                          "十六","十七","十八","十九","二十",
                          "廿一","廿二","廿三","廿四","廿五",
                          "廿六","廿七","廿八","廿九","三十"
    };
    const char* ChMonth[] = { "*","正","二","三","四","五","六","七","八","九","十","十一","腊" };
 
    memset(str, '\0', sizeof(str));
    memset(s, '\0', sizeof(s));
    if (LunarCalendar(year, month, day))
    {
        strcat_s(s, "闰");
        strcat_s(s, ChMonth[(LunarCalendarDay & 0x3C0) >> 6]);
    }
    else
        strcat_s(s, ChMonth[(LunarCalendarDay & 0x3C0) >> 6]);
    //strcat_s(s, "月");
    strcat_s(str, ChDay[LunarCalendarDay & 0x3F]);
    LunarCalendarDay = 0;
    return str;
}
Calendar::Calendar(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    int w = this->width();
    int h = this->height();
    //获取当前年月日
    current_year = QDate::currentDate().year();
    current_month = QDate::currentDate().month();
    current_day = QDate::currentDate().day();
    //初始化数组
    date = new MyLabel * [6];
    for (int i = 0; i < 6; i++)
    {
        date[i] = new MyLabel[7];
    }
    //将星期几打印在最上方
    headLine = new QLabel[7];
    for (int i = 0; i < 7; i++)
    {
        headLine[i].setParent(this);
        headLine[i].resize(w / 10, w / 10);
        headLine[i].move(2 * w / 10 + i * w / 10, w / 20);
        headLine[i].setStyleSheet("QLabel{font-size:30px;}");
        headLine[i].setAlignment(Qt::AlignCenter);

    }
    headLine[1].setText(QString::fromLocal8Bit("周一"));
    headLine[2].setText(QString::fromLocal8Bit("周二"));
    headLine[3].setText(QString::fromLocal8Bit("周三"));
    headLine[4].setText(QString::fromLocal8Bit("周四"));
    headLine[5].setText(QString::fromLocal8Bit("周五"));
    headLine[6].setText(QString::fromLocal8Bit("周六"));
    headLine[0].setText(QString::fromLocal8Bit("周日"));

    bar = new QLabel;
    bar->setParent(this);
    bar->resize(w / 7, w / 10);
    bar->move( w / 2 , 0);
    bar->setText(QString::number(current_year, 10)+ QString::fromLocal8Bit("年") + QString::number(current_month, 10) + QString::fromLocal8Bit("月"));
    bar->setStyleSheet("QLabel{font-size:30px;}");
    bar->setAlignment(Qt::AlignCenter);

    //将数组单元分配到界面上
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            date[i][j].setParent(this);
            date[i][j].resize(w / 10, w / 10);
            date[i][j].move(2 * w / 10 + j * w / 10, w / 10 + i * w / 10);


            //-------第二次迭代新加内容如下------

            connect(&date[i][j], &MyLabel::clicked, this, &Calendar::labelpress);
        }
    }
    //分配按钮
    QPushButton* add = new QPushButton;
    add->setText("-->");
    add->resize(w / 15, w / 15);
    add->setParent(this);
    add->move(0, 0);
    add->setFlat(true);
    QPushButton* sub = new QPushButton;
    sub->setText("<--");
    sub->resize(w / 15, w / 15);
    sub->setParent(this);
    sub->move(0, w / 10);
    sub->setFlat(true);
    connect(add, &QPushButton::clicked, this, &Calendar::addMonth);
    connect(sub, &QPushButton::clicked, this, &Calendar::subMonth);
    //刷新日历数据
    initWidget();


     //-------第二次迭代新加内容如下------
    schedule_window.hide();  
    connect(&schedule_window, &schedule::sendOK, this, &Calendar::reciveOK);
    connect(this, &Calendar::sendto_schdule, &schedule_window, &schedule::receive_frommain);
    ifstream a;
    a.open("daily.txt");
    string s1 = "";
    string s2 = "";
    int k = 0;
    while (a >> s1 && a >> s2)
    {
        t.insert(pair<string, string>(s1.substr(1), s2.substr(1)));
    }
    a.close();
    //-------第二次迭代新加内容如上------

}
Calendar::~Calendar()
{
    for (int i = 0; i < 6; i++)
    {
        delete[]date[i];
    }
    delete[]date;
    delete[]headLine;
}


void  Calendar::initWidget()
{
    bar->setText(QString::number(current_year, 10) + QString::fromLocal8Bit("年") + QString::number(current_month, 10) + QString::fromLocal8Bit("月"));
    //QTextCodec* codec = QTextCodec::codecForLocale();
    QString a;
    //计算该月的第一天是星期几
    int firweek = CaculateWeekDay(current_year, current_month, 1);
    int lastMonthDay;
    //计算上个月有几天
    if (current_month == 1)
    {
        lastMonthDay = getMonthDays(current_year - 1, 12);
    }
    else
    {
        lastMonthDay = getMonthDays(current_year, current_month - 1);
    }
    int currentMonthDay = getMonthDays(current_year, current_month);
    int total = 1;

    if (firweek == 1)
    {
        //显示上个月的天数
        for (int i = 6; i >= 0; i--)
        {
            if (current_month == 1)
            {

                //--------第二次迭代内容如下------
                date[0][i].setDate(current_year - 1, 12, lastMonthDay);
                //---------第二次迭代内容如上------
                
                
                date[0][i].setText(QString::number(lastMonthDay--, 10) + "\n" + QString::fromLocal8Bit(output(current_year - 1, 12, lastMonthDay)));
             

            }
            else
            {
                //--------第二次迭代内容如下------
                date[0][i].setDate(current_year, current_month - 1, lastMonthDay);
             //---------第二次迭代内容如上------

                date[0][i].setText(QString::number(lastMonthDay--, 10) + "\n" + QString::fromLocal8Bit(output(current_year, current_month - 1, lastMonthDay)));
              
            }

        }
        //显示当前月天数
        int i = 1; int j = 0;
        while (total <= currentMonthDay)
        {
            //--------第二次迭代内容如下------
            date[i][j].setDate(current_year, current_month - 1, total);
            //---------第二次迭代内容如上------

            date[i][j++].setText(QString::number(total++, 10) + "\n" + QString::fromLocal8Bit(output(current_year, current_month - 1, total)));

            if (j == 7)
            {
                i++;
                j = 0;
            }

        }
        total = 1;
        //显示下一个月
        while (i < 6)
        {
            if (current_month == 12)
            {
                //--------第二次迭代内容如下------
                date[i][j].setDate(current_year + 1, 1, total);
                //---------第二次迭代内容如上------


                date[i][j++].setText(QString::number(total++, 10) + "\n" + QString::fromLocal8Bit(output(current_year + 1, 1, total)));
            }
            else
            {
                //--------第二次迭代内容如下------
                date[i][j].setDate(current_year, current_month + 1, total);
                //---------第二次迭代内容如上------


                date[i][j++].setText(QString::number(total++, 10) + "\n" + QString::fromLocal8Bit(output(current_year, current_month+1, total)));
            }
            if (j == 7)
            {
                i++;
                j = 0;
            }

        }
    }
    else
    {
        for (int i = firweek - 1; i >= 0; i--)
        {
            if (current_month == 1)
            {
                //--------第二次迭代内容如下------
                date[0][i].setDate(current_year - 1, 12, lastMonthDay);
                //---------第二次迭代内容如上------


                date[0][i].setText(QString::number(lastMonthDay--, 10) + "\n" + QString::fromLocal8Bit(output(current_year-1, 12, lastMonthDay)));
            }
            else
            {
                //--------第二次迭代内容如下------
                date[0][i].setDate(current_year, current_month - 1, lastMonthDay);
                //---------第二次迭代内容如上------

                date[0][i].setText(QString::number(lastMonthDay--, 10) + "\n" + QString::fromLocal8Bit(output(current_year, current_month - 1, lastMonthDay)));
            }
           
        }
        //显示当前月
        for (int i = firweek; i < 7; i++)
        {
            date[0][i].setText(QString::number(total++, 10) + "\n" + QString::fromLocal8Bit(output(current_year, current_month, total)));
            if (QDate::currentDate().day() == total)
            {
                date[0][i].setStyleSheet("QLabel{color:rgba(255, 0, 0, 255);font-size:30px;}");
            }
        }
        int i = 1; int j = 0;
        while (total <= currentMonthDay)
        {
            //--------第二次迭代内容如下------
            date[i][j].setDate(current_year, current_month, total);
            //---------第二次迭代内容如上------

            date[i][j++].setText(QString::number(total++, 10) + "\n" + QString::fromLocal8Bit(output(current_year, current_month, total)));
           
            if (j == 7)
            {
                i++;
                j = 0;
            }

        }
        total = 1;
        //显示下一个月
        while (i < 6)
        {
            if (current_month == 12)
            {
                //--------第二次迭代内容如下------
                date[i][j].setDate(current_year + 1, 1, total);
                //---------第二次迭代内容如上------


                date[i][j++].setText(QString::number(total++, 10) + "\n" + QString::fromLocal8Bit(output(current_year+1, 1, total)));
            }
            else
            {
                //--------第二次迭代内容如下------
                date[i][j].setDate(current_year, current_month + 1, total);
                //---------第二次迭代内容如上------


                date[i][j++].setText(QString::number(total++, 10) + "\n" + QString::fromLocal8Bit(output(current_year, current_month+1, total)));
            }         
            if (j == 7)
            {
                i++;
                j = 0;
            }
        }
    }
}
void Calendar::addMonth()
{
    if (this->current_month == 12)
    {
        this->current_month = 1;
        this->current_year++;
        initWidget();
        return;
    }
    this->current_month++;
    initWidget();
}
void Calendar::subMonth()
{
    if (this->current_month == 1)
    {
        this->current_month = 12;
        this->current_year--;
        initWidget();
        return;
    }
    this->current_month--;
    initWidget();
}

//第二次迭代内容如下------
void Calendar::labelpress(int y, int m, int d)
{
    string ymd = to_string(y);
    if (m < 10)
    {
        ymd += "0";
        ymd+= to_string(m);
    }
    else
    {
        ymd += to_string(m);
    }
    if (d < 10)
    {
        ymd += "0";
        ymd += to_string(d);
    }
    else
    {
        ymd += to_string(d);
    }
    map<string, string>::iterator iter = t.find(ymd);
    //找到
    string s = "";
    if (iter != t.end()) 
    {      
        s = iter->second;
    }
    emit(sendto_schdule(s));   
    this->hide();
    schedule_window.move(300, 300);
    schedule_window.show();
   
}
void Calendar::reciveOK()
{
    this->show();

};