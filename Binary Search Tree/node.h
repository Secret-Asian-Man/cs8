#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>
#include "basenode.h"

using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;

template<typename T>
class node : public base_node
{
public:
    //constructor
    node(const T &data = T(), unsigned int count = 1);
    node(const node<T>&other);

    //destructor
    ~node();

    //accessors
    T& getData();
    node<T> *child(CHILD which);

    //mutators
    void setChildNode(CHILD which, node<T>* n);
    void storeData(const T& d);
    const T readData();


    //operators
    node<T>& operator=(const node<T>&other);

    template<typename U>
    friend
    ostream& operator<<(ostream& out, node<U>& other);

    template<typename U>
    friend
    istream& operator>>(istream& in, node<U> &other);

private:
    void copy(const T &other);
};


template<typename T>
node<T>::node(const T &data, unsigned int count)
{
    theData() = new T(data);
    setCount(count);
}

template<typename T>
node<T>::node(const node<T>&other)
{
    copy(other);
}

template<typename T>
node<T>::~node()
{
    delete (T*)theData();
}

template<typename T>
node<T>& node<T>::operator=(const node<T>&other)
{
    if(this != &other)
        copy(other);
    return *this;
}

template<typename T>
T& node<T>::getData()
{
    return *(T*)theData();
}

template<typename T>
const T node<T>::readData()
{
    return *(T*)theData();
//    return getData();
}

template<typename T>
void node<T>::storeData(const T& d)
{
    *(T*)base_node::theData() = d;
}

template<typename T>
void node<T>::copy(const T &other)
{
    theData() = new T((T*)other.theData());
}


template<typename T>
node<T>* node<T>::child(CHILD which)
{
    return (node<T>*)base_node::child(which);
}

template<typename T>
void node<T>::setChildNode(CHILD which, node<T>* n)
{
    base_node::child(which) = n;
}


template<typename U>
ostream& operator<<(ostream& out, node<U>& other)
{
    if(out == cout)
        out<<other.readData()<<" ";
    else
        out<<other.readData()<<endl;
    return out;
}

template<typename U>
istream& operator>>(istream& in, node<U> &other)
{
    U data;
    if(in == cin)
    {
        cout<<"Item: ";
        in>>data;
        other.getData() = data;
    }
    else
        if(in>>data)
            other.getData() = data;
    return in;
}


#endif // BASE_NODE_H
