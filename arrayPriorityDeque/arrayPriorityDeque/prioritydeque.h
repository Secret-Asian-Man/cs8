#ifndef PRIORITYDEQUE
#define PRIORITYDEQUE
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <string>

using std::istream;
using std::ostream;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::stringstream;

#define uint unsigned int

enum PDEQUE_ERRORS {PDEQUE__EMPTY, PDEQUE__FULL, PDEQUE__ILLEGAL_SIZE};


template<typename T>
class PDeque
{
public:
    PDeque(uint s = 100);
    PDeque(const T &data, uint s = 100, int priority=0);
    PDeque(const PDeque<T>& other);
    ~PDeque();

    PDeque<T>& operator=(const PDeque<T>& other);

    T peek();
    bool full();
    bool empty();
    void clear();
    uint getSize();
    void resize(uint s);

    void pushAtBack(const T& d, int priority=0);//from a normal queue
    T popAtFront();//from a normal queue

    void pushAtFront(const T& d, int priority=0);//for a dequeue
    T popAtBack();//for a dequeue

    PDeque<T>& operator<<(const T& d);
    PDeque<T>& operator>>(T& d);
    void merge(const PDeque<T> &other);

    template<typename U>
    friend
    ostream& operator<<(ostream &out, const PDeque<U> &q);

    template<typename U>
    friend
    istream& operator>>(istream &in,  PDeque<U> &q);

private:
    T* head;//head is the left //tail is size/size subtracted by 1
    int* priorityList;
    uint size;//tail is the right
    uint maxsize;

    //private functions

    void swap(T &data1, T &data2);
    void swap(unsigned int position1, unsigned int position2);
    void optimizeList();

    void nukem();
    void copy(const PDeque<T> &other);
};

template<typename T>
PDeque<T>::PDeque(uint s)
{
    size=0;
    maxsize=s;
    head= new T[size];
    priorityList=new int[size];

}

template<typename T>
PDeque<T>::PDeque(const T &data, uint s, int priority)
{
    if(s < 1)
        throw PDEQUE__ILLEGAL_SIZE;

    maxsize = s;
    size = 0;

    push(data, priority);
}

template<typename T>
PDeque<T>::PDeque(const PDeque<T>& other)
{
    size=0;
    maxsize=100;
    head= new T[size];


    nukem();
    copy(other);
}

template<typename T>
PDeque<T>::~PDeque()
{
    nukem();
}


template<typename T>
PDeque<T>& PDeque<T>::operator=(const PDeque<T>& other)
{
    if(this != &other)
    {
        nukem();
        copy(other);
    }
    return *this;
}


template<typename T>
T PDeque<T>::peek()
{

    if (empty())
        throw PDEQUE__EMPTY;

    return head[0];

}

template<typename T>
bool PDeque<T>::full()
{
    return size >= maxsize;
}

template<typename T>
bool PDeque<T>::empty()
{
    return (size==0);
}

template<typename T>
void PDeque<T>::clear()
{
    nukem();
}

template<typename T>
uint PDeque<T>::getSize()
{
    return size;
}

template<typename T>
void PDeque<T>::resize(uint s)
{
    if(size > s)
        throw PDEQUE__ILLEGAL_SIZE;

    maxsize = s;
}

template<typename T>
void PDeque<T>::pushAtBack(const T& d, int priority)
{
    if(full())
        throw PDEQUE__FULL;


    uint newSize=size+1;

    if(empty())
    {
        head= new T[1];
        priorityList=new int[1];
        head[0]=d;
        priorityList[0]=priority;
    }
    else
    {
        T* tempPtr= new T [newSize];
        int* tempPriorityPtr= new int [newSize];

        for (uint i=0;i<size;i++)//copy our array into new bigger arry
        {
            tempPtr[i]=head[i];
            tempPriorityPtr[i]=priorityList[i];
        }

        tempPtr[size]=d;
        tempPriorityPtr[size]=priority;

        nukem();

        head=tempPtr;
        priorityList=tempPriorityPtr;
    }

    size=newSize;

    optimizeList();

}

template<typename T>
T PDeque<T>::popAtFront()
{

    if (empty())
        throw PDEQUE__EMPTY;

    T returnMe=T();

    uint newSize=size-1;

    returnMe=head[0];

    T* tempPtr= new T [newSize];
    int* tempPriorityPtr= new int [newSize];


    for (unsigned int i=0;i<size-1;i++)
    {
        tempPtr[i]=head[i+1];
        tempPriorityPtr[i]=priorityList[i+1];

    }

    nukem();

    head=tempPtr;
    priorityList=tempPriorityPtr;

    size=newSize;

    //    optimizeList();

    return returnMe;


}

