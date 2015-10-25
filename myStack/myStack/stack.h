#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include "base_stack.h"
#include "node.h"

using std::cin;
using std::cout;
using std::istream;
using std::ostream;

template<typename T>
class stack:public base_stack
{
public:
    stack(unsigned int size=10);
    stack(const T& data, unsigned int size = 10);
    stack(stack<T> &other);
    ~stack();

    stack<T>& operator=(const stack<T> &other);

    T pop();
    const T& top();
    node<T>* baseTop();
    void push(const T& data);
    void clear();
    stack<T>& operator<<(const T& data);
    stack<T>& operator>>( T& data);


    template<typename U>
    friend
    ostream& operator<<(ostream& out, /*const*/ stack<U> &s);


    template<typename U>
    friend
    istream& operator>>(istream& in, stack<U> &s);

private:

    void reverse();
    void copy(stack<T> &other);
    void nukem();
};

template<typename T>
stack<T>::stack(unsigned int size)
{
    changeMaxSize(size);
}

template<typename T>
stack<T>::stack(const T& data, unsigned int size)
{
    changeMaxSize(size);
    push(data);
}

template<typename T>
stack<T>::stack(stack<T> &other)
{
    stack::copy(other);
    reverse();
}

template<typename T>
stack<T>::~stack()
{
    nukem();
}

template<typename T>
stack<T>& stack<T>::operator=(const stack<T> &other)
{
    if(this != &other)
    {
        nukem();
        copy(other);
    }
    return *this;
}

template<typename T>
T stack<T>::pop()
{
    base_node* tos = base_stack::pop();

    T data = ((node<T>*) tos)->getData();

    ((node<T>*) tos)->getData() = T();

    delete tos;
    return data;
}

template<typename T>
const T& stack<T>::top()
{
    node<T>* tos = (node<T>*)base_stack::top();

    T data =tos->getData();

    return data;
    //return ((node<T>*) base_stack::top())->getData();
}

template<typename T>
node<T>* stack<T>::baseTop()
{

    node<T>* tos = node<T>::getData();

    return tos;
}


template<typename T>
void stack<T>::push(const T& data)
{
    node<T>* newNode = new node<T>(data);
    base_stack::push((base_node*)newNode);
}

template<typename T>
void stack<T>::clear()
{
    nukem();
}

template<typename T>
stack<T>& stack<T>::operator<<(const T& data)
{
    push(data);
    return *this;
}

template<typename T>
stack<T>& stack<T>::operator>>( T& data)
{
    data = pop();
    return *this;
}

template<typename T>
void stack<T>::reverse()
{
    unsigned int tempSize=getSize();
    T temp[tempSize];

    for (unsigned int i=0;i<tempSize;i++) //empties stack while storing data into a queue
    {
        temp[i]=pop();
    }

    for (unsigned int i=0;i<tempSize;i++) //fills stacks with data from queue
    {
        push(temp[i]);
    }
}

template<typename U>
ostream& operator<<(ostream& out, /*const*/ stack<U> &s)
{
    if(out == cout)
    {
        node<U>* ptr = (node<U>*)s.base_stack::top();

        while(ptr)
        {
            out<<ptr->theData()<<"->";

            ptr=(node<U>*)ptr->nextNode();
        }
        cout<<"NULL"<<endl;
    }
    else
    {

    }

    return out;
}


template<typename U>
istream& operator>>(istream& in, stack<U> &s)
{
    U data;
    if(in == cin)
    {
        cout<<"What data to push into the stack? ";
        cin>>data;
        s.push(data);
    }
    else
    {

    }
    return in;

}

template<typename T>
void stack<T>::copy(stack<T> &other)
{
    nukem();

    node<T>* ptr = (node<T>*)other.base_stack::top();

    while(ptr)
    {
        push(ptr->getData());

        ptr=(node<T>*)ptr->nextNode();
    }


}

template<typename T>
void stack<T>::nukem()
{
    while(!empty())
        base_stack::pop();
}


#endif // STACK_H
