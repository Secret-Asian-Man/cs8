#include "fraction.h"
#include <cmath>
#include <iostream>

fraction::fraction(int num, int denom):numerator(num), denominator(denom)
{
    int gcf=greatestCommonFactor(num,denom);

    numerator=num/gcf;
    denominator=denom/gcf;
}

fraction::fraction(double number)
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

void fraction::setBoth(double input)
{
    decimalToFraction(input,numerator,denominator);

    int gcf=greatestCommonFactor(numerator,denominator);

    numerator=numerator/gcf;
    denominator=denominator/gcf;
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

fraction fraction::operator+(const fraction &other) //adds 2 fractions together
{
    fraction temp(((numerator*other.denominator)+(denominator*other.numerator)),denominator*other.denominator);
    return temp;
}

fraction fraction::operator-(const fraction &other) //subtracts 2 fractions
{
    fraction temp(((numerator*other.denominator)-(denominator*other.numerator)),denominator*other.denominator);
    return temp;
}

fraction fraction::operator/(const fraction &other) //divides 2 fractions
{
    fraction temp(numerator*other.denominator,denominator*other.numerator);
    return temp;
}

fraction fraction::operator*(const fraction &other) //multiplies 2 fractions
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
    else // add to file
    {

    }

    return out;
}

int fraction::greatestCommonFactor(int num1, int num2)
{
    //euclidean algorithm
    if (num1 && num2) //if num1 != 0 && num2 != 0
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
    return 1; //returns 1 if a factor is not found
}


//doubles are inaccurate, so this functions is a workaround using a specified decimal place.
void fraction::decimalToFraction(double input, int &numer, int &denom, int decimalPlaces)
{
    if (input!=0.0)
    {
        int whole=(int)input;//drops the decimals off the double
        int precision=1; //for decimal places
        numer=0;
        denom=1;

        for (int i=0;i<decimalPlaces;i++)//sets number acurracy
            precision=precision*10;

        double decimal=(round((input*precision)-(whole*precision)));//cuts off the number at the specified decimal place then rounds the number

        denom=denom*precision;
        numer=decimal;

        numer=numer+(whole*denom); //sets improper fraction
    }

}
