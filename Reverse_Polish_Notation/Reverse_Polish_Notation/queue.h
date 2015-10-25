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

#define uint unsigned int

enum QUEUE_ERRORS {QUEUE_EMPTY, QUEUE_FULL, QUEUE_ILLEGAL_SIZE};


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
    void push(const T& d);
    void pop(T& d);
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
    T* head; //tail is size/size subtracted by 1
    uint size, maxsize;

    void nukem();
    void copy(const queue<T> &other);
};

template<typename T>
queue<T>::queue(uint s)
{
    maxsize=s;
    size=0;
    head= new T[size];


}

template<typename T>
queue<T>::queue(const T &data, uint s)
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
uint queue<T>::getSize()
{
    return size;
}

template<typename T>
void queue<T>::resize(uint s)
{
    if(size > s)
        throw QUEUE_ILLEGAL_SIZE;

    maxsize = s;
}

template<typename T>
void queue<T>::push(const T& d)
{

    //------------------static debug-----------------
    //    head=new T[5]{'1', '2', '3', '4', '5'};
    //    size=5;

    //    for (int i=0;i<size-1;i++)
    //    {
    //        std::cout<<"DEBUG wibgiwbdfiwb: "<<head[i]<<std::endl;
    //    }
    //----------------------------------------------

    if(full())
        throw QUEUE_FULL;


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
void queue<T>::pop(T& d)
{

    if (empty())
        throw QUEUE_EMPTY;

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



    //    node<T> *temp;
    //    if(empty())
    //        throw EMPTY;
    //    temp = head;
    //    head = head->nextNode();
    //    d = temp->getData();
    //    temp->getData() = T();
    //    delete temp;
    //    --size;
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

//    T* ptr=head;

//    for (uint i=0;i<size;i++)
//    {
//        *ptr=0;

//        ++ptr;
//    }

//    size=0;

//    delete[] head;

//    head=NULL;

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
        throw QUEUE_EMPTY;

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


    //    U* ptr = q.head;
    //    for (uint i=0;i<q.size;i++)
    //    {
    //        out<<*ptr<<endl;

    //        ++ptr;
    //    }
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



#endif // QUEUE_H
