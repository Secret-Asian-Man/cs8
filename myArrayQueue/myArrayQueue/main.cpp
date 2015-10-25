#include <iostream>
#include <string>
#include "driver.h"

using namespace std;

int main()
{
    try{
        //          queue<char> one, two;
        //          char ans;
        //          int que = 1;
        //          string title[13] = {
        //              " Please make a selection: ",
        //              "  S : Select a queue",
        //              "  R : Read from a file",
        //              "  W : Write to a file",
        //              "  P : Print the queue",
        //              "  + : Enqueue an item",
        //              "  - : Dequeue an item",
        //              "  M : Merge Queue 2 into Queue 1",
        //              "  Q : Quit",
        //              "Your selection: "};
        //          system("cls");

        //            while(toupper(ans = menu(title)) != 'Q')
        //               perform(ans, que,  one, two);




int dummy=0;

        queue<int> testQ1;
        testQ1.push(1);
        testQ1.push(22);
        testQ1.push(333);


        std::cout<<"testQ1 : "<<testQ1<<std::endl;

        testQ1.pop(dummy);
        std::cout<<"DEBUG dummy: "<<dummy<<std::endl;

        testQ1.pop(dummy);
        std::cout<<"DEBUG dummy: "<<dummy<<std::endl;

        testQ1.pop(dummy);
        std::cout<<"DEBUG dummy: "<<dummy<<std::endl;


    } catch (QUEUE_ERRORS error)
    {
        switch (error)
        {
        case EMPTY:
            std::cout<<"ERROR EMPTY: "<<std::endl;
            break;

        case FULL:
            std::cout<<"ERROR FULL: "<<std::endl;
            break;

        case ILLEGAL_SIZE:
            std::cout<<"ERROR ILLEGAL_SIZE: "<<std::endl;
            break;

        default:
            cout<<"Invalid key..."<<endl;
            break;
        }
    }

    return 0;
}
