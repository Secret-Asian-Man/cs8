/**
    CS8
    main.cpp
    Purpose: Making Credit Cards

    @author David Wu
    @version 1.0.0 (12:55 AM Tuesday, November 17, 2015)
*/

#include <iostream>
#include <fstream>

using namespace std;


void getInput(string &cardCarrier, string &bank, string &creditOrDebit, string &cardType, unsigned int &amount=1);
void loadFile(istream &file);
string& readFile();
char generateCheckSum(string numbers); //checks if you mistyped a credit card number
bool Validate(string creditCardNumber);
void replaceSpaceWithUnderScore(string &input);
void getInput(string &container);


int main()
{
    //what kind of card (visa, mastercard), which bank, what type of card (gold, platnium), how many
    //check for duplicates (master card has duplicates every other one)

    if (luhnAlgorithmValidate("4147202107313437"))
    {
        std::cout<<"DEBUG VALID!: "<<std::endl;
    }
    else
    {
        std::cout<<"DEBUG INVALID!!!!!!!!: "<<std::endl;

    }


    //start at '' continue until  not a number


    return 0;
}

/**
    Checks if credit card number is valid

    @param numbers: the credit card number
    @return returns true is valid number, false if not.
*/
char generateCheckSum(string numbers)
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


bool Validate(string creditCardNumber)
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

void getInput(string &bank, string &location, string &creditOrDebit, string &cardType, unsigned int &amount=1)
{
    std::cout<<"Pick a bank: "<<endl;
    getinput(bank);
    replaceSpaceWithUnderScore(bank);

    std::cout<<"Pick a location: "<<endl;
    getinput(location);
    replaceSpaceWithUnderScore(location);

    std::cout<<"Credit or Debit? : "<<endl;
    getInput(creditOrDebit);

    std::cout<<"What kind of card do you want? : "<<endl;
    getInput(cardType);

    std::cout<<"How many cards do you want? : "<<endl;
    cin<<amount;


}

void replaceSpaceWithUnderScore(string &input)
{
    for (int i=0;i<input.size();i++)
        if (input[i]==' ')
            input[i]='_';
}


void getInput(string &container)
{
    char userInput;

    do
    {
        cin.get(userInput);
        container.push_back(userInput);

    } while(userInput!= 10);

}


















