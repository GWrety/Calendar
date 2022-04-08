#include "model.h"

model::model()
{
    // 初始化
    this->num1 = 0;
    this->num2 = 0;
}

// 定义方法，对应model.h中的定义
void model::setNum1(int num)
{
    this->num1 = num;
}

void model::setNum2(int num)
{
    this->num2 = num;
}

void model::setFlag(QString flag)
{
    this->flag = flag;
}

// 当用户点击"="号时调用该函数
QString model::doExpr()
{
    double result = 0.0;
    // switch不能用QStirng，这里用if
    if(this->flag=="+"){
        result = this->num1 + this->num2;
    }else if(this->flag=="-"){
        result = this->num1 - this->num2;
    }else if(this->flag=="*"){
        result = this->num1 * this->num2;
    }else if(this->flag=="/"){
        // 除数为0的情况
        if(this->num2==0){
            return "-1";
        }
        result = (this->num1)*1.0 / this->num2;
    }else{
        // 把int类型转化成string类型
        // 1. str = QString::number(num);
        // 2. str = setNum(num);
        return QString::number(this->num1);
    }
    return QString::number(result);
}
