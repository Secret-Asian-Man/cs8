#include "mixednumbersv2.h"

mixedNumbersV2::mixedNumbersV2(int wholeNumber, int numer, int denom)
{
    numerator=numer+(wholeNumber*denom);
    denominator=denom;
}

mixedNumbersV2::mixedNumbersV2(const mixedNumbersV2 &other)
{
    numerator=other.numerator;
    denominator=other.denominator;
}

mixedNumbersV2::mixedNumbersV2(const fraction &other)
{
    numerator=other.getNumerator();
    denominator=other.getDenominator();
}

mixedNumbersV2::mixedNumbersV2(double number):fraction(number)
{

    //BLANK

}

mixedNumbersV2::~mixedNumbersV2()
{
    numerator=0;
    denominator=1;
}

std::ostream& operator<<(std::ostream &out, const mixedNumbersV2 &other)
{
    int simple=other.getNumerator()/other.getDenominator();

    if (out==std::cout)
    {
        if (other.getNumerator())
        {
            if (simple!=0) //if factorable. Takes advantage of int dropping decimals
            {



                std::cout<<simple<<" "; //The whole number
                int temp=abs(other.getNumerator())%other.getDenominator();
                if (temp!=0) //temp saves some processing time
                {
                    std::cout<<temp<<"/"<<other.getDenominator();
                }
                std::cout<<std::endl;
            }
            else
            {
                int temp=other.getNumerator()%other.getDenominator();
                if (temp!=0) //temp saves some processing time
                {
                    std::cout<<temp<<"/"<<other.getDenominator();
                }

            }
        }
        else
        {
            std::cout<<"0"<<std::endl;

        }


    }
    else
    {

    }

    return out;
}

std::istream& operator>>(std::istream &in,  mixedNumbersV2 &other)
{
    int whole=0;
    int numer=0;
    int denom=0;
    char dummy= ' ';

    if (in== std::cin)
    {
        std::cout<<"Input fraction (ie. 0 1/2): ";
        std::cin>>whole;
        std::cin>>numer;
        std::cin>>dummy;
        std::cin>>denom;


        numer=(whole*denom)+numer;
        other.setBoth(numer,denom);

    }
    else
    {

    }

    return in;
}

