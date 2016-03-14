#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QPainter>
#include <iostream>
#include <QDebug>
#include <cmath>
#include <QGraphicsScene>
#include "note.h"
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

void MainWindow::paintEvent(QPaintEvent * event)
{


}

MainWindow::~MainWindow()
{
    delete ui;
}

