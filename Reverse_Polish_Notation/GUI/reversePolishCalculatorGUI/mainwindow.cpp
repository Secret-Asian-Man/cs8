#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    wasDecimalPressed=false;
    newEntry=true;
    connect(ui->one,SIGNAL(clicked()),this, SLOT(onePressed()));
    connect(ui->two,SIGNAL(clicked()),this, SLOT(onePressed()));
//    connect(ui->three,SIGNAL(clicked()),this, SLOT(onePressed()));
//    connect(ui->four,SIGNAL(clicked()),this, SLOT(onePressed()));
    connect(ui->five,SIGNAL(clicked()),this, SLOT(onePressed()));
    connect(ui->six,SIGNAL(clicked()),this, SLOT(onePressed()));
//    connect(ui->seven,SIGNAL(clicked()),this, SLOT(onePressed()));
    connect(ui->nine,SIGNAL(clicked()),this, SLOT(onePressed()));
//    connect(ui->zero,SIGNAL(clicked()),this, SLOT(onePressed()));

//    connect(ui->decimal,SIGNAL(clicked()),this, SLOT(onePressed()));
//    connect(ui->plusMinus,SIGNAL(clicked()),this, SLOT(onePressed()));

//    connect(Ui::MainWindow::two,SIGNAL(clicked()),Ui::MainWindow, SLOT(twoPressed()));
//    connect(Ui::MainWindow::three,SIGNAL(clicked()),Ui::MainWindow, SLOT(threePressed()));
//    connect(Ui::MainWindow::four,SIGNAL(clicked()),Ui::MainWindow, SLOT(fourPressed()));
//    connect(Ui::MainWindow::five,SIGNAL(clicked()),Ui::MainWindow, SLOT(fivePressed()));
//    connect(Ui::MainWindow::six,SIGNAL(clicked()),Ui::MainWindow, SLOT(sixPressed()));
//    connect(Ui::MainWindow::seven,SIGNAL(clicked()),Ui::MainWindow, SLOT(sevenPressed()));
//    connect(Ui::MainWindow::eight,SIGNAL(clicked()),Ui::MainWindow, SLOT(eightPressed()));
//    connect(Ui::MainWindow::nine,SIGNAL(clicked()),Ui::MainWindow, SLOT(ninePressed()));
//    connect(Ui::MainWindow::zero,SIGNAL(clicked()),Ui::MainWindow, SLOT(zeroPressed()));

//    connect(Ui::MainWindow::decimal,SIGNAL(clicked()),Ui::MainWindow, SLOT(decimalPressed()));
//    connect(Ui::MainWindow::plusMinus,SIGNAL(clicked()),Ui::MainWindow, SLOT(plusMinusPressed()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onePressed()
{
    updateDisplay('1');

}

void MainWindow::twoPressed()
{
    updateDisplay('2');

}

void MainWindow::threePressed()
{
    updateDisplay('3');

}

void MainWindow::fourPressed()
{
    updateDisplay('4');

}

void MainWindow::fivePressed()
{
    updateDisplay('5');

}

void MainWindow::sixPressed()
{
    updateDisplay('6');

}

void MainWindow::sevenPressed()
{
    updateDisplay('7');

}

void MainWindow::eightPressed()
{
    updateDisplay('8');

}

void MainWindow::ninePressed()
{
    updateDisplay('9');

}

void MainWindow::zeroPressed()
{
    updateDisplay('0');

}

void MainWindow::decimalPressed()
{
    if (!wasDecimalPressed)
    {
        wasDecimalPressed=true;
        updateDisplay('.');

    }
}

void MainWindow::plusMinusPressed()
{

}

void MainWindow::updateDisplay(char number)
{
    QString line=ui->display->text();
    if (newEntry)
    {
        newEntry=false;
        line="";
    }
    else
    {
        line=line+number;
        ui->display->setText(line);
    }


}
