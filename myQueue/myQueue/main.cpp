#include <iostream>
#include <string>
#include "driver.h"

using namespace std;

int main()
{
    try{
          queue<char> one, two;
          char ans;
          int que = 1;
          string title[13] = {
              " Please make a selection: ",
              "  S : Select a queue",
              "  R : Read from a file",
              "  W : Write to a file",
              "  P : Print the queue",
              "  + : Enqueue an item",
              "  - : Dequeue an item",
              "  M : Merge Queue 2 into Queue 1",
              "  Q : Quit",
              "Your selection: "};
          system("cls");
        /*  try
          {
            checkArgs(argc, argv, one, two, que);
          }
          catch(int e)
          {
             cout<<"Error "<<e<<". Program terminating"<<endl;
             exit(e);
          }*/

            while(toupper(ans = menu(title)) != 'Q')
               perform(ans, que,  one, two);






//        queue<int> testQ1;
//        queue<int> testQ2;

//        testQ1.enqueue(1);
//        testQ1.enqueue(2);
//        testQ1.enqueue(3);

//        testQ2.enqueue(4);
//        testQ2.enqueue(5);
//        testQ2.enqueue(6);

//        testQ1.merge(testQ2);

//        std::cout<<"testQ1 : "<<testQ1<<std::endl;
//        std::cout<<"testQ2 : "<<testQ2<<std::endl;


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
