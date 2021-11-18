#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
int currentwidget = 0;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    currentwidget = 0;
    operatorFun();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::operatorFun()
{
    QStringList qss;
    //qss.append(QString("QPushButton{background-image:url(:/source/circleBtn.jpg);}"));
    qss.append(QString("QPushButton{"
                       "border:2px solid;"
                       "border-colcor:black;"
                       "border-top-left-radius:32px;"
                       "border-top-right-radius:32px;"
                       "border-bottom-left-radius:32px;"
                       "border-bottom-right-radius:32px;"
                       "}"));

    qss.append(QString("QPushButton{"
                       "background-color:rgb(225,225,225);"
                       "}"));

    qss.append(QString("QPushButton:pressed{"
                       "background-color:rgb(255,255,255);"
                       "}"));

    ui->pushButton->setStyleSheet(qss.join(""));

    ui->pushButton_2->setStyleSheet(qss.join(""));

    ui->pushButton_3->setStyleSheet(qss.join(""));

    ui->pushButton_4->setStyleSheet(qss.join(""));

    QStringList qss2;

    qss2.append(QString("QPushButton{"
                        "background-color:rgb(225,225,225);"
                        "border:2px solid;"
                        "border-color:rgb(64,65,66);"
                        "}"));

    qss2.append(QString("QPushButton:pressed{"
                        "background-color:rgb(229,241,251);"
                        "border:2px solid;"
                        "border-color:rgb(225,225,225);"
                        "}"));

    ui->pushButton_5->setStyleSheet(qss2.join(""));
    ui->pushButton_6->setStyleSheet(qss2.join(""));
    ui->pushButton_7->setStyleSheet(qss2.join(""));


}

void MainWindow::on_pushButton_4_clicked()
{
    currentwidget++;
    if(currentwidget>=ui->stackedWidget->count())
    {
        currentwidget = 0;
    }
    ui->stackedWidget->setCurrentIndex(currentwidget);

}

void MainWindow::on_pushButton_3_clicked()
{
    currentwidget--;
    if(currentwidget<0)
    {
        currentwidget = ui->stackedWidget->count()-1;
    }
    ui->stackedWidget->setCurrentIndex(currentwidget);
}
