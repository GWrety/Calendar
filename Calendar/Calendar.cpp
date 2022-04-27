#include "Calendar.h"
Calendar::Calendar(QWidget* parent)
    : QMainWindow(parent)
{
    //ui.setupUi(this);
    this->resize(800, 600);
    int w = this->width();
    int h = this->height();
    //主界面白色
    this->setStyleSheet("background-color:rgb(192,142,175)");
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
        headLine[i].resize(w / 10, h / 10);
        headLine[i].move(15 * w / 100 + i * w / 10, 3 * h / 10);
        headLine[i].setStyleSheet("QLabel{color:rgb(255,254,250);font-size:25px;background-color:rgb(254,204,17);border-radius:13px;border:1px solid Black;}");
        headLine[i].setAlignment(Qt::AlignCenter);
    }
    headLine[1].setText("周一");
    headLine[2].setText("周二");
    headLine[3].setText("周三");
    headLine[4].setText("周四");
    headLine[5].setText("周五");
    headLine[6].setText("周六");
    headLine[0].setText("周日");
    
    bar = new QLabel(this);
    bar->resize(4 * w / 10, 15 * h / 100);
    bar->move(3 * w / 10, 15 * h / 100);
    bar->setText(QString::number(current_year, 10) + QString::fromLocal8Bit("年") + QString::number(current_month, 10) + QString::fromLocal8Bit("月"));
    bar->setStyleSheet("QLabel{color:rgb(255,254,250);font-size:40px;background-color:rgb(254,204,17);border-radius:13px;border:1px solid Black;}");
    bar->setAlignment(Qt::AlignCenter);

    //分配按钮
    QPushButton* add = new QPushButton(this);
    QIcon  t2;
    t2.addFile(":/Calendar/right.png");
    add->setIcon(t2);
    add->setIconSize(QSize(w / 10, 15 * h / 100));
    add->resize(1 * w / 10, 15 * h / 100);
    add->move(7* w / 10, 15 * h / 100);
    add->setStyleSheet("QPushButton{background-color:rgb(249,210,125);border-radius:13px;border:1px solid Black;}"
        "QPushButton:hover{background-color:rgb(252,183,10);border-radius:20px;border:1px solid Black;}"
        );
    add->setFlat(true);
    QPushButton* sub = new QPushButton(this);
    QIcon  t3;
    t3.addFile(":/Calendar/left.png");
    sub->setIcon(t3);
    sub->setIconSize(QSize(w / 10, 15 * h / 100));
    sub->resize(1 * w / 10, 15*h / 100);
    sub->move(2*w/10, 15 * h / 100);
    sub->setStyleSheet("QPushButton{background-color:rgb(249,210,125);border-radius:13px;border:1px solid Black;}"
        "QPushButton:hover{background-color:rgb(252,183,10);border-radius:20px;border:1px solid Black;}");
    sub->setFlat(true);
    connect(add, &QPushButton::clicked, this, &Calendar::addMonth);
    connect(sub, &QPushButton::clicked, this, &Calendar::subMonth);


    //将数组单元分配到界面上
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            date[i][j].setParent(this);
            date[i][j].resize(w / 10, h / 10);
            date[i][j].move(15 * w / 100 + j * w / 10, 4 * h / 10 + i * h / 10);
            connect(&date[i][j], &MyLabel::clicked, this, &Calendar::labelpress);
        }
    }
    QIcon  t1;
    t1.addFile(":/Calendar/day.png");
    this->setWindowIcon(t1);
    //查看日程
    schedule_window.hide();
    schedule_window.setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowMinimizeButtonHint);
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
    //schedule_window.setParent(this);
    connect(this, &Calendar::sendwhto_schdule, &schedule_window, &schedule::receivewh_frommain);
    emit(sendwhto_schdule(w, h));
    //schedule_window.move( w / 4,4*h / 10);
    a.close();
   
    QFile  file1("saying.txt");
    if (!file1.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << 1;
    }
    QFile  file2("word.txt");
    if (!file2.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << 1;
    }
    char* temp = new char[200];
    for (int i = 0; i < 130; ++i) {
        file1.readLine(temp, 200);
        saying[i] = QString(temp);
    }
    delete[]temp;

    QTime current = QTime::currentTime();
    srand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
    int b = rand() % 130;   //随机生成0到9的随机数
    if (b % 2) {
        if (b != 129)b--;
        else {
            b = 0;
        }
    }
    picture = new QWidget;
    picture->setParent(this);
    picture->setStyleSheet("border-image:url(:/Calendar/pic.jpg)");
    picture->resize(w, 90 * h / 100);
    picture->move(0, 10 * h / 100);
    picture->hide();

    Dailytpic = new DailyLabel;
    Dailytpic->resize(w, 10 * h / 100);
    Dailytpic->move(0, 0);
    Dailytpic->setParent(this);
    Dailytpic->setText(saying[b] + "\r" + saying[b + 1]);
    connect(Dailytpic, SIGNAL(enter()), this, SLOT(picshow()));
    connect(Dailytpic, SIGNAL(leave()), this, SLOT(picclose()));
    daily = new Daily;
    daily->hide();
    jizhang = new zhangWidget;
    jizhang->hide();

    answerwidget =new AnswerWidget;
    answerwidget->hide();

    eatwidget = new eatthing;
    eatwidget->hide();
    //todolist
    Todo = new QPushButton(this);
    Todo->setStyleSheet("QPushButton{background-color:rgb(249,210,125);border-radius:13px;border:1px solid Black;}"
        "QPushButton:hover{background-color:rgb(252,183,10);border-radius:20px;border:1px solid Black;}");
    Todo->setText("todo");
    Todo->resize(w / 10, h/10);
    Todo->move(90 * w / 100, 55 * h / 100);
    connect(Todo, &QPushButton::clicked, this, [=] {this->sx(); });
    //备忘录
    waiting = new QPushButton(this);
    waiting->resize(1 * w / 10, h / 10);
    waiting->move(90 * w / 100, 65 * h / 100);
    waiting->setText("备忘录");
    waiting->setStyleSheet("QPushButton{background-color:rgb(249,210,125);border-radius:13px;border:1px solid Black;}"
        "QPushButton:hover{background-color:rgb(252,183,10);border-radius:20px;border:1px solid Black;}");
    waiting->setParent(this);
    connect(waiting, &QPushButton::clicked, this, [=] {this->wit(); });
    //添加日程
    adddaily = new QPushButton(this);
    adddaily->resize(w / 10, h / 10);
    adddaily->move(90 * w / 100, 75 * h / 100);
    adddaily->setText("添加日程");
    adddaily->setStyleSheet("QPushButton{background-color:rgb(249,210,125);border-radius:13px;border:1px solid Black;}"
        "QPushButton:hover{background-color:rgb(252,183,10);border-radius:20px;border:1px solid Black;}");
    connect(adddaily, &QPushButton::clicked, this, [=] {this->show_adddaily(); });
    //记账
    addzhang = new QPushButton(this);
    addzhang->resize( w / 10, h / 10);
    addzhang->setText("记账");
    addzhang->move(90 * w / 100, 85 * h / 100);
    addzhang->setStyleSheet("QPushButton{background-color:rgb(249,210,125);border-radius:13px;border:1px solid Black;}"
        "QPushButton:hover{background-color:rgb(252,183,10);border-radius:20px;border:1px solid Black;}");
    connect(addzhang, &QPushButton::clicked, this, [=] {this->show_addzhang(); });
    //计算器
    Calculator = new QPushButton(this);
    Calculator->setText("计算器");
    Calculator->setStyleSheet("QPushButton{background-color:rgb(249,210,125);border-radius:13px;border:1px solid Black;}"
        "QPushButton:hover{background-color:rgb(252,183,10);border-radius:20px;border:1px solid Black;}");
    Calculator->resize( w / 10, h / 10);
    Calculator->move(0, 55 * h / 100);
    connect(Calculator, &QPushButton::clicked, this, [=] {calculator->show(); });
    //今天吃什么
    Whateat = new QPushButton(this);
    Whateat->setText("今天吃什么");
    Whateat->setStyleSheet("QPushButton{background-color:rgb(249,210,125);border-radius:13px;border:1px solid Black;}"
        "QPushButton:hover{background-color:rgb(252,183,10);border-radius:20px;border:1px solid Black;}");
    Whateat->resize(w / 10, h / 10);
    Whateat->move(0, 65 * h / 100);
    connect(Whateat, &QPushButton::clicked, this, [=] {this->show_whateat(); });
    //答案之书
    Whatans = new QPushButton(this);
    Whatans->setText("答案之书");
    Whatans->setStyleSheet("QPushButton{background-color:rgb(249,210,125);border-radius:13px;border:1px solid Black;}"
        "QPushButton:hover{background-color:rgb(252,183,10);border-radius:20px;border:1px solid Black;}");
    Whatans->resize(w / 10, h / 10);
    Whatans->move(0, 75 * h / 100);
    connect(Whatans, &QPushButton::clicked, this, [=] {this->show_whatans(); });
    //计算器
    dailyhealth = new QPushButton(this);
    dailyhealth->setText("每日健康");
    dailyhealth->setStyleSheet("QPushButton{background-color:rgb(249,210,125);border-radius:13px;border:1px solid Black;}"
        "QPushButton:hover{background-color:rgb(252,183,10);border-radius:20px;border:1px solid Black;}");
    dailyhealth->resize( w / 10, h / 10);
    dailyhealth->move(0, 85* h / 100);
    connect(dailyhealth, &QPushButton::clicked, this, [=] {this->show_dailyhealth(); });
    //刷新日历数据
    initWidget();
}
//判断某年某月某日是周几的函数
int Calendar::CaculateWeekDay(int y, int m, int d)
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
bool Calendar::isLoopYaer(int year)
{
    return (((0 == (year % 4)) && (0 != (year % 100))) || (0 == (year % 400)));
}
//计算
int Calendar::getTotalMonthDays(int year, int month)
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
int Calendar::getMonthDays(int year, int month)
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
int Calendar::LunarCalendar(int year, int month, int day)
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
    //StaticDayCount记录大小月的天数 29 或30  
    //index 记录从哪个月开始来计算。  
    //flag 是用来对闰月的特殊处理。  
    //判断阳历日在春节前还是春节后  
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
//展示农历
char* Calendar::output(int year, int month, int day)
{     
    const char* ChDay[] = {"*","初一","初二","初三","初四","初五","初六","初七","初八","初九","初十", "十一","十二","十三","十四","十五","十六","十七","十八","十九","二十","廿一","廿二","廿三","廿四","廿五","廿六","廿七","廿八","廿九","三十"};
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
        strcat_s(str, ChDay[LunarCalendarDay & 0x1f]);//0x3f修改后
        LunarCalendarDay = 0;
    return str;
}

