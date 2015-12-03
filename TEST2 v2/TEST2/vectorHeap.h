#ifndef VECTORHEAP
#define VECTORHEAP

#include <iostream>
#include <bitset>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <fstream>

using std::bitset;
using std::string;


enum HEAP_ERRORS { EMPTY };
enum HEAP_TYPE { LESSTHAN, GREATERTHAN };
enum HEAP_BRANCH { LEFT, RIGHT };

template<typename T>
class vectorHeap
{
public:
    typedef bool (vectorHeap<T>::*fptr)(const T &x,const  T &y);

    //Constructors
    vectorHeap(HEAP_TYPE t = LESSTHAN);
    vectorHeap(const vectorHeap<T> &other);


    //Destructor
    ~vectorHeap();


    //Accessors
    long int getCount();


    //Mutators


    //Operators
    vectorHeap<T>& operator=(const vectorHeap<T> &other);
    vectorHeap<T>& operator<<(const T &data);
    vectorHeap<T>& operator>>(T &data);


    //Functions
    void clear();
    void AlexPrint(long int root, long int depth) const;
    void insert(const T &data);
    T remove();
    void printAll(/*std::ofstream out=std::cout, bool saveToFile=false, string fileName=""*/);

private:

    //Private Member Variables
    std::vector<T> list;
    long int lastChildEntered;
    HEAP_TYPE heapType;
    fptr heapSortingMethod[2];

    //Private Functions
    void copy(const vectorHeap<T> &otherHeap);
    bool lessThan(const T &x,const  T &y);
    bool greaterThan(const T &x,const  T &y);
    T smallerOf(const T& a, const T &b);
    T biggerOf(const T& a, const T &b);
    long int findLastChild();
    long int findParent(long int childNumber);
    void reheapifyDown();
    void reheapifyUp();
    void swap(T &x, T &y);
    long int findDepth(long int childIdNumber);








};

template<typename T>
vectorHeap<T>::vectorHeap(HEAP_TYPE t)
{
    lastChildEntered = 0;
    heapType = t;
    heapSortingMethod[LESSTHAN] = &vectorHeap<T>::lessThan;
    heapSortingMethod[GREATERTHAN] = &vectorHeap<T>::greaterThan;
}

template<typename T>
vectorHeap<T>::~vectorHeap()
{
    list.clear();
    lastChildEntered=0;
}

template<typename T>
vectorHeap<T>::vectorHeap(const vectorHeap<T> &other)
{
    copy(other);
}

template<typename T>
vectorHeap<T>& vectorHeap<T>::operator=(const vectorHeap<T> &other)
{
    if(this != &other)
    {
        list.clear();
        copy(other);
    }
    return *this;
}


template<typename T>
vectorHeap<T>& vectorHeap<T>::operator<<(const T &data)
{

    if(list.empty())
    {
        list.push_back(data);
        lastChildEntered = 1;
    }
    else
    {
        lastChildEntered++;

        list.push_back(data);
        reheapifyUp();
    }
    return *this;
}

template<typename T>
vectorHeap<T>& vectorHeap<T>::operator>>(T &data)
{
    //swap root with last element
    //delete last element

    if (list.empty())
        throw EMPTY;

    data=list[0];

    swap(list[0], list[findLastChild()]); //swaps once only



    std::cout<<"DEBUG popping: "<<list.back()<<std::endl;
    list.pop_back();

    --lastChildEntered;

    reheapifyDown();

    return *this;
}

template<typename T>
void vectorHeap<T>::clear()
{
    list.clear();
}

template<typename T>
void vectorHeap<T>::AlexPrint(long int root, long int depth) const
{
    if (!list.empty())
    {
        AlexPrint(list[2*root+1], depth + 1);
        for (long int i = 0; i < 2*depth; i++) std::cout << " ";
        std::cout << depth<<":";
        std::cout << list[root] << std::endl;
        AlexPrint(list[2*root+2], depth + 1);

    }
}

template<typename T>
long int vectorHeap<T>::getCount()
{
    return lastChildEntered;
}

template<typename T>
void vectorHeap<T>::insert(const T &data) //should work
{
    if(list.empty())
    {
        list.push_back(data);
        lastChildEntered = 1;
    }
    else
    {
        lastChildEntered++;

        list.push_back(data);
        reheapifyUp();
    }
}

