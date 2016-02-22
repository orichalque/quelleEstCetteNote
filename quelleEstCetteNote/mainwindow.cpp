#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_25_clicked()
{

}

void MainWindow::on_pushButton_25_pressed()
{
    ui -> pushButton_25 -> setStyleSheet("background-color: rgb(0, 181, 255)");
}

void MainWindow::on_pushButton_25_released()
{
    ui -> pushButton_25 -> setStyleSheet("background-color: rgb(155, 181, 255)");
}
