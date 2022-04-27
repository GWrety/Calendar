#pragma once
#include <QLabel>
#include <QMouseEvent>
#include<QEvent>
class MyLabel : public QLabel
{
	Q_OBJECT
public:
	explicit MyLabel(QWidget* parent = 0);
	int lag = 0;
	//鼠标进入事件
	void enterEvent(QEnterEvent*);
	//鼠标离开事
	void leaveEvent(QEvent*);
	int year;
	int month;
	int day;
	bool isToday;
	bool isSchedule;
	void setToday(bool Today);
	void setSchedule(bool Schedule);
	void mousePressEvent(QMouseEvent* event);

	void setDate(int year, int month, int day);

signals:
	void clicked(int y, int m, int d);
};

