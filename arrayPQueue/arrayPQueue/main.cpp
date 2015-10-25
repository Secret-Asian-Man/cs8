#include <iostream>
#include <pqueue.h>
using namespace std;

int main()
{
    try
    {
        PQueue<int> test;

        test.push(111);
        test.push(222,4);
        test.push(333);
        test.push(666,1);
        test.push(9,45120);
        test.push(551,-999);
        cout<<test<<endl;


        std::cout<<"DEBUG popped: "<<test.pop()<<std::endl;
        std::cout<<"DEBUG popped: "<<test.pop()<<std::endl;
        std::cout<<"DEBUG popped: "<<test.pop()<<std::endl;


        cout<<test<<endl;

    }
    catch (PQUEUE_ERRORS error)
    {
        switch (error)
        {
        case PQUEUE_EMPTY:
            std::cout<<"ERROR PQUEUE_EMPTY: "<<std::endl;
            break;

        case PQUEUE_FULL:
            std::cout<<"ERROR PQUEUE_FULL: "<<std::endl;
            break;


        case PQUEUE_ILLEGAL_SIZE:
            std::cout<<"ERROR PQUEUE_ILLEGAL_SIZE: "<<std::endl;
            break;


        default:
            cout<<"Invalid key..."<<endl;
            break;
        }
    }



    return 0;
}

