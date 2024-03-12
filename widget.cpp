#include "widget.h"
#include "ui_widget.h"
#define CALCULATION
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::isPossible(){
    if (money < 100) {
        ui->pbCoffee->setEnabled(false);
    }
    if (money < 200) {
        ui->pbTea->setEnabled(false);
    }
    if (money < 300) {
        ui->pbTang->setEnabled(false);
    }
}

void Widget::changeMoney(int diff){
    money += diff;
    ui->lcdNumber->display(money);
    isPossible();
}




void Widget::on_pbCoin10_clicked()
{
   changeMoney(10);
}


void Widget::on_pbCoin50_clicked()
{
    changeMoney(50);
}

void Widget::on_pbCoin100_clicked()
{
    changeMoney(100);
}

void Widget::on_pbCoffee_clicked()
{
    money -= 100;
}

void Widget::on_pbCoin500_clicked()
{
 changeMoney(500);
}

void Widget::on_pbTea_clicked()
{
    changeMoney(-200);
}

void Widget::on_pbTang_clicked()
{
    changeMoney(-300);
}


void Widget::on_pbReset_clicked() {
    QMessageBox mb;

    int Coin10, Coin50, Coin100;

    Coin100 = money / 100;
    money %= 100;

    Coin50 = money / 50;
    money %= 50;

    Coin10 = money / 10;
    money %= 10;

    QString message = "10 : " + QString::number(Coin10) + "\n" +
                      "50 : " + QString::number(Coin50) + "\n" +
                      "100 : " + QString::number(Coin100);

    mb.information(nullptr, "Coins Count", message);
}

