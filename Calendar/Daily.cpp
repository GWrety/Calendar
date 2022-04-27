#include "Daily.h"
#include"qdatetime.h"
Daily::Daily(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
	this->setWindowIcon(QIcon(":/Calendar/time.png"));
	this->setWindowTitle("添加日程");
	QDate date;
	QFont a;
	a.setPointSize(30);
	QString temp = ui.dateEdit->date().toString("yyyy/MM/dd");
	ui.dateEdit->setDate(date.currentDate());
	ui.dateEdit->setFont(a);
	a.setPointSize(20);
	ui.textEdit->setFont(a);
}
void Daily::UpDateDaile()
{   QFont a;
	a.setPointSize(20);
	ui.textEdit->setFont(a);
	b.open("daily.txt",ios::app);
	QString temp = ui.dateEdit->date().toString("yyyy/MM/dd");
	string tempa = temp.toStdString();
	string temps = "";
	temps = ui.textEdit->toPlainText().toStdString();
	b << "#" << tempa.substr(0, 4)<<tempa.substr(5,2)<<tempa.substr(8,2) << endl;
	b << "#" << temps << endl;
	a.setPointSize(50);
	ui.textEdit->setFont(a);
	temp = "SUCCEED ADD!!!";
	ui.textEdit->setText(temp.toLocal8Bit());
	b.close();
}