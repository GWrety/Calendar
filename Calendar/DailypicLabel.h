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
	//�������¼�
	 void mousePressEvent(QMouseEvent*);
	//����뿪��
	void leaveEvent(QEvent*);
signals:
	void enter();
	void leave();
};