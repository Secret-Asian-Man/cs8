#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdio.h>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    wasDecimalPressed = false;
    newEntry = true;
    clear=false;

    //-----------------------------NUMBER BUTTONS------------------------------------------
    connect(ui->one,SIGNAL(clicked()), this, SLOT(onePressed()));
    connect(ui->two,SIGNAL(clicked()), this, SLOT(twoPressed()));
    connect(ui->three,SIGNAL(clicked()), this, SLOT(threePressed()));
    connect(ui->four,SIGNAL(clicked()), this, SLOT(fourPressed()));
    connect(ui->five,SIGNAL(clicked()), this, SLOT(fivePressed()));
    connect(ui->six,SIGNAL(clicked()), this, SLOT(sixPressed()));
    connect(ui->seven,SIGNAL(clicked()), this, SLOT(sevenPressed()));
    connect(ui->eight,SIGNAL(clicked()), this, SLOT(eightPressed()));
    connect(ui->nine,SIGNAL(clicked()), this, SLOT(ninePressed()));
    connect(ui->zero,SIGNAL(clicked()), this, SLOT(zeroPressed()));
    //-----------------------------------------------------------------------


    //------------------------------OPERATOR BUTTONS-----------------------------------------
    connect(ui->mult,SIGNAL(clicked()), this, SLOT(multiplyPressed()));
    connect(ui->divide,SIGNAL(clicked()), this, SLOT(dividePressed()));
    connect(ui->exponent,SIGNAL(clicked()), this, SLOT(exponentPressed()));
    connect(ui->add,SIGNAL(clicked()), this, SLOT(plusPressed()));
    connect(ui->subtract,SIGNAL(clicked()), this, SLOT(minusPressed()));
    //-----------------------------------------------------------------------


    //------------------------------ENTER BUTTON-----------------------------------------
    connect(ui->equal,SIGNAL(clicked()), this, SLOT(equalPressed()));
    //-----------------------------------------------------------------------


    //--------------------------------UTILITY BUTTONS---------------------------------------
    connect(ui->openParen,SIGNAL(clicked()), this, SLOT(openParenPressed()));
    connect(ui->closeParen,SIGNAL(clicked()), this, SLOT(closeParenPressed()));
    connect(ui->decimal,SIGNAL(clicked()), this, SLOT(decimalPressed()));
    connect(ui->space,SIGNAL(clicked()), this, SLOT(spacepressed()));
    //-----------------------------------------------------------------------


    //-------------------------------CLEAR BUTTONS----------------------------------------
    connect(ui->clear,SIGNAL(clicked()), this, SLOT(clearScreenPressed()));
    connect(ui->Backspace,SIGNAL(clicked()), this, SLOT(backspacePressed()));
    //-----------------------------------------------------------------------

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::onePressed()
{    
    checkNewEntry(); //checks if there was a previous entry to create a new one.

    userInput=userInput+'1';
    updateDisplay('1');

}

void MainWindow::twoPressed()
{
    checkNewEntry(); //checks if there was a previous entry to create a new one.

    userInput=userInput+'2';
    updateDisplay('2');
}

void MainWindow::threePressed()
{
    checkNewEntry(); //checks if there was a previous entry to create a new one.

    userInput=userInput+'3';
    updateDisplay('3');
}

void MainWindow::fourPressed()
{
    checkNewEntry(); //checks if there was a previous entry to create a new one.

    userInput=userInput+'4';
    updateDisplay('4');
}

void MainWindow::fivePressed()
{
    checkNewEntry(); //checks if there was a previous entry to create a new one.

    userInput=userInput+'5';
    updateDisplay('5');
}

void MainWindow::sixPressed()
{
    checkNewEntry(); //checks if there was a previous entry to create a new one.

    userInput=userInput+'6';
    updateDisplay('6');
}

void MainWindow::sevenPressed()
{
    checkNewEntry(); //checks if there was a previous entry to create a new one.

    userInput=userInput+'7';
    updateDisplay('7');
}

