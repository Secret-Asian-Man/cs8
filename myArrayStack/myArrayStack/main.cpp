#include <iostream>
#include "stack.h"
#include <string>

using namespace std;

//string getLine();
//void perform(string line);
//string trimAndNormalize(string line);

int main()
{
    try
    {
        stack<int> testStack;

        int dummy=0;

        testStack.push(111);
        testStack.push(222);
        testStack.push(333);
        testStack.push(444);
        testStack.push(555);

        cout<<"testStack1111: "<<testStack<<endl;

        std::cout<<"DEBUG peek : "<<testStack.peek()<<std::endl;
        testStack.pop(dummy);
        std::cout<<"DEBUG popped dummy: "<<dummy<<std::endl;
        std::cout<<"DEBUG peek : "<<testStack.peek()<<std::endl;
        testStack.pop(dummy);
        std::cout<<"DEBUG popped dummy: "<<dummy<<std::endl;
        std::cout<<"DEBUG peek : "<<testStack.peek()<<std::endl;
        testStack.pop(dummy);
        std::cout<<"DEBUG popped dummy: "<<dummy<<std::endl;
        std::cout<<"DEBUG peek : "<<testStack.peek()<<std::endl;
        testStack.pop(dummy);
        std::cout<<"DEBUG popped dummy: "<<dummy<<std::endl;

        cout<<"testStack222222: "<<testStack<<endl;



//        stack<int> testStack2;
//        cout<<"testStack2: "<<testStack2<<endl;


        //        int tempT=0;
        //        while(!testStack.empty())
        //        {

        //            testStack.pop(tempT);
        //            std::cout<<"DEBUG testStack.pop(): "<<tempT<<std::endl;

        //        }





    }
    catch(STACK_ERRORS error)
    {

        switch (error)
        {

        case EMPTY:
            std::cout<<"error EMPTY: "<<std::endl;
            break;

        case FULL:
            std::cout<<"error FULL: "<<std::endl;
            break;

        case ILLEGAL_SIZE:
            std::cout<<"error ILLEGAL_SIZE: "<<std::endl;
            break;

        default:
            cout<<"Invalid key..."<<endl;
            break;
        }
    }











    //    try{
    //        string line;
    //        while((line = getLine()) != "")
    //            perform(line);
    //    }
    //    catch(STACK_ERRORS error)
    //    {
    //        switch (error)
    //        {
    //        case EMPTY:
    //            std::cout<<"ERROR EMPTY "<<std::endl;
    //            break;

    //        case FULL:
    //            std::cout<<"ERROR FULL "<<std::endl;

    //            break;

    //        case ILLEGAL_SIZE:
    //            std::cout<<"ERROR ILLEGAL_SIZE "<<std::endl;

    //            break;

    //        default:
    //            cout<<"Undefined Error..."<<endl;
    //            break;
    //        }
    //    }

    return 0;
}

//string getLine()
//{
//    string line;
//    cout<<"Input: ";
//    getline(cin, line);
//    return line;
//}

//void perform(string line)
//{
//    stack<char> myStack(line.size());
//    string normalized, reversed;
//    normalized = trimAndNormalize(line);
//    for(unsigned int i = 0; i < normalized.size(); i++)
//        myStack<<normalized[i];
//    while(!myStack.empty())
//        reversed += myStack.pop();
//    string isNot = reversed == normalized ? " is " : " is not ";
//    cout<<line<<isNot<<" a palindrome"<<endl;

//}


//string trimAndNormalize(string line)
//{
//    unsigned int pos;
//    for(unsigned int i = 0; i < line.size(); i++)
//        line[i] = toupper(line[i]);
//    while((pos = line.find("ABCDEFGHIJKLMNOPQRSTUVWXYZ")) < string::npos)
//        line.erase(pos,1);
//    return line;
//}
