#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>
#include <fstream>

class fraction
{
public:
    //constructors
    fraction(int num=0,int denom=1);
    fraction(double number);

    //destructor
    ~fraction();

    //accessors
    int getNumerator()const;
    int getDenominator()const;
    void getBoth(int &num, int &denom)const;
    double getDecimal()const;
    fraction getFraction() const;

    //mutators
    void setNumerator(int num);
    void setDenominator(int denom);
    void setBoth(int num, int denom);
    void setBoth(double input);

    //functions
    void print();

    //operators
    friend
    std::ostream& operator<<(std::ostream& out, const fraction &other);

    fraction& operator=(const fraction& other);

    fraction operator+(const fraction &other);
    fraction operator-(const fraction &other);
    fraction operator/(const fraction &other);
    fraction operator*(const fraction &other);


protected:
    int numerator;
    int denominator;


private:
    int greatestCommonFactor(int num1, int num2);
    void decimalToFraction(double input, int &numer, int &denom, int decimalPlaces=5);

};

#endif // FRACTION_H