void MainWindow::eightPressed()
{
    checkNewEntry(); //checks if there was a previous entry to create a new one.

    userInput=userInput+'8';
    updateDisplay('8');
}

void MainWindow::ninePressed()
{
    checkNewEntry(); //checks if there was a previous entry to create a new one.

    userInput=userInput+'9';
    updateDisplay('9');
}

void MainWindow::zeroPressed()
{
    checkNewEntry(); //checks if there was a previous entry to create a new one.

    userInput=userInput+'0';
    updateDisplay('0');
}

void MainWindow::decimalPressed()
{
    if(!wasDecimalPressed)
    {
        wasDecimalPressed = true;
        userInput=userInput+'.';
        updateDisplay('.');
    }
}

void MainWindow::multiplyPressed()
{
    checkNewEntry(); //checks if there was a previous entry to create a new one.

    wasDecimalPressed = false;

    userInput=userInput+'*';
    updateDisplay('x');

}

void MainWindow::dividePressed()
{
    checkNewEntry(); //checks if there was a previous entry to create a new one.

    wasDecimalPressed = false;

    userInput=userInput+'/';
    updateDisplay('/');
}

void MainWindow::plusPressed()
{
    checkNewEntry(); //checks if there was a previous entry to create a new one.

    wasDecimalPressed = false;

    userInput=userInput+'+';
    updateDisplay('+');

}

void MainWindow::minusPressed()
{
    checkNewEntry(); //checks if there was a previous entry to create a new one.

    wasDecimalPressed = false;

    userInput=userInput+'-';
    updateDisplay('-');

}

void MainWindow::exponentPressed()
{
    checkNewEntry(); //checks if there was a previous entry to create a new one.

    wasDecimalPressed = false;

    userInput=userInput+'^';
    updateDisplay('^');
}

void MainWindow::equalPressed()
{
    try
    {
        parser<char> calculator;

        clear=true;

        cout<<"DEBUG input queue: "<<userInput<<endl;
        calculator.calculate(userInput);

        outputMixed(calculator);
        outputShunt(calculator);

        userInput.clear();

    }
    catch(QUEUE_ERRORS error)
    {
        switch (error)
        {
        case QUEUE_EMPTY:
            std::cout<<"ERROR: QUEUE_EMPTY "<<std::endl;
            std::cout<<"ERROR: SYNTAX_ERROR "<<std::endl;
            ui->display->setText("Syntax Error");
            break;

        case QUEUE_FULL:
            std::cout<<"ERROR: QUEUE_FULL "<<std::endl;
            break;

        case QUEUE_ILLEGAL_SIZE:
            std::cout<<"ERROR: QUEUE_ILLEGAL_SIZE "<<std::endl;
            break;

        default:
            cout<<"Unkown QUEUE_EMPTY"<<endl;
            break;
        }
    }
    catch(STACK_ERRORS error)
    {
        switch (error)
        {
        case STACK_EMPTY:
            std::cout<<"ERROR: STACK_EMPTY "<<std::endl;
            std::cout<<"ERROR: SYNTAX_ERROR "<<std::endl;
            ui->display->setText("Syntax Error");
            break;

        case STACK_FULL:
            std::cout<<"ERROR: STACK_FULL "<<std::endl;
            break;

        case STACK_ILLEGAL_SIZE:
            std::cout<<"ERROR: STACK_ILLEGAL_SIZE "<<std::endl;
            break;

        default:
            cout<<"Unkown STACK_ERRORS"<<endl;
            break;
        }

    }
    catch(PARSER_ERRORS error)
    {
        switch (error)
        {
        case LPARENS_AT_END:
            std::cout<<"ERROR: LPARENS_AT_END "<<std::endl;
            ui->display->setText("Syntax Error");
            break;

        case RPARENS_WITHOUT_LPARENS:
            std::cout<<"ERROR: RPARENS_WITHOUT_LPARENS "<<std::endl;
            ui->display->setText("Syntax Error");
            break;

        case SYNTAX_ERROR:
            std::cout<<"ERROR: SYNTAX_ERROR "<<std::endl;
            break;

        case MATH_ERROR:
            std::cout<<"ERROR: MATH_ERROR "<<std::endl;
            ui->display->setText("Math Error");

            break;

        default:
            cout<<"Unkown PARSER_ERRORS"<<endl;
            break;
        }
    }
}// end of void MainWindow::equalPressed()

