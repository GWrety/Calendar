#pragma once
#include <QLabel>
#include <QMouseEvent>
#include<QEvent>
class DailyLabel : public QLabel
{
	Q_OBJECT
public:
	 DailyLabel(QWidget* parent = 0);
	 QString style[3];
	//鼠标进入事件
	 void mousePressEvent(QMouseEvent*);
	//鼠标离开事
	void leaveEvent(QEvent*);
signals:
	void enter();
	void leave();
};