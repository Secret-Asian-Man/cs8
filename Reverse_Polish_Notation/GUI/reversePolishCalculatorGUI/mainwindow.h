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


public slots:
//    void updateDisplay();
    void onePressed();
    void twoPressed();
    void threePressed();
    void fourPressed();
    void fivePressed();
    void sixPressed();
    void sevenPressed();
    void eightPressed();
    void ninePressed();
    void zeroPressed();
    void decimalPressed();
    void plusMinusPressed();

private:
    Ui::MainWindow *ui;
    bool wasDecimalPressed;
    bool newEntry;


    void updateDisplay(char number);
};

#endif // MAINWINDOW_H