void MainWindow::closeParenPressed()
{
    checkNewEntry(); //checks if there was a previous entry to create a new one.

    userInput=userInput+')';
    updateDisplay(')');

}

void MainWindow::openParenPressed()
{
    checkNewEntry(); //checks if there was a previous entry to create a new one.

    userInput=userInput+'(';
    updateDisplay('(');

}

void MainWindow::spacepressed()
{
    checkNewEntry(); //checks if there was a previous entry to create a new one.

    userInput=userInput+' ';
    updateDisplay(' ');

}

void MainWindow::clearScreenPressed()
{
    newEntry = true;
    wasDecimalPressed=false;
    clear=false;

    userInput="";
    ui->display->setText("");
    ui->postFix->setText("");

}

void MainWindow::backspacePressed()
{
    if (userInput[userInput.size()-1]=='.')//if the end of the string is a '.'
        wasDecimalPressed=false;

    if (userInput.size()>0)
        userInput.pop_back();//erases the last character in the string
    else//if string is empty
        newEntry = true;

    ui->display->setText(userInput.c_str());
}

void MainWindow::checkNewEntry()
{
    if (clear)
    {
        userInput="";
        ui->display->setText("");
        ui->postFix->setText("");
        clear=false;
    }
}

void MainWindow::outputMixed(parser<char> calculator)
{
    std::ostringstream strs; //for converting to double to string


    int simple=calculator.finalAnswer.getNumerator()/calculator.finalAnswer.getDenominator();//for checking if rational is factorable by taking advantage of ints dropping decimals


    if (calculator.finalAnswer.getNumerator())//if the numerator != 0
    {

        if (simple!=0) //if factorable. Takes advantage of int dropping decimals
        {
            int temp=abs(calculator.finalAnswer.getNumerator())%calculator.finalAnswer.getDenominator(); //simplifies the numerator from a improper fraction, and makes sure the numerator isn't negative

            strs<<simple<<" "; //The whole number in the mixed number
            if (temp!=0)
            {
                strs<<temp<<"/"<<calculator.finalAnswer.getDenominator(); //outputs the numerator/denominator
            }
        }
        else
        {
            int temp=calculator.finalAnswer.getNumerator()%calculator.finalAnswer.getDenominator();//for setting the numerator

            if (temp!=0) //temp saves some processing time
            {
                strs<<temp<<'/'<<calculator.finalAnswer.getDenominator(); //outputs the numerator/denominator
            }

        }
    }
    else //whole number is 0, numerator is 0, so final answer is 0
    {
        strs<<'0'<<std::endl;
    }

    ui->display->setText(strs.str().c_str());//string stream is converted into a string which is converted into a cstring, which is given to qstring

}

void MainWindow::outputShunt(parser<char> calculator)
{
    //get parser q, convert to qstring, output

    queue<char> tempQueue=calculator.getPostfix();
    string tempString="";
    char tempChar;

    for (unsigned int i=0;i<calculator.getPostfix().getSize();i++)
    {
        tempQueue.pop(tempChar);
        tempString=tempString+tempChar;
    }

    ui->postFix->setText(tempString.c_str());
}

void MainWindow::updateDisplay(char number)
{
    QString line = ui->display->text();
    if(newEntry)
    {
        newEntry = false;
        line = "";
    }
    line = line + number;
    ui->display->setText(line);
}
