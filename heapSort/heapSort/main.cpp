#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <iomanip>

using namespace std;

int getInput(char *title, int low = -32768, int high = 32767);
void initialize(vector<int> &list, int qty, int low, int high);
void display(char *title, const vector<int> &list, int low, int high);
void heapSort(vector<int> &list);
void swap(int &a, int &b);


int main()
{
    int low, high, qty;
    vector<int> list;
    srand(time(NULL));
    low = getInput("What is the lowest number to put into the list? ");
    high = getInput("What is the highest number to put into the list? ", low);
    qty = getInput("How many random numbers to put into the list? ", 1, high);
    initialize(list, qty, low, high);
    display("Unsorted list of random numbers: ", list, low, high);
    heapSort(list);
    display("Sorted list of random numbers: ", list, low, high);
    return 0;
}


int getInput(char *title, int low , int high )
{
    int val;
    bool cont = true;
    do
    {
        cout<<title;
        cin>>val;
        if(val < low || val > high)
        {
            cout<<"Please re-enter. Input out of range.";
        }
        else
            cont = false;
    }while(cont);
    return val;
}

void initialize(vector<int> &list, int qty, int low, int high)
{
    for(int i = 0; i < qty; ++i)
        list.push_back(low + rand()%(abs(high-low)+1));
}

void display(char *title, const vector<int> &list, int low, int high)
{
    int i = 0, colWidth = 7 , cols = 8;
    cout<<title<<endl;
    for(;i < list.size(); ++i)
    {
        if(!(i%cols))
            cout<<endl;
        cout<<setw(colWidth)<<list[i];
    }
    if((i%cols))
        cout<<endl;
    cout<<endl;
}

void heapSort(vector<int> &list)
{
    //Build a heap for the first element down to the last
    int parent, child = 0, lChild, rChild, compareChild;
    for(int i = 0; i < list.size();++i)
    {
        child = i;
        parent = child/2;
        while(child && (list[parent] < list[child]) )
        {
            swap(list[parent], list[child]);
            child = parent;
            parent = child/2;
        }
    }
    //Re-heapify down after removing the root
    for(int i = list.size()-1; i >= 0; --i)
    {
        swap(list[0], list[i]); //Remove the root
        parent = 0;
        bool cont = true;
        while( cont && (parent < i/2))
        {    
            lChild = parent*2;
            rChild = parent*2 + 1;
            if(rChild > i)
                compareChild = lChild;
            else
                compareChild = list[lChild] > list[rChild]
                               ?
                                lChild : rChild;
            if(list[parent] < list[compareChild])
            {
                swap(list[parent], list[compareChild]);
                parent = compareChild;
            }
            else
                cont = false;
         }
    }
}

void swap(int &a, int &b)
{
   // a ^= b ^= a ^= b;
   int temp = a;
   a = b;
   b = temp;
}
