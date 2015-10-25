/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionGo_away;
    QAction *actionNo_peeking;
    QAction *actionHelp_me;
    QWidget *centralWidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *two;
    QPushButton *one;
    QPushButton *three;
    QPushButton *eight;
    QPushButton *seven;
    QPushButton *six;
    QPushButton *four;
    QPushButton *five;
    QPushButton *nine;
    QPushButton *zero;
    QPushButton *decimal;
    QPushButton *plusMinus;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QPushButton *clearEntry;
    QPushButton *subtract;
    QPushButton *divide;
    QPushButton *clear;
    QPushButton *closeParen;
    QPushButton *add;
    QPushButton *mult;
    QPushButton *openParen;
    QPushButton *equal;
    QPushButton *exponent;
    QLabel *display;
    QMenuBar *menuBar;
    QMenu *menuCalculator;
    QMenu *menuView;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(665, 300);
        actionGo_away = new QAction(MainWindow);
        actionGo_away->setObjectName(QStringLiteral("actionGo_away"));
        actionNo_peeking = new QAction(MainWindow);
        actionNo_peeking->setObjectName(QStringLiteral("actionNo_peeking"));
        actionHelp_me = new QAction(MainWindow);
        actionHelp_me->setObjectName(QStringLiteral("actionHelp_me"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(30, 80, 401, 161));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        two = new QPushButton(gridLayoutWidget);
        two->setObjectName(QStringLiteral("two"));

        gridLayout->addWidget(two, 0, 1, 1, 1);

        one = new QPushButton(gridLayoutWidget);
        one->setObjectName(QStringLiteral("one"));

        gridLayout->addWidget(one, 0, 0, 1, 1);

        three = new QPushButton(gridLayoutWidget);
        three->setObjectName(QStringLiteral("three"));

        gridLayout->addWidget(three, 0, 2, 1, 1);

        eight = new QPushButton(gridLayoutWidget);
        eight->setObjectName(QStringLiteral("eight"));

        gridLayout->addWidget(eight, 2, 1, 1, 1);

        seven = new QPushButton(gridLayoutWidget);
        seven->setObjectName(QStringLiteral("seven"));

        gridLayout->addWidget(seven, 2, 0, 1, 1);

        six = new QPushButton(gridLayoutWidget);
        six->setObjectName(QStringLiteral("six"));

        gridLayout->addWidget(six, 1, 2, 1, 1);

        four = new QPushButton(gridLayoutWidget);
        four->setObjectName(QStringLiteral("four"));

        gridLayout->addWidget(four, 1, 0, 1, 1);

        five = new QPushButton(gridLayoutWidget);
        five->setObjectName(QStringLiteral("five"));

        gridLayout->addWidget(five, 1, 1, 1, 1);

        nine = new QPushButton(gridLayoutWidget);
        nine->setObjectName(QStringLiteral("nine"));

        gridLayout->addWidget(nine, 2, 2, 1, 1);

        zero = new QPushButton(gridLayoutWidget);
        zero->setObjectName(QStringLiteral("zero"));
        QFont font;
        font.setPointSize(10);
        zero->setFont(font);

        gridLayout->addWidget(zero, 3, 1, 1, 1);

        decimal = new QPushButton(gridLayoutWidget);
        decimal->setObjectName(QStringLiteral("decimal"));

        gridLayout->addWidget(decimal, 3, 2, 1, 1);

        plusMinus = new QPushButton(gridLayoutWidget);
        plusMinus->setObjectName(QStringLiteral("plusMinus"));

        gridLayout->addWidget(plusMinus, 3, 0, 1, 1);

        gridLayoutWidget_2 = new QWidget(centralWidget);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(460, 80, 181, 170));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        clearEntry = new QPushButton(gridLayoutWidget_2);
        clearEntry->setObjectName(QStringLiteral("clearEntry"));

        gridLayout_2->addWidget(clearEntry, 1, 1, 1, 1);

        subtract = new QPushButton(gridLayoutWidget_2);
        subtract->setObjectName(QStringLiteral("subtract"));

        gridLayout_2->addWidget(subtract, 4, 1, 1, 1);

        divide = new QPushButton(gridLayoutWidget_2);
        divide->setObjectName(QStringLiteral("divide"));

        gridLayout_2->addWidget(divide, 3, 1, 1, 1);

        clear = new QPushButton(gridLayoutWidget_2);
        clear->setObjectName(QStringLiteral("clear"));

        gridLayout_2->addWidget(clear, 1, 0, 1, 1);

        closeParen = new QPushButton(gridLayoutWidget_2);
        closeParen->setObjectName(QStringLiteral("closeParen"));

        gridLayout_2->addWidget(closeParen, 2, 1, 1, 1);

        add = new QPushButton(gridLayoutWidget_2);
        add->setObjectName(QStringLiteral("add"));

        gridLayout_2->addWidget(add, 4, 0, 1, 1);

        mult = new QPushButton(gridLayoutWidget_2);
        mult->setObjectName(QStringLiteral("mult"));

        gridLayout_2->addWidget(mult, 3, 0, 1, 1);

        openParen = new QPushButton(gridLayoutWidget_2);
        openParen->setObjectName(QStringLiteral("openParen"));

        gridLayout_2->addWidget(openParen, 2, 0, 1, 1);

        equal = new QPushButton(gridLayoutWidget_2);
        equal->setObjectName(QStringLiteral("equal"));

        gridLayout_2->addWidget(equal, 5, 1, 1, 1);

        exponent = new QPushButton(gridLayoutWidget_2);
        exponent->setObjectName(QStringLiteral("exponent"));

        gridLayout_2->addWidget(exponent, 5, 0, 1, 1);

        display = new QLabel(centralWidget);
        display->setObjectName(QStringLiteral("display"));
        display->setGeometry(QRect(35, 10, 391, 61));
        QFont font1;
        font1.setPointSize(36);
        display->setFont(font1);
        display->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 665, 21));
        menuCalculator = new QMenu(menuBar);
        menuCalculator->setObjectName(QStringLiteral("menuCalculator"));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QStringLiteral("menuView"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuCalculator->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuCalculator->addAction(actionGo_away);
        menuView->addAction(actionNo_peeking);
        menuHelp->addAction(actionHelp_me);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionGo_away->setText(QApplication::translate("MainWindow", "No", 0));
        actionNo_peeking->setText(QApplication::translate("MainWindow", "No peeking", 0));
        actionHelp_me->setText(QApplication::translate("MainWindow", "Help me!", 0));
        two->setText(QApplication::translate("MainWindow", "2", 0));
        one->setText(QApplication::translate("MainWindow", "1", 0));
        three->setText(QApplication::translate("MainWindow", "3", 0));
        eight->setText(QApplication::translate("MainWindow", "8", 0));
        seven->setText(QApplication::translate("MainWindow", "7", 0));
        six->setText(QApplication::translate("MainWindow", "6", 0));
        four->setText(QApplication::translate("MainWindow", "4", 0));
        five->setText(QApplication::translate("MainWindow", "5", 0));
        nine->setText(QApplication::translate("MainWindow", "9", 0));
        zero->setText(QApplication::translate("MainWindow", "0", 0));
        decimal->setText(QApplication::translate("MainWindow", ".", 0));
        plusMinus->setText(QApplication::translate("MainWindow", "+/-", 0));
        clearEntry->setText(QApplication::translate("MainWindow", "Clear Entry", 0));
        subtract->setText(QApplication::translate("MainWindow", "-", 0));
        divide->setText(QApplication::translate("MainWindow", "/", 0));
        clear->setText(QApplication::translate("MainWindow", "Clear", 0));
        closeParen->setText(QApplication::translate("MainWindow", ")", 0));
        add->setText(QApplication::translate("MainWindow", "+", 0));
        mult->setText(QApplication::translate("MainWindow", "*", 0));
        openParen->setText(QApplication::translate("MainWindow", "(", 0));
        equal->setText(QApplication::translate("MainWindow", "=", 0));
        exponent->setText(QApplication::translate("MainWindow", "^", 0));
        display->setText(QApplication::translate("MainWindow", "0", 0));
        menuCalculator->setTitle(QApplication::translate("MainWindow", "Edit", 0));
        menuView->setTitle(QApplication::translate("MainWindow", "View", 0));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