template<typename T>
T vectorHeap<T>::remove() //should work
{
    if (list.empty())
        throw EMPTY;

    T data=list[0];

    swap(list[0], list[findLastChild()]); //swaps once only

    list.pop_back();

    --lastChildEntered;

    reheapifyDown();

    return data;
}

template<typename T>
void vectorHeap<T>::printAll(/*std::ofstream out, bool saveToFile, string fileName*/)
{
    //the act of printing destroys the heap
    //out or cout?
    std::cout<<"DEBUG 11111111111111111111 "<<std::endl;

    while(!list.empty())
    {    std::cout<<"DEBUG 222222222222222222222222 "<<std::endl;


        std::cout<<remove()<<"\n";
    }





//    if (saveToFile && out != std::cout) //saves to file
//    {
//        out.open(fileName.c_str());

//        if (out.is_open())
//            while(!list.empty())
//                out<<remove()<<"\n";

//        out.close();
//    }
//    else //prints to console
//    {
//        while(!list.empty())
//           out<<remove()<<"\n";
//    }


    //    in the tree of words, I want to run the print function of each.
    //    I also want to be able to save the print to a file
}

template<typename T>
void vectorHeap<T>::copy(const vectorHeap<T> &otherHeap)
{
    list.clear();
    list=otherHeap.list;
    lastChildEntered=otherHeap.lastChildEntered;
}

template<typename T>
long int vectorHeap<T>::findLastChild()
{
    return list.size()-1;
}

template<typename T>
long int vectorHeap<T>::findParent(long int childNumber) //can find myself with parent->which[lastChildEntered%2]
{
    if((childNumber-1)/2 <= 0)
        return 0;

    return (childNumber-1)/2;
}

template<typename T>
void vectorHeap<T>::reheapifyDown() //for removing root
{
    //reheapify down by swapping new root with the bigger of the 2 children until NULL.
    //NOTE: In a heap, a LEFT child CAN exist without a brother, but a a RIGHT child CANNOT exist without a brother

    long int walker=0;
    bool loopAgain=true;

    while(walker < lastChildEntered-1 && loopAgain)
    {
        std::cout<<"=========== "<<std::endl;
        for (unsigned int i=0;i<list.size();++i)
        {
            std::cout<<list[i]<<"_";
        }
        std::cout<<std::endl<<"^^^^^^^^^^^ "<<std::endl;

        if(2*walker+1 < lastChildEntered-1 && 2*walker+2 <= lastChildEntered-1)//if there is left AND right child //OPTIMIZABLE
        {
            if(list[2*walker+1] < list[2*walker+2])//if left child is smaller. If negative left is smaller, if positive right is smaller
            {
                swap(list[walker],list[2*walker+1]);
                walker=2*walker+1;
            }
            else//right child must be bigger or equal
            {
                swap(list[walker],list[2*walker+2]);
                walker=2*walker+2;
            }
        }
        else if(2*walker+1 < lastChildEntered-1)
        {
            swap(list[walker],list[2*walker+1]);
            walker=2*walker+1;
        }
        else
        {
            loopAgain=false;
        }
    }
}

template<typename T>
void vectorHeap<T>::reheapifyUp() //for inserting
{
    //insert at last element
    //folowing the last element, check if the parent is greater, if it is, swap the two.

    long int walker=lastChildEntered-1; //lastChildEntered acts like a size

    //this function only gets called if lastChildEntered is at least 2
    while(list[(walker-1)/2] > list[walker]) //OPTIMIZABLE: possibly create new variable to do the math
    {
        swap(list[walker],list[(walker-1)/2]);
        walker= (walker-1)/2; //works because integer division takes care of exceptions
    }

}


template<typename T>
void vectorHeap<T>::swap(T &x, T &y)
{
    T temp = x;
    x = y;
    y = temp;
}

template<typename T>
long int vectorHeap<T>::findDepth(long int childIdNumber) //0 based, finds the depth of the given child id
{
    long int depth=floor(log10(childIdNumber*1.)/log10(2.));

    return depth;
}

template<typename T>
bool vectorHeap<T>::lessThan(const T &x,const  T &y)
{
    return x < y;
}

template<typename T>
bool vectorHeap<T>::greaterThan(const T &x,const  T &y)
{
    return x > y;
}

template<typename T>
T vectorHeap<T>::smallerOf(const T& a, const T &b)
{
    if(a<b)
        return a;
    else
        return b;
}

template<typename T>
T vectorHeap<T>::biggerOf(const T& a, const T &b)
{
    if(a>b)
        return a;
    else
        return b;
}

#endif // VECTORHEAP