template<typename T>
void PDeque<T>:: pushAtFront(const T &d, int priority)//DEQUEUE FUNCTION
{
    if(full())
        throw PDEQUE__FULL;


    uint newSize=size+1;

    if(empty())
    {
        head= new T[1];
        priorityList= new int[1];

        head[0]=d;
        priorityList[0]=priority;
    }
    else
    {
        T* tempPtr= new T [newSize];
        int* tempPriorityPtr= new int [newSize];

        for (uint i=1;i<newSize;i++)//copy our array into new bigger array starting 1 off. 1st slot is left empty
        {
            tempPtr[i]=head[i-1];
            tempPriorityPtr[i]=priorityList[i-1];
        }

        tempPtr[0]=d; //sets front to data
        tempPriorityPtr[0]=priority;
        nukem();

        head=tempPtr;
        priorityList=tempPriorityPtr;
    }

    size=newSize;

    optimizeList();
}

template<typename T>
T PDeque<T>::popAtBack()//DEQUEUE FUNCTION
{
    if (empty())
        throw PDEQUE__EMPTY;

    T returnMe=T();

    uint newSize=size-1;

    returnMe=head[newSize]; //returns the tail

    T* tempPtr= new T [newSize];
    int* tempPriorityPtr= new int [newSize];

    for (unsigned int i=0;i<newSize;i++)
    {
        tempPtr[i]=head[i];
        tempPriorityPtr[i]=priorityList[i];

    }

    nukem();

    head=tempPtr;
    priorityList=tempPriorityPtr;

    size=newSize;

    return returnMe;
}

template<typename T>
void PDeque<T>::swap(T &data1, T &data2)
{
    T temp=data1;

    data1=data2;

    data2=temp;
}

template<typename T>
void PDeque<T>::swap(unsigned int position1, unsigned int position2)
{
    swap(head[position1],head[position2]);
    swap(priorityList[position1],priorityList[position2]);
}

template<typename T>
void PDeque<T>::optimizeList()
{
    //STARTING AT THE TAIL and progressing forward, if the previous' priority is > call swap(myPos,theirPos)

    if (size >1 && priorityList[size-2]<priorityList[size-1])//peeks at the back, then decides whether to run, and which to run.
    {
        for (unsigned int i=size-1;i>0;i--)//going BACKWARDS from tail to head
        {
            if (priorityList[i]>priorityList[i-1])//if my priority is greater than the next guy's priority then...
            {
                swap(head[i],head[i-1]);
                swap(priorityList[i],priorityList[i-1]);
            }
        }
    }
    else if(size >1 && priorityList[0]<priorityList[1])
    {
        for (unsigned int i=0;i<size-1;i++)//going FORWARDS from head to tail
        {
            if (priorityList[i]<=priorityList[i+1])//if my priority is greater than the next guy's priority then...
            {
                swap(head[i],head[i+1]);
                swap(priorityList[i],priorityList[i+1]);
            }
        }
    }
}

template<typename T>
PDeque<T>& PDeque<T>::operator<<(const T& d)
{
    pushAtBack(d);
    return *this;
}

template<typename T>
PDeque<T>& PDeque<T>::operator>>(T& d)
{
    d=popAtFront();
    return *this;
}

template<typename T>
void PDeque<T>::merge(const PDeque<T> &other)
{

    //    queue<T> temp(other);

    PDeque<T> temp;
    temp=other;

    while(!temp.empty())
    {
        T tempData=T();//initializing tempData
        tempData=temp.popAtFront();//pops and stores in tempData
        pushAtBack(tempData);//pushes using tempData
    }

    temp.clear(); //clean up after myself
}


template<typename T>
void PDeque<T>::nukem()//@@@@@@@@@@@@@@@@@
{

    if(!empty())
    {
        for (unsigned int i=0;i<size;i++)
        {
            head[i]=0;
            priorityList[i]=0;
        }
        size=0;



        delete[] head; //doesn't seem to affect anything
        delete[] priorityList;
    }

}

template<typename T>
void PDeque<T>::copy(const PDeque<T> &other)
{
    nukem();

    size=other.size;

    head=new T[size];
    priorityList=new int [size];

    for (unsigned int i=0;i<other.size;i++)
    {
        head[i]=other.head[i];
        priorityList[i]=other.priorityList[i];
    }


}

template<typename U>
ostream& operator<<(ostream &out, const PDeque<U> &q)
{
    if (q.size==0)
    {
        std::cout<<"Print failed, list empty: "<<std::endl;
        throw PDEQUE__EMPTY;
    }

    if(out == cout)
        cout<<"There are "<<q.size<<" items in the queue."<<endl
           <<"they are: "<<endl;
    else
        out<<"maxsize: "<<q.maxsize<<endl;


    for (uint i=0;i<q.size;i++)
    {
        cout<<"("<<q.head[i]<<":"<<q.priorityList[i]<<") ";
    }

    cout<<endl;

    return out;
}

template<typename U>
istream& operator>>(istream &in,  PDeque<U> &q)
{
    uint size;
    U data;
    string line;
    stringstream ss;
    if(in == cin)
    {
        cout<<"What is the maximum quantity that the queue can hold? ";
        in>>size;
    }
    else
    {
        getline(in,line);
        ss<< line.substr(line.find(':')+1);
        ss>>size;
    }
    q.resize(size);
    while(in>>data)
        q<<data;
    return in;
}
#endif // PRIORITYDEQUE

