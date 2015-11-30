
//http://null-byte.wonderhowto.com/how-to/credit-card-algorithms-work-anatomy-credit-card-numbers-0132295/
//there is the same number of characters separating the digits from the name (4)
#ifndef CREDITCARD_H
#define CREDITCARD_H
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

using std::string;
using std::cout;

class CreditCard
{
public:


    //Constructors
    CreditCard();
    CreditCard(char cardType, char whichBank);
    CreditCard(string newCreditCardNumber);
    CreditCard(const CreditCard &other);


    //Destructor
    ~CreditCard();

    //Accessors
    string getCreditCardNumber();


    //Mutators
    void setCreditCardNumber(string newCreditCardNumber);

    //Operators
    CreditCard& operator =(const CreditCard &other);

    //Functions
    std::string generateCreditCardNumber(char cardType, char whichBank);
    char generateCheckSum(string numbers); //checks if you mistyped a credit card number
    bool Validate(string creditCardNumber);



private:

    //Private Member Variables
    string creditCardNumber;
    char checkSum;
    std::ifstream file;

    //Private Functions
    void loadFile();
    string& readFile();
    void replaceSpaceWithUnderScore(string &input);
    void listBanknames(std::string creditCardType);
    bool firstOf(string compare, char key);
    bool firstNotOf(string compare, char key);


};

#endif // CREDITCARD_H
