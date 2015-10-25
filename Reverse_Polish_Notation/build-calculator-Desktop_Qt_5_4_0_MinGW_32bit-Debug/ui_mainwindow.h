/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
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
#include <QtWidgets/QSpacerItem>
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
    QPushButton *three;
    QPushButton *one;
    QPushButton *two;
    QPushButton *eight;
    QPushButton *six;
    QPushButton *seven;
    QPushButton *five;
    QPushButton *nine;
    QPushButton *four;
    QPushButton *zero;
    QPushButton *decimal;
    QPushButton *space;
    QSpacerItem *horizontalSpacer;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QPushButton *clear;
    QPushButton *subtract;
    QPushButton *Backspace;
    QPushButton *add;
    QPushButton *mult;
    QPushButton *closeParen;
    QPushButton *openParen;
    QPushButton *equal;
    QPushButton *exponent;
    QPushButton *divide;
    QLabel *display;
    QLabel *postFix;
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
        MainWindow->resize(632, 688);
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
        gridLayoutWidget->setGeometry(QRect(20, 180, 320, 420));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        three = new QPushButton(gridLayoutWidget);
        three->setObjectName(QStringLiteral("three"));
        three->setMinimumSize(QSize(100, 100));

        gridLayout->addWidget(three, 0, 2, 1, 1);

        one = new QPushButton(gridLayoutWidget);
        one->setObjectName(QStringLiteral("one"));
        one->setMinimumSize(QSize(100, 100));
        one->setMaximumSize(QSize(100, 100));

        gridLayout->addWidget(one, 0, 0, 1, 1);

        two = new QPushButton(gridLayoutWidget);
        two->setObjectName(QStringLiteral("two"));
        two->setMinimumSize(QSize(100, 100));

        gridLayout->addWidget(two, 0, 1, 1, 1);

        eight = new QPushButton(gridLayoutWidget);
        eight->setObjectName(QStringLiteral("eight"));
        eight->setMinimumSize(QSize(100, 100));

        gridLayout->addWidget(eight, 2, 1, 1, 1);

        six = new QPushButton(gridLayoutWidget);
        six->setObjectName(QStringLiteral("six"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(100);
        sizePolicy.setVerticalStretch(100);
        sizePolicy.setHeightForWidth(six->sizePolicy().hasHeightForWidth());
        six->setSizePolicy(sizePolicy);
        six->setMinimumSize(QSize(100, 100));

        gridLayout->addWidget(six, 1, 2, 1, 1);

        seven = new QPushButton(gridLayoutWidget);
        seven->setObjectName(QStringLiteral("seven"));
        seven->setMinimumSize(QSize(100, 100));

        gridLayout->addWidget(seven, 2, 0, 1, 1);

        five = new QPushButton(gridLayoutWidget);
        five->setObjectName(QStringLiteral("five"));
        five->setMinimumSize(QSize(100, 100));

        gridLayout->addWidget(five, 1, 1, 1, 1);

        nine = new QPushButton(gridLayoutWidget);
        nine->setObjectName(QStringLiteral("nine"));
        nine->setMinimumSize(QSize(100, 100));

        gridLayout->addWidget(nine, 2, 2, 1, 1);

        four = new QPushButton(gridLayoutWidget);
        four->setObjectName(QStringLiteral("four"));
        four->setMinimumSize(QSize(100, 100));

        gridLayout->addWidget(four, 1, 0, 1, 1);

        zero = new QPushButton(gridLayoutWidget);
        zero->setObjectName(QStringLiteral("zero"));
        zero->setMinimumSize(QSize(100, 100));
        QFont font;
        font.setPointSize(10);
        zero->setFont(font);

        gridLayout->addWidget(zero, 3, 1, 1, 1);

        decimal = new QPushButton(gridLayoutWidget);
        decimal->setObjectName(QStringLiteral("decimal"));
        decimal->setMinimumSize(QSize(100, 100));

        gridLayout->addWidget(decimal, 3, 2, 1, 1);

        space = new QPushButton(gridLayoutWidget);
        space->setObjectName(QStringLiteral("space"));
        sizePolicy.setHeightForWidth(space->sizePolicy().hasHeightForWidth());
        space->setSizePolicy(sizePolicy);
        space->setMinimumSize(QSize(100, 100));

        gridLayout->addWidget(space, 3, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(158, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 3, 1, 1);

        gridLayoutWidget_2 = new QWidget(centralWidget);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(390, 220, 208, 332));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        clear = new QPushButton(gridLayoutWidget_2);
        clear->setObjectName(QStringLiteral("clear"));
        clear->setMinimumSize(QSize(100, 50));

        gridLayout_2->addWidget(clear, 1, 0, 1, 1);

        subtract = new QPushButton(gridLayoutWidget_2);
        subtract->setObjectName(QStringLiteral("subtract"));
        subtract->setMinimumSize(QSize(100, 50));

        gridLayout_2->addWidget(subtract, 5, 1, 1, 1);

        Backspace = new QPushButton(gridLayoutWidget_2);
        Backspace->setObjectName(QStringLiteral("Backspace"));
        Backspace->setMinimumSize(QSize(100, 50));

        gridLayout_2->addWidget(Backspace, 1, 1, 1, 1);

        add = new QPushButton(gridLayoutWidget_2);
        add->setObjectName(QStringLiteral("add"));
        add->setMinimumSize(QSize(100, 50));

        gridLayout_2->addWidget(add, 5, 0, 1, 1);

        mult = new QPushButton(gridLayoutWidget_2);
        mult->setObjectName(QStringLiteral("mult"));
        mult->setMinimumSize(QSize(100, 50));

        gridLayout_2->addWidget(mult, 4, 0, 1, 1);

        closeParen = new QPushButton(gridLayoutWidget_2);
        closeParen->setObjectName(QStringLiteral("closeParen"));
        closeParen->setMinimumSize(QSize(100, 50));

        gridLayout_2->addWidget(closeParen, 2, 1, 1, 1);

        openParen = new QPushButton(gridLayoutWidget_2);
        openParen->setObjectName(QStringLiteral("openParen"));
        openParen->setMinimumSize(QSize(100, 50));

        gridLayout_2->addWidget(openParen, 2, 0, 1, 1);

        equal = new QPushButton(gridLayoutWidget_2);
        equal->setObjectName(QStringLiteral("equal"));
        equal->setMinimumSize(QSize(100, 50));

        gridLayout_2->addWidget(equal, 6, 1, 1, 1);

        exponent = new QPushButton(gridLayoutWidget_2);
        exponent->setObjectName(QStringLiteral("exponent"));
        exponent->setMinimumSize(QSize(100, 50));

        gridLayout_2->addWidget(exponent, 6, 0, 1, 1);

        divide = new QPushButton(gridLayoutWidget_2);
        divide->setObjectName(QStringLiteral("divide"));
        divide->setMinimumSize(QSize(100, 50));

        gridLayout_2->addWidget(divide, 4, 1, 1, 1);

        display = new QLabel(centralWidget);
        display->setObjectName(QStringLiteral("display"));
        display->setGeometry(QRect(40, 110, 561, 61));
        QFont font1;
        font1.setPointSize(36);
        display->setFont(font1);
        display->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        postFix = new QLabel(centralWidget);
        postFix->setObjectName(QStringLiteral("postFix"));
        postFix->setGeometry(QRect(40, 0, 561, 61));
        postFix->setFont(font1);
        postFix->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 632, 21));
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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Calculator", 0));
        actionGo_away->setText(QApplication::translate("MainWindow", "No", 0));
        actionNo_peeking->setText(QApplication::translate("MainWindow", "No peeking", 0));
        actionHelp_me->setText(QApplication::translate("MainWindow", "Help me!", 0));
        three->setText(QApplication::translate("MainWindow", "3", 0));
        one->setText(QApplication::translate("MainWindow", "1", 0));
        two->setText(QApplication::translate("MainWindow", "2", 0));
        eight->setText(QApplication::translate("MainWindow", "8", 0));
        six->setText(QApplication::translate("MainWindow", "6", 0));
        seven->setText(QApplication::translate("MainWindow", "7", 0));
        five->setText(QApplication::translate("MainWindow", "5", 0));
        nine->setText(QApplication::translate("MainWindow", "9", 0));
        four->setText(QApplication::translate("MainWindow", "4", 0));
        zero->setText(QApplication::translate("MainWindow", "0", 0));
        decimal->setText(QApplication::translate("MainWindow", ".", 0));
        space->setText(QApplication::translate("MainWindow", "Space", 0));
        clear->setText(QApplication::translate("MainWindow", "Clear", 0));
        subtract->setText(QApplication::translate("MainWindow", "-", 0));
        Backspace->setText(QApplication::translate("MainWindow", "BackSpace", 0));
        add->setText(QApplication::translate("MainWindow", "+", 0));
        mult->setText(QApplication::translate("MainWindow", "*", 0));
        closeParen->setText(QApplication::translate("MainWindow", ")", 0));
        openParen->setText(QApplication::translate("MainWindow", "(", 0));
        equal->setText(QApplication::translate("MainWindow", "=", 0));
        exponent->setText(QApplication::translate("MainWindow", "^", 0));
        divide->setText(QApplication::translate("MainWindow", "/", 0));
        display->setText(QApplication::translate("MainWindow", "0", 0));
        postFix->setText(QApplication::translate("MainWindow", "0", 0));
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
