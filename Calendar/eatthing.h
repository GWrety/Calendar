#ifndef EATTHING_H
#define EATTHING_H

#include <QWidget>
#include<QFile>
#include<QString>
#include<QLabel>
#include<QPushButton>
#include<QTimer>
#include<QTextCodec>
#include<QStringList>
#include<QTextStream>
QT_BEGIN_NAMESPACE
namespace Ui { class eatthing; }
QT_END_NAMESPACE

class eatthing : public QWidget
{
    Q_OBJECT

public:
    eatthing(QWidget *parent = nullptr);
    ~eatthing();
    void readmenu();

private:
    Ui::eatthing *ui;
    QStringList mymenu;
    QTimer *timer;
    bool isStart=true;
};
#endif // EATTHING_H
