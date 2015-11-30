#include "creditcard.h"

enum ERROR{fileNotFound};


CreditCard::CreditCard()
{
    creditCardNumber="";
    checkSum=' ';
}

CreditCard::CreditCard(char cardType, char whichBank)
{
    creditCardNumber=generateCreditCardNumber(cardType,whichBank);
    checkSum=generateCheckSum(creditCardNumber);

}

CreditCard::CreditCard(std::string newCreditCardNumber)
{
    creditCardNumber=newCreditCardNumber;
    checkSum=generateCheckSum(newCreditCardNumber);
}

CreditCard::CreditCard(const CreditCard &other)
{
    creditCardNumber=other.creditCardNumber;
    checkSum=other.checkSum;
}

CreditCard::~CreditCard()
{
    creditCardNumber="";
    checkSum=' ';

    file.close();

}

std::string CreditCard::getCreditCardNumber()
{
    return creditCardNumber;
}

void CreditCard::setCreditCardNumber(std::string newCreditCardNumber)
{
    creditCardNumber=newCreditCardNumber;
}

CreditCard &CreditCard::operator =(const CreditCard &other)
{
    if (this != &other)
    {
        creditCardNumber=other.creditCardNumber;
        checkSum=other.checkSum;
    }
    return *this;
}

string CreditCard::generateCreditCardNumber(char cardType, char whichBank)
{

}

char CreditCard::generateCheckSum(std::string numbers)
{
    unsigned int sum=0;
    bool toggle=true;
    unsigned int checkDigit=0;


    while(!numbers.empty())
    {
        unsigned int temp=numbers.back() - '0'; //saves last digit

        if (toggle)
        {
            temp= temp*2;

            if (temp>=10)
                temp=temp-9;
        }

        sum=sum+temp;

        toggle=!toggle;
        numbers.pop_back(); //deletes last digit
    }

    checkDigit= (sum*9)%10;

    return checkDigit+'0';
}

bool CreditCard::Validate(std::string creditCardNumber)
{
    unsigned int sum=0;
    bool toggle=true;
    unsigned int otherCheckDigit=creditCardNumber.back() - '0';
    unsigned int myCheckDigit=0;

    creditCardNumber.pop_back();

    while(!creditCardNumber.empty())
    {
        unsigned int temp=creditCardNumber.back() - '0'; //saves last digit

        if (toggle)
        {
            temp= temp*2;

            if (temp>=10)
                temp=temp-9;
        }

        sum=sum+temp;

        toggle=!toggle;
        creditCardNumber.pop_back(); //deletes last digit
    }

    myCheckDigit= (sum*9)%10;

    return (otherCheckDigit==myCheckDigit);
}

void CreditCard::loadFile()
{

}

std::string &CreditCard::readFile()
{
    //use .ignore to skip characters
}

void CreditCard::replaceSpaceWithUnderScore(std::string &input)
{
    for (int i=0;i<input.size();i++)
        if (input[i]==' ')
            input[i]='_';
}

void CreditCard::listBanknames(string creditCardType)
{
    string temp="../resources/" + creditCardType + ".dat";
    file.open(temp);

    if (!file.is_open())
        throw fileNotFound;




}

bool CreditCard::firstOf(std::string compare, char key)
{

    for (unsigned int i=0;i<compare.size();++i)
        if (key==compare[i])
            return true;

    return false;
}

bool CreditCard::firstNotOf(std::string compare, char key)
{
    for (unsigned int i=0;i<compare.size();++i)
        if (key!=compare[i])
            return true;

    return false;

}
