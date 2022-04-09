#pragma once
#include <qlabel.h>
#include <QMouseEvent>
#include<QEvent>
class MyLabel : public QLabel
{
	Q_OBJECT
public:
	explicit MyLabel(QWidget* parent = 0);

	//鼠标进入事件
	void enterEvent(QEvent*);
	//鼠标离开事
	void leaveEvent(QEvent*);



	//第二次迭代内容如下------
	int year;
	int month;
	int day;

	void mousePressEvent(QMouseEvent* event);

	void setDate(int year, int month, int day);

signals:
	void clicked(int y, int m, int d);


	

};

