#include <iostream>
#include "prioritydeque.h"

using namespace std;

int main()
{
    try
    {
        PDeque<int> test;

        test.pushAtBack(1);
        test.pushAtBack(12);
        test.pushAtBack(123,5);
        test.pushAtBack(1234);
        test.pushAtFront(48486,-56);
        test.pushAtBack(12345);
        test.pushAtBack(123456,23);
        cout<<test<<endl;

        std::cout<<"Popped: "<<test.popAtBack()<<std::endl;
        std::cout<<"Popped: "<<test.popAtBack()<<std::endl;
        std::cout<<"Popped: "<<test.popAtFront()<<std::endl;
        std::cout<<"Popped: "<<test.popAtBack()<<std::endl;

        cout<<test<<endl;

    }
    catch(PDEQUE_ERRORS error)
    {
        switch (error)
        {

        case PDEQUE__EMPTY:
            std::cout<<"ERROR PDEQUE__EMPTY: "<<std::endl;
            break;

        case PDEQUE__FULL:
            std::cout<<"ERROR PDEQUE__FULL: "<<std::endl;
            break;


        case PDEQUE__ILLEGAL_SIZE:
            std::cout<<"ERROR PDEQUE__ILLEGAL_SIZE: "<<std::endl;
            break;


        default:
            cout<<"PDEQUE UNKNOWN ERROR..."<<endl;
            break;
        }
    }



    return 0;
}

