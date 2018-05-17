#include "widget.h"
#include "ui_widget.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QSqlRecord>
#include <QSqlError>
#include <QSqlDriver>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    if(QSqlDatabase::database().driver()->hasFeature(QSqlDriver::Transactions))
    {
        qDebug()<<2;
        QSqlQuery query;
        if(QSqlDatabase::database().transaction())
        {
            query.exec("insert into student values(16,'hello')");
            query.exec("insert into student values(17,'he')");
            query.exec("delete from student where id=14");
            if(QSqlDatabase::database().commit())
            {
                qDebug()<<QSqlDatabase::database().lastError();
                if(!QSqlDatabase::database().rollback())
                    qDebug()<<QSqlDatabase::database().lastError();
            }
        }
        query.exec("select * from students");
        while(query.next())
            qDebug()<<query.value(0).toInt()<<query.value(1).toString();
    }
}
