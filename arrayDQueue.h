//===========================Queue converted to Dequeue=======================================

//NEED: push at head, pop at tail
//add more functions instead of more parameters






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

enum QUEUE_ERRORS {EMPTY, FULL,ILLEGAL_SIZE};


template<typename T>
class queue
{
public:
    queue(uint s = 100);
    queue(const T &data, uint s = 100);
    queue(const queue<T>& other);
    ~queue();

    queue<T>& operator=(const queue<T>& other);

    T peek();
    bool full();
    bool empty();
    void clear();
    uint getSize();
    void resize(uint s);
    void pushAtBack(const T& d);//from a normal queue
    void popAtFront(T& d);//from a normal queue
    void pushAtFront(const T& d);//for a dequeue
    void popAtBack(T& d);//for a dequeue

    queue<T>& operator<<(const T& d);
    queue<T>& operator>>(T& d);
    void merge(const queue<T> &other);

    template<typename U>
    friend
    ostream& operator<<(ostream &out, const queue<U> &q);

    template<typename U>
    friend
    istream& operator>>(istream &in,  queue<U> &q);

private:
    T* head;//head is the left //tail is size/size subtracted by 1
    uint size;//tail is the right
    uint maxsize;

    void nukem();
    void copy(const queue<T> &other);
};

template<typename T>
queue<T>::queue(uint s)
{
    size=0;
    maxsize=s;
    head= new T[size];

}

template<typename T>
queue<T>::queue(const T &data, uint s)
{
    if(s < 1)
        throw ILLEGAL_SIZE;

    maxsize = s;
    size = 0;
    push(data);
}

template<typename T>
queue<T>::queue(const queue<T>& other)
{
    size=0;
    maxsize=100;
    head= new T[size];


    nukem();
    copy(other);
}

template<typename T>
queue<T>::~queue()
{
    nukem();
}


template<typename T>
queue<T>& queue<T>::operator=(const queue<T>& other)
{
    if(this != &other)
    {
        nukem();
        copy(other);
    }
    return *this;
}


template<typename T>
T queue<T>::peek()
{

    if (empty())
        throw EMPTY;

    return head[0];

}

template<typename T>
bool queue<T>::full()
{
    return size >= maxsize;
}

template<typename T>
bool queue<T>::empty()
{
    return (size==0);
}

template<typename T>
void queue<T>::clear()
{
    nukem();
}

template<typename T>
uint queue<T>::getSize()
{
    return size;
}

template<typename T>
void queue<T>::resize(uint s)
{
    if(size > s)
        throw ILLEGAL_SIZE;

    maxsize = s;
}

template<typename T>
void queue<T>::pushAtBack(const T& d)
{
    if(full())
        throw FULL;


    uint newSize=size+1;

    if(empty())
    {
        head= new T[1];
        head[0]=d;
    }
    else
    {
        T* tempPtr= new T [newSize];

        for (uint i=0;i<size;i++)//copy our array into new bigger arry
        {
            tempPtr[i]=head[i];
        }

        tempPtr[size]=d;

        nukem();

        head=tempPtr;
    }

    size=newSize;

}

template<typename T>
void queue<T>::popAtFront(T& d)
{

    if (empty())
        throw EMPTY;

    uint newSize=size-1;

    d=head[0];

    T* tempPtr= new T [newSize];

    for (unsigned int i=0;i<size-1;i++)
    {
        tempPtr[i]=head[i+1];
    }

    nukem();

    head=tempPtr;

    size=newSize;

}

template<typename T>
void queue<T>::pushAtFront(const T &d)//DEQUEUE FUNCTION
{
    if(full())
        throw FULL;


    uint newSize=size+1;

    if(empty())
    {
        head= new T[1];
        head[0]=d;
    }
    else
    {
        T* tempPtr= new T [newSize];

        for (uint i=1;i<size+1;i++)//copy our array into new bigger array starting 1 off. 1st slot is left empty
        {
            tempPtr[i]=head[i];
        }

        tempPtr[0]=d; //sets front to data

        nukem();

        head=tempPtr;
    }

    size=newSize;
}

