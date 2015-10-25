#include <iostream>
#include <arraydqueue.h>
using namespace std;

int main()
{
    try
    {
        arrayDQueue<int> test;

        test.pushAtBack(111);
        test.pushAtBack(222);
        test.pushAtBack(333);
        test.pushAtBack(444);
        std::cout<<"DEBUG test original: "<<test<<std::endl;

        cout<<"back popped: "<<test.popAtBack()<<endl;
        cout<<"back popped: "<<test.popAtBack()<<endl;
        cout<<"back popped: "<<test.popAtBack()<<endl;
        cout<<"back popped: "<<test.popAtBack()<<endl;

        std::cout<<"DEBUG test: "<<test<<std::endl;
    }
    catch (DQUEUE_ERRORS error)
    {
        switch (error)
        {
        case DQUEUE_EMPTY:
            std::cout<<"ERROR DQUEUE_EMPTY: "<<std::endl;
            break;

        case DQUEUE_FULL:
            std::cout<<"ERROR DQUEUE_FULL: "<<std::endl;
            break;

        case DQUEUE_ILLEGAL_SIZE:
            std::cout<<"ERROR DQUEUE_ILLEGAL_SIZE: "<<std::endl;
            break;

        default:
            cout<<"DQUEUE UNKNOWN ERROR"<<endl;
            break;
        }
    }

    return 0;
}


