#include "fraction.h"
#include <cmath>
#include <iostream>

fraction::fraction(int num, int denom):numerator(num), denominator(denom)
{
    int gcf=greatestCommonFactor(num,denom);

    numerator=num/gcf;
    denominator=denom/gcf;
}

fraction::fraction(double number)//1.55
{
    numerator=0;
    denominator=1;

    decimalToFraction(number,numerator,denominator);


    int gcf=greatestCommonFactor(numerator,denominator);


    numerator=numerator/gcf;
    denominator=denominator/gcf;

}


fraction::~fraction()
{
    numerator=0;
    denominator=1;
}

int fraction::getNumerator() const
{
    return numerator;
}

int fraction::getDenominator() const
{
    return denominator;
}

void fraction::getBoth(int &num, int &denom) const
{
    num=numerator;
    denom=denominator;
}

double fraction::getDecimal() const
{
    return (double)numerator/denominator;
}

fraction fraction::getFraction() const //allows the child:mixedNumbers, access to the parent(fractions)
{
    return *this;
}

void fraction::setNumerator(int num)
{
    int gcf=greatestCommonFactor(num,denominator);

    numerator=num/gcf;
    denominator=denominator/gcf;
}

void fraction::setDenominator(int denom)
{
    int gcf=greatestCommonFactor(numerator,denom);

    numerator=numerator/gcf;
    denominator=denom/gcf;
}

void fraction::setBoth(int num, int denom)
{
    int gcf=greatestCommonFactor(num,denom);

    numerator=num/gcf;
    denominator=denom/gcf;
}

void fraction::print()
{
    std::cout<<numerator<<"/"<<denominator;
}

fraction &fraction::operator=(const fraction &other)
{
    numerator=other.numerator;
    denominator=other.denominator;

    return *this;
}

fraction fraction::operator+(const fraction &other)
{
    fraction temp(((numerator*other.denominator)+(denominator*other.numerator)),denominator*other.denominator);
    return temp;
}

fraction fraction::operator-(const fraction &other)
{
    fraction temp(((numerator*other.denominator)-(denominator*other.numerator)),denominator*other.denominator);
    return temp;
}

fraction fraction::operator/(const fraction &other)
{
    fraction temp(numerator*other.denominator,denominator*other.numerator);
    return temp;
}

fraction fraction::operator*(const fraction &other)
{
    fraction temp(numerator*other.numerator,denominator*other.denominator);
    return temp;
}

std::ostream& operator<<(std::ostream &out, const fraction &other)
{
    if (std::cout==out)
    {
        std::cout<<other.numerator<<"/"<<other.denominator;
    }
    else
    {

    }

    return out;
}

/***********************************
 * Function: greatestCommonFactor
 * Purpose: finds the greatest common factor between 2 numbers
 * Parameters: 2 numbers
 * Returns: the greatest common factor
 * Summary:
 * Notes:
 * ***********************************/
int fraction::greatestCommonFactor(int num1, int num2)
{
    //euclidean algorith
    if (num1 && num2)
    {
        num1=abs(num1);
        num2=abs(num2);

        while(num1!=num2)

        {
            //subtracts the lesser number
            if(num1>num2)
                num1=num1-num2;
            else
                num2=num2-num1;
        }

        return num1;
    }
    return 1;

}



void fraction::decimalToFraction(double input, int &numer, int &denom, int decimalPlaces)
{
    if (input!=0.0)
    {
        int whole=(int)input;//1
        int precision=1;
        numer=0;
        denom=1;




        for (int i=0;i<decimalPlaces;i++)
            precision=precision*10;

        double decimal=(round((input*precision)-(whole*precision)));//PROBLEM HERE, 1.4999999999999 when input is 1.5




        denom=denom*precision;
        numer=decimal;

        numer=numer+(whole*denom);
    }


}
