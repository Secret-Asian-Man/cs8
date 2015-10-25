#ifndef MIXEDNUMBERSV2_H
#define MIXEDNUMBERSV2_H
#include "fraction.h"

class mixedNumbersV2: public fraction
{
public:
    //Fractions are not stored as simplified versions, but simplified just for displaying

    //constructors
    mixedNumbersV2(int wholeNumber=0, int numer=0, int denom=1);
    mixedNumbersV2(const mixedNumbersV2 &other);
    mixedNumbersV2(const fraction &other);
    mixedNumbersV2(double number);
    //destructor
    ~mixedNumbersV2();


    //operators
    friend
    std::ostream& operator<<(std::ostream& out, const mixedNumbersV2& other);
    friend
    std::istream& operator>>(std::istream& in,  mixedNumbersV2& other);



};

#endif // MIXEDNUMBERSV2_H
