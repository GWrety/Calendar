#include <QWidget>
#include<QDate>
#include<QDateTime>
#include<QString>
#include<QLabel>
#include<QPushButton>
#include<QStringlist>
#include<QFile>
#include<QDebug>
#include<QTextStream>
#include<QTextCodec>
#include<QByteArray>
#include "ui_widget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class zhangWidget; }
QT_END_NAMESPACE

class zhangWidget : public QWidget
{
    Q_OBJECT

public:
    zhangWidget(QWidget *parent = nullptr);
    ~zhangWidget();
     void readtofile();
     void writetofile();
     void allpay();
     void deletedate();
private:
    Ui::zhangWidget *ui;
    QStringList name;
    QStringList time;
    QStringList sum;
    QStringList about;
};

