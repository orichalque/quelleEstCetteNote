#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_25_clicked();

    void on_pushButton_25_pressed();

    void on_pushButton_25_released();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
