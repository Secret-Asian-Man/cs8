/**
    CS8
    main.cpp
    Purpose: Praticing Heaps

    @author David Wu
    @version 1.0.0 (2:48 PM Thursday, November 12, 2015)
*/

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <vector>
#include "heap.h"

using namespace std;

void loadList(vector<int> &list);
void display(char *title, const vector<int> &list);
void loadHeap(heap<int> &myHeap, const vector<int> &list);
void reloadList(heap<int> &myHeap,vector<int> &list);


int main()
{
    // ERROR: both reheapfies swap ALOT, but nothing actually gets changed! WHY!@!@!@



    try{
        heap<int> myHeap;
        vector<int> list;
        srand(time(NULL));

        loadList(list);
        display("Unsorted", list);
        loadHeap(myHeap, list); //fails here
        std::cout<<"DEBUG 11111111111111111111111111 "<<std::endl;
        reloadList(myHeap,list);
        std::cout<<"DEBUG 99999999999999999999999999 "<<std::endl;

        display("Sorted", list);
    }
    catch(HEAP_ERRORS error)
    {
        switch (error)
        {
        case EMPTY:
            std::cout<<"ERROR Tree is empty!! "<<std::endl;
            break;

        default:
            cout<<"Unknown Heap error..."<<endl;
            break;
        }
    }

    return 0;
}

void loadList(vector<int> &list)
{
    //    for(int i = 0; i < 10; ++i)
    //        list.push_back((int)pow(-1.,rand()%2)*(rand()%1001));

    list.push_back(2);
    list.push_back(5);
    list.push_back(1);
    list.push_back(4);
    list.push_back(7);
    list.push_back(5);




//    list.push_back(8);
//    list.push_back(20);
//    list.push_back(-5);
//    list.push_back(4);
}

void display(char *title, const vector<int> &list)
{
    cout<<title<<" list: ";
    for(unsigned int i = 0; i < list.size(); ++i)
    {
        if(!(i%10))
            cout<<endl;
        cout<<setw(6)<<list[i];
    }
    cout<<endl<<endl;
}

void loadHeap(heap<int> &myHeap,const vector<int> &list)
{
    for(unsigned int i = 0; i < list.size(); ++i)
    {
        myHeap << list[i];
    }

}

void reloadList(heap<int> &myHeap,vector<int> &list)
{

   std::cout<<"DEBUG 222222222222222222222222 "<<std::endl;
    for(unsigned int i = 0; i < list.size(); ++i)
    {
        myHeap >> list[i];
    }
}
































