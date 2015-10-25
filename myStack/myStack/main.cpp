#include <iostream>
#include <iostream>
#include "stack.h"
#include <string>

using namespace std;

string getLine();
void perform(string line);
string trimAndNormalize(string line);

int main()
{
    try{
        string line;
        while((line = getLine()) != "")
            perform(line);
    }
    catch(BASE_STACK_ERRORS error)
    {
        switch (error)
        {
        case EMPTY:
            std::cout<<"ERROR EMPTY "<<std::endl;
            break;

        case FULL:
            std::cout<<"ERROR FULL "<<std::endl;

            break;

        case ILLEGAL_SIZE:
            std::cout<<"ERROR ILLEGAL_SIZE "<<std::endl;

            break;

        default:
            cout<<"Undefined Error..."<<endl;
            break;
        }
    }

    return 0;
}

string getLine()
{
    string line;
    cout<<"Input: ";
    getline(cin, line);
    return line;
}

void perform(string line)
{
    stack<char> myStack(line.size());
    string normalized, reversed;
    normalized = trimAndNormalize(line);
    for(unsigned int i = 0; i < normalized.size(); i++)
        myStack<<normalized[i];
    while(!myStack.empty())
        reversed += myStack.pop();
    string isNot = reversed == normalized ? " is " : " is not ";
    cout<<line<<isNot<<" a palindrome"<<endl;

}


string trimAndNormalize(string line)
{
    unsigned int pos;
    for(unsigned int i = 0; i < line.size(); i++)
        line[i] = toupper(line[i]);
    while((pos = line.find("ABCDEFGHIJKLMNOPQRSTUVWXYZ")) < string::npos)
        line.erase(pos,1);
    return line;
}
