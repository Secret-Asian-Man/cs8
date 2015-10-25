#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include "parser.h"
#include "queue.h"

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

    void multiplyPressed();
    void dividePressed();
    void plusPressed();
    void minusPressed();
    void exponentPressed();

    void equalPressed();

    void closeParenPressed();
    void openParenPressed();
    void spacepressed();
    void clearScreenPressed();
    void backspacePressed();

private:
    Ui::MainWindow *ui;
    string userInput;
    bool wasDecimalPressed;
    bool newEntry;
    bool clear;

    void checkNewEntry();
    void outputMixed(parser<char> calculator);
    void outputShunt(parser<char> calculator);
    void updateDisplay(char number);
};

#endif // MAINWINDOW_H
