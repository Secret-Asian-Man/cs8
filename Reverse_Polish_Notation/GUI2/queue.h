#ifndef QUEUE_H
#define QUEUE_H

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

enum QUEUE_ERRORS {QUEUE_EMPTY, QUEUE_FULL, QUEUE_ILLEGAL_SIZE};

template<typename T>
class queue
{
public:
    //constructors
    queue(unsigned int s = 100);
    queue(const T &data, unsigned int s = 100);
    queue(const queue<T>& other);

    //destructors
    ~queue();

    //functions
    T peek();
    bool full();
    bool empty();
    void clear();
    unsigned int getSize();
    void resize(unsigned int s);
    void push(const T& d);
    void pop(T& d);
    queue<T>& operator<<(const T& d);
    queue<T>& operator>>(T& d);
    void merge(const queue<T> &other);

    //operators
    queue<T>& operator=(const queue<T>& other);

    template<typename U>
    friend
    ostream& operator<<(ostream &out, const queue<U> &q);

    template<typename U>
    friend
    istream& operator>>(istream &in,  queue<U> &q);

private:
    //private variables
    T* head; //tail is size/size subtracted by 1
    unsigned int size, maxsize;

    //private functions
    void nukem();
    void copy(const queue<T> &other);
};

template<typename T>
queue<T>::queue(unsigned int s)
{
    maxsize=s;
    size=0;
    head= new T[size];
}

template<typename T>
queue<T>::queue(const T &data, unsigned int s)
{
    if(s < 1)
        throw QUEUE_ILLEGAL_SIZE;

    maxsize = s;
    size = 0;
    head= new T[size];
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
        throw QUEUE_EMPTY;

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
unsigned int queue<T>::getSize()
{
    return size;
}

template<typename T>
void queue<T>::resize(unsigned int s)
{
    if(size > s)
        throw QUEUE_ILLEGAL_SIZE;

    maxsize = s;
}

template<typename T>
void queue<T>::push(const T& d)
{
    if(full())
        throw QUEUE_FULL;

    unsigned int newSize=size+1;

    if(empty())
    {
        head= new T[1];
        head[0]=d;
    }
    else
    {
        T* tempPtr= new T [newSize];

        for (unsigned int i=0;i<size;i++)//copy our array into new bigger arry
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
void queue<T>::pop(T& d)
{
    if (empty())
        throw QUEUE_EMPTY;

    unsigned int newSize=size-1;

    d=head[0];

    T* tempPtr= new T [newSize];

    for (unsigned int i=0;i<size-1;i++)
        tempPtr[i]=head[i+1];

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
        for (unsigned int i=0;i<size;i++)
            head[i]=0;

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
        head[i]=other.head[i];
}

template<typename U>
ostream& operator<<(ostream &out, const queue<U> &q)
{
    if (q.size==0)
        throw QUEUE_EMPTY;

    if(out == cout)
        cout<<"There are "<<q.size<<" items in the queue."<<endl
           <<"they are: "<<endl;
    else
        out<<"maxsize: "<<q.maxsize<<endl;

    for (unsigned int i=0;i<q.size;i++)
        cout<<q.head[i]<<" ";

    cout<<endl;

    return out;
}

template<typename U>
istream& operator>>(istream &in,  queue<U> &q)
{
    unsigned int size;
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

#endif // QUEUE_H
