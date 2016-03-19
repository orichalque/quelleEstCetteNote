/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QCheckBox>
#include <QHeaderView>
#include <QMainWindow>
#include <QMenuBar>
#include <QPushButton>
#include <QSlider>
#include <QStatusBar>
#include <QToolBar>
#include <QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *sdf;
    QSlider *verticalSlider;
    QSlider *horizontalSlider;
    QPushButton *dfsdfsd;
    QCheckBox *checkBox;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString("MainWindow"));
        MainWindow->resize(400, 300);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString("centralWidget"));
        sdf = new QPushButton(centralWidget);
        sdf->setObjectName(QString("sdf"));
        sdf->setGeometry(QRect(70, 100, 141, 51));
        sdf->setStyleSheet(QString("border-image: url(:/img/doremi);"));
        verticalSlider = new QSlider(centralWidget);
        verticalSlider->setObjectName(QString("verticalSlider"));
        verticalSlider->setGeometry(QRect(40, 40, 24, 160));
        verticalSlider->setMaximum(1);
        verticalSlider->setOrientation(Qt::Vertical);
        horizontalSlider = new QSlider(centralWidget);
        horizontalSlider->setObjectName(QString("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(150, 60, 160, 24));
        horizontalSlider->setMaximum(1);
        horizontalSlider->setOrientation(Qt::Horizontal);
        dfsdfsd = new QPushButton(centralWidget);
        dfsdfsd->setObjectName(QString("dfsdfsd"));
        dfsdfsd->setGeometry(QRect(210, 50, 131, 161));
        QFont font;
        font.setBold(false);
        font.setItalic(false);
        font.setUnderline(false);
        font.setWeight(50);
        font.setStrikeOut(false);
        font.setKerning(false);
        dfsdfsd->setFont(font);
        dfsdfsd->setStyleSheet(QString(""));
        dfsdfsd->setIconSize(QSize(50, 16));
        dfsdfsd->setCheckable(true);
        dfsdfsd->setChecked(false);
        dfsdfsd->setAutoRepeat(false);
        dfsdfsd->setAutoExclusive(false);
        checkBox = new QCheckBox(centralWidget);
        checkBox->setObjectName(QString("checkBox"));
        checkBox->setGeometry(QRect(10, 210, 104, 23));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 28));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        sdf->setText(QString());
#ifndef QT_NO_ACCESSIBILITY
        dfsdfsd->setAccessibleName(QString());
#endif // QT_NO_ACCESSIBILITY
        dfsdfsd->setText(QApplication::translate("MainWindow", "dennis", "sqdfqs"));
        checkBox->setText(QApplication::translate("MainWindow", "CheckBox", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