Calendar::~Calendar()
{
    for (int i = 0; i < 6; i++)
    {
        delete[]date[i];
    }
    delete[]headLine;
    delete bar;
}
void  Calendar::initWidget()
{
    bar->setText(QString::number(current_year, 10) + "年" + QString::number(current_month, 10) + "月");
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
                date[0][i].setDate(current_year - 1, 12, lastMonthDay);
                date[0][i].setText(QString::number(lastMonthDay--, 10) + "\n" + output(current_year - 1, 12, lastMonthDay));
            }
            else
            {
                date[0][i].setDate(current_year, current_month - 1, lastMonthDay);
                date[0][i].setText(QString::number(lastMonthDay--, 10) + "\n" +output(current_year, current_month - 1, lastMonthDay));
            }

        }
        //显示当前月天数
        int i = 1; int j = 0;
        while (total <= currentMonthDay)
        {
            date[i][j].setDate(current_year, current_month - 1, total);
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
                date[i][j].setDate(current_year + 1, 1, total);
                date[i][j++].setText(QString::number(total++, 10) + "\n" + QString::fromLocal8Bit(output(current_year + 1, 1, total)));
            }
            else
            {
                date[i][j].setDate(current_year, current_month + 1, total);
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
                date[0][i].setDate(current_year - 1, 12, lastMonthDay);
                date[0][i].setText(QString::number(lastMonthDay--, 10) + "\n" + output(current_year-1, 12, lastMonthDay));
            }
            else
            {
                date[0][i].setDate(current_year, current_month - 1, lastMonthDay);
                date[0][i].setText(QString::number(lastMonthDay--, 10) + "\n" + output(current_year, current_month - 1, lastMonthDay));
            }
           
        }
        //显示当前月
        for (int i = firweek; i < 7; i++)
        {
            date[0][i].setText(QString::number(total++, 10) + "\n" +output(current_year, current_month, total));
            if (QDate::currentDate().day() == total)
            {
                date[0][i].setStyleSheet("QLabel{color:rgba(255, 0, 0, 255);font-size:30px;}");
            }
        }
        int i = 1; int j = 0;
        while (total <= currentMonthDay)
        {
            date[i][j].setDate(current_year, current_month, total);
            date[i][j++].setText(QString::number(total++, 10) + "\n" + output(current_year, current_month, total));
           
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
                date[i][j].setDate(current_year + 1, 1, total);
                date[i][j++].setText(QString::number(total++, 10) + "\n" + output(current_year+1, 1, total));
            }
            else
            {
                date[i][j].setDate(current_year, current_month + 1, total);
                date[i][j++].setText(QString::number(total++, 10) + "\n" +output(current_year, current_month+1, total));
            }         
            if (j == 7)
            {
                i++;
                j = 0;
            }
        }
    }
    qDebug() << 1;
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