template<typename T>
void queue<T>::popAtBack(T &d)//DEQUEUE FUNCTION
{
    if (empty())
        throw EMPTY;

    uint newSize=size-1;

    d=head[newSize]; //returns the tail

    T* tempPtr= new T [newSize];

    for (unsigned int i=0;i<newSize;i++)
    {
        tempPtr[i]=head[i];
    }

    nukem();

    head=tempPtr;

    size=newSize;
}

template<typename T>
queue<T>& queue<T>::operator<<(const T& d)
{
    push(d);
    return *this;
}

template<typename T>
queue<T>& queue<T>::operator>>(T& d)
{
    pop(d);
    return *this;
}

template<typename T>
void queue<T>::merge(const queue<T> &other)
{

    //    queue<T> temp(other);

    queue<T> temp;
    temp=other;

    while(!temp.empty())
    {
        T tempData=T();//initializing tempData
        temp.pop(tempData);//pops and stores in tempData
        push(tempData);//pushes using tempData
    }

    temp.clear(); //clean up after myself
}


template<typename T>
void queue<T>::nukem()
{

    if(!empty())
    {
        //std::cout<<"DEBUG size: "<<size<<std::endl;
        for (unsigned int i=0;i<size;i++)
        {
            //std::cout<<"DEBUG nukem() head[i]: "<<head[i]<<std::endl;
            head[i]=0;
        }
        size=0;



        delete[] head; //doesn't seem to affect anything
    }

}

template<typename T>
void queue<T>::copy(const queue<T> &other)
{
    nukem();

    size=other.size;

    head=new T[size];

    for (unsigned int i=0;i<other.size;i++)
    {
        head[i]=other.head[i];
    }


}

template<typename U>
ostream& operator<<(ostream &out, const queue<U> &q)
{
    if (q.size==0)
        throw EMPTY;

    if(out == cout)
        cout<<"There are "<<q.size<<" items in the queue."<<endl
           <<"they are: "<<endl;
    else
        out<<"maxsize: "<<q.maxsize<<endl;


    for (uint i=0;i<q.size;i++)
    {
        cout<<q.head[i]<<" ";
    }

    cout<<endl;

    return out;
}

template<typename U>
istream& operator>>(istream &in,  queue<U> &q)
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
//==================================================================================




//======================================Wilkinson Dequeue==============================================
//#include <iostream>
//#include <typeinfo>
//#include <stdio.h>
//#include <cstdlib>
//#include <string>
//#include <cstring>

//using namespace std;

//enum ERRORS {FULL, EMPTY, TOO_SMALL};
//enum ENQUEUE_WHERE {FRONT, BACK};

//template<typename T, typename U = emptyClass>
//class deque
//{
//    public:
//        deque(int s = 5);
//        ~deque();
//        deque(const deque<T,U> &other);
//        deque<T,U>& operator=(const deque<T,U> &other);
//        void enqueue(ENQUEUE_WHERE where, const T &data);
//        void enqueue(ENQUEUE_WHERE where, const T &data, const U &priority);
//        void dequeue(ENQUEUE_WHERE where, T &data);
//        bool full();
//        bool empty();
//        void clear();
//        /*
//          What other functions are missing here???????
//        */

//    private:
//       node<T,U> *front, *back;
//       int size, capacity;
//       bool priority;
//       U whatAmI;
//       void copy(const deque<T,U> &other);
//       void nukem();

//};


//template<typename T, typename U>
//deque<T,U>::deque(int s)
//{
//    priority = strcmp(typeid(whatAmI).name(),"10emptyClass") == 0;
//    front = back = NULL;
//    size = s;
//    capacity = 0;
//}

//template<typename T, typename U >
//deque<T,U>::~deque()
//{
//    nukem();
//}



//template<typename T, typename U >
//deque<T,U>::deque(const deque<T,U> &other)
//{
//    copy(other);
//}

//template<typename T, typename U >
//deque<T,U>& deque<T,U>::operator=(const deque<T,U> &other)
//{
//    if(this != &other)
//    {
//        nukem();
//        copy(other);
//    }
//    return *this;
//}



