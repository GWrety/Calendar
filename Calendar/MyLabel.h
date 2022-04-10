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
	//�������¼�
	void enterEvent(QEnterEvent*);
	//����뿪��
	void leaveEvent(QEvent*);
	int year;
	int month;
	int day;

	void mousePressEvent(QMouseEvent* event);

	void setDate(int year, int month, int day);

signals:
	void clicked(int y, int m, int d);
};

