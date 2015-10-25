#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <string>
#include "node.h"

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
    uint size();
    void resize(uint s);
    void enqueue(const T& d);
    void dequeue(T& d);
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
    node<T> *head, *tail;
    uint qty, maxQty;

    void nukem();
    void copy(const queue<T> &other);

};

template<typename T>
queue<T>::queue(uint s)
{
    maxQty = s;
    qty = 0;
    head = tail = new node<T>[qty];
}

template<typename T>
queue<T>::queue(const T &data, uint s)
{
    if(s < 1)
        throw ILLEGAL_SIZE;
    maxQty = s;
    qty = 0;
    enqueue(data);
}

template<typename T>
queue<T>::queue(const queue<T>& other)
{    
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
    return head->data;
}

template<typename T>
bool queue<T>::full()
{
    return qty >= maxQty;
}

template<typename T>
bool queue<T>::empty()
{
    return !head;
}

template<typename T>
void queue<T>::clear()
{
    nukem();
}

template<typename T>
uint queue<T>::size()
{
    return qty;
}

template<typename T>
void queue<T>::resize(uint s)
{
    if(qty > s)
        throw ILLEGAL_SIZE;
    maxQty = s;
}

template<typename T>
void queue<T>::enqueue(const T& d)
{
    if(full())
        throw FULL;
    if(empty())
        head = tail = new node<T>(d);
    else
    {
        tail->setNextNode(new node<T>(d));
        tail = tail->nextNode();
    }
    ++qty;
}

template<typename T>
void queue<T>::dequeue(T& d)
{
    node<T> *temp;
    if(empty())
        throw EMPTY;
    temp = head;
    head = head->nextNode();
    d = temp->getData();
    temp->getData() = T();
    delete temp;
    --qty;
}

template<typename T>
queue<T>& queue<T>::operator<<(const T& d)
{
    enqueue(d);
    return *this;
}

template<typename T>
queue<T>& queue<T>::operator>>(T& d)
{
    dequeue(d);
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
        temp.dequeue(tempData);//pops and stores in tempData
        enqueue(tempData);//pushes using tempData
    }

    temp.clear(); //clean up after myself
}


template<typename T>
void queue<T>::nukem()
{
    node<T> *temp;
    qty = 0;
    while(head)
    {
        temp = head;
        head = head->nextNode();
        temp->getData()= T();
        delete temp;
    }
    head = tail = NULL;
}

template<typename T>
void queue<T>::copy(const queue<T> &other)
{
    node<T> *ptr = other.head;
    maxQty = other.maxQty;
    qty=other.qty;
    for(; ptr; enqueue(ptr->getData()), ptr= ptr->nextNode());
    /*
     The above is the same as
     while(ptr)
     {
        enqueue(ptr->data);
        ptr = ptr->next;
     }
    */
}

template<typename U>
ostream& operator<<(ostream &out, const queue<U> &q)
{
    if(out == cout)
        cout<<"There are "<<q.qty<<" items in the queue."<<endl
           <<"they are: "<<endl;
    else
        out<<"maxQty: "<<q.maxQty<<endl;
    for(node<U>* ptr = q.head;ptr;ptr=ptr->nextNode())
        out<<*ptr<<endl;
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