//template<typename T, typename U >
//void deque<T,U>::copy(const deque<T,U> &other)
//{
//    node<T,U> * who;
//    priority = other.priority;
//    size = other.size;
//    capacity = other.capacity;
//    front = back = new node<T,U>(*other.front);
//    for(who = other.front->nextnode(); who; who = who->nextnode())
//    {
//        node<T,U> *newnode = new node<T,U>(*who);
//        back->nextnode() = newnode;
//        newnode.prevnode() = back;
//        back = back->nextnode();
//    }
//}

//template<typename T, typename U >
//void deque<T,U>::nukem()
//{
//    node<T,U> * temp = front;
//    while( temp )
//    {
//        node<T,U> *bye = temp;
//        temp = temp->nextnode();
//        delete bye;
//    }
//    front = back = NULL;
//    capacity = 0;
//}


//template<typename T, typename U >
//void deque<T,U>::enqueue(ENQUEUE_WHERE where, const T &data)
//{
//    if(full())
//        throw FULL;
//    node<T,U> *newnode = new node<T,U>(data);
//    if(where == FRONT)
//    {
//        front->previousnode() = newnode;
//        newnode->nextnode() = front;
//        front = newnode;
//    }
//    else
//    {
//        back->nextnode() = newnode;
//        newnode->prevnode() = back;
//        back = newnode;
//    }
//    size++;
//}

//template<typename T, typename U>
//void deque<T,U>::enqueue(ENQUEUE_WHERE where, const T &data, const U &priority)
//{
//    if(full())
//        throw FULL;
//    node<T,U> *newnode = new node<T,U>(data, priority);
//    ++size;
//    if(where == FRONT)
//        if(newnode->myPriority() > front->myPriority())
//        {
//            front->previousnode() = newnode;
//            newnode->nextnode() = front;
//            front = newnode;
//        }
//        else
//        {
//            node<T,U> *ptr = front;
//            for(; ptr->nextnode() && ptr->myPriority() > newnode->myPriority ; ptr = ptr->nextnode());
//            if(!ptr->nextnode())
//            {
//                back->nextnode() = newnode;
//                newnode->prevnode() = back;
//                back = newnode;
//            }
//            else
//            {
//                newnode->previousnode() = ptr;
//                newnode->nextnode() = ptr->nextnode();\
//                ptr->nextnode()->previousnode() = newnode;
//                ptr->nextnode() = newnode;
//            }
//        }
//    else
//        if(back->myPriority() > newnode->myPriority())
//        {
//            back->nextnode() = newnode;
//            newnode->previousnode() = back;
//            back = newnode;
//        }
//        else
//        {
//            node<T,U> *ptr = back;
//            for(; ptr->previousnode() &&newnode->myPriority() > ptr->myPriority() ; ptr = ptr->previousnode());
//            if(!ptr->nextnode())
//            {
//                front->previousnode() = newnode;
//                newnode->nextnode() = front;
//                front = newnode;
//            }
//            else
//            {
//                newnode->previousnode() = ptr;
//                newnode->nextnode() = ptr->nextnode();\
//                ptr->nextnode()->previousnode() = newnode;
//                ptr->nextnode() = newnode;
//            }
//        }
//}

//template<typename T, typename U >
//void deque<T,U>::dequeue(ENQUEUE_WHERE where, T &data)
//{
//    node<T,U> *temp = front;
//    if(empty())
//        throw EMPTY;
//    if(where == FRONT)
//    {
//        data = front->myData();
//        front = front->nextnode();
//        front->previousnode() = NULL;
//        delete temp;
//    }
//    else
//    {
//        data = back->myData();
//        temp = back;
//        back = back->prevnode();
//        back->nextnode() = NULL;
//        delete temp;
//    }
//    --size;
//}

//template<typename T, typename U >
//bool deque<T,U>::full()
//{
//    return size >= capacity;
//}

//template<typename T, typename U >
//bool deque<T,U>::empty()
//{
//    return !size;
//}

//template<typename T, typename U >
//void deque<T,U>::clear()
//{
//    nukem();
//    size = 0;
//}

