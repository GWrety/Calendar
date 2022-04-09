#pragma once
#include <QWidget>
#include<qtextedit.h>
#include<qpushbutton.h>
using namespace std;
class schedule : public QWidget
{
	Q_OBJECT
public:
	schedule(QWidget* parent = 0);
	void p1_cli();
	void receive_frommain(string s);
	QPushButton* p1;
	QTextEdit* t1;
signals:
	void sendOK();
};