void Calendar::UpdateSaying() {
    int b = rand() % 130;   //随机生成0到9的随机数
    if (b % 2) {
        if (b != 129)b--;
        else {
            b = 0;
        }
    }
    //text_saying->clear();
    //text_word->clear();
    //text_saying->setText(saying[b]);
    //text_word->setText(word[b]);
    Dailytpic->setText(saying[b]+"\r"+saying[b+1]);
}

void Calendar::ts()
{
    a->move(this->x() + this->frameGeometry().width(), this->y());
}
void Calendar::sx()
{
    a->show();
    connect(timer, &QTimer::timeout, this,[=]() {this->ts(); });
    timer->start(1);
}
void Calendar::wit() {
    
    w->show();
};
void Calendar::picshow() {
    picture->show();
    picture->raise();
    UpdateSaying();
};
void Calendar::picclose() {
    picture->close();
};
//查看日程
void Calendar::labelpress(int y, int m, int d)
{
    string ymd = to_string(y);
    if (m < 10)
    {
        ymd += "0";
        ymd += to_string(m);
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
    emit(sendto_schdule(ymd + s));
    schedule_window.move(this->pos().x()+this->size().width() / 4, this->pos().y()+ 3*this->size().height() / 10);
    schedule_window.raise();
    schedule_window.show();

}


void Calendar::reciveOK(string oc)
{
    this->show();
    string ymd = oc.substr(1, 8);

    if (oc[0] == 'D')
    {
        map<string, string>::iterator key = t.find(ymd);
        if (key != t.end())
        {
            t.erase(key);
        }
        ofstream b("daily.txt");
        string s1;
        string s2;
        for (auto it = t.begin(); it != t.end(); ++it)
        {
            s1 = "#" + (*it).first;
            s2 = "#" + (*it).second;
            b << s1;
            b << endl;
            b << s2;
            b << endl;
        }
        b.close();
    }
    else if (oc[0] == 'C')
    {
        string cont = oc.substr(9, -1);
        map<string, string>::iterator key = t.find(ymd);
        if (key != t.end())
        {
            key->second = cont;
        }
        ofstream b("daily.txt");
        string s1;
        string s2;
        for (auto it = t.begin(); it != t.end(); ++it)
        {
            s1 = "#" + (*it).first;
            s2 = "#" + (*it).second;
            b << s1;
            b << endl;
            b << s2;
            b << endl;
        }
        b.close();
    }
};

//添加日程
void Calendar::show_adddaily() {
    daily->show();
};
//记账
void Calendar::show_addzhang() {
    jizhang->show();
};

void Calendar::show_dailyhealth() {

};
void Calendar::show_whateat() {
    eatwidget->move(this->pos().x() + this->size().width() / 4, this->pos().y());
    eatwidget->show();
};
void Calendar::show_whatans() {
    answerwidget->move(this->pos().x() + this->size().width() / 4, this->pos().y());
    answerwidget->show();
};

void Calendar::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setBrush(Qt::white);
    int w = this->width();
    int h = this->height();
    painter.drawRoundedRect(15*w/100,15*h/100,7*w/10,7*h/10,80,50);
    
    painter.drawRoundedRect(90 * w / 100,55*h /100,2*w / 10, 40 * h / 100,20, 10);
    painter.drawRoundedRect(-w/10, 55*h /100,2*w / 10,40* h /100, 20, 10);
    painter.drawPixmap(0,10*h/100,15*w/100,45*h/100,QPixmap(":/Calendar/lady1.png"));
    painter.drawPixmap(85*w/100, 10 * h / 100, 15 * w / 100, 45 * h / 100, QPixmap(":/Calendar/lady2.png"));
}