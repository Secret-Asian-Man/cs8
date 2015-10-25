#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <fstream>


using std::cin;
using std::cout;
using std::istream;
using std::ostream;

enum STACK_ERRORS {EMPTY, FULL,ILLEGAL_SIZE};


template<typename T>
class stack
{
public:
    //constructors
    stack(unsigned int s=100);
    stack(const T& data, unsigned int s = 100);
    stack(const stack<T> &other);

    //destructor
    ~stack();

    //functions
    void pop(T &d);
    const T peek();
    void push(const T& data);
    void clear();
    bool empty() const;
    bool full() const;
    void changeMaxSize(unsigned int newMaxSize);
    unsigned int getSize();
    void reverse();

    //operators
    stack<T>& operator=(const stack<T> &other);
    stack<T>& operator<<(const T& data);
    stack<T>& operator>>( T& data);

    template<typename U>
    friend
    ostream& operator<<(ostream& out, const stack<U> &s);

    template<typename U>
    friend
    istream& operator>>(istream& in, stack<U> &s);

protected:
    T* head;
    unsigned int size;
    unsigned int maxSize;


private:
    void copy(const stack<T> &other);
    void nukem();
};

//constructors
template<typename T>
stack<T>::stack(unsigned int s)
{
    if (s<=0)
        throw ILLEGAL_SIZE;

    size=0;
    maxSize=s;
    head=new T[size];

}

template<typename T>
stack<T>::stack(const T& data, unsigned int s)
{
    if (s<=0)
        throw ILLEGAL_SIZE;

    size=0;
    maxSize=s;
    head=new T[size];

    push(data);
}

template<typename T>
stack<T>::stack(const stack<T> &other)
{
    size=0;
    maxSize=100;
    head=new T[size]; //head must be pointing to something! Otherwise if I call nukem(), other gets nuked for some bizzare reason.

    nukem();

    copy(other);
}

//destructor
template<typename T>
stack<T>::~stack()
{
    nukem();
}

//functions
template<typename T>
void stack<T>::pop(T& d)
{

    if(empty())
        throw EMPTY;

    unsigned int newSize=size-1;

    d=head[newSize];

    T* tempPtr=new T[newSize];

    for (unsigned int i=0;i<newSize;i++)
    {
        tempPtr[i]=head[i];
    }

    nukem();

    head=tempPtr;

    size=newSize;
}

template<typename T>
const T stack<T>::peek()
{
    if (empty())
        throw EMPTY;

    return head[size-1]; //peek at the next thing about to come out
}

template<typename T>
void stack<T>::push(const T& data)
{
    if (full())
        throw FULL;

    unsigned int newSize=size+1;

    if(empty())
    {
        head=new T[1];
        head[0]=data;
    }
    else
    {

        T* temp=new T[newSize];

        for (unsigned int i=0;i<size;i++)
        {
            temp[i]=head[i];
        }

        temp[size]=data;

        nukem();

        head=temp;


    }

    size=newSize;


}

template<typename T>
void stack<T>::clear()
{
    nukem();
}

template<typename T>
bool stack<T>::empty() const
{
    return !size;
}

template<typename T>
bool stack<T>::full() const
{
    return (size>=maxSize);
}

template<typename T>
void stack<T>::changeMaxSize(unsigned int newMaxSize)
{
    maxSize=newMaxSize;
}

template<typename T>
unsigned int stack<T>::getSize()
{
    return size;
}

//operators
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
stack<T>& stack<T>::operator<<(const T& data)
{
    push(data);
    return *this;
}

template<typename T>
stack<T>& stack<T>::operator>>( T& data)
{
    pop(data);
    return *this;
}

template<typename U>
ostream& operator<<(ostream& out, const stack<U> &s)
{

    if(s.size==0)
    {

        throw EMPTY;

    }

    if(out == cout)
    {

        for (unsigned int i=0;i<s.size;i++)
        {
            std::cout<<s.head[i]<<" ";
        }
        std::cout<<std::endl;
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
void stack<T>::reverse()
{
    int storedSize=size;
    T* temp= new T[storedSize];

    for (unsigned int i=0;!empty();i++)
    {
        int tempPop=0;
        pop(tempPop);
        std::cout<<"DEBUG reverse tempPop: "<<tempPop<<std::endl;
        temp[i]=tempPop;
    }
    nukem();

    head=temp;
    size=storedSize;//popping ruins the original size
}

template<typename T>
void stack<T>::copy(const stack<T> &other)
{
    nukem();

    size=other.size;
    maxSize=other.maxSize;

    head=new T[other.size];

    for (unsigned int i=0;i<other.size;i++)//error here. other doesn't exist
    {
        //        std::cout<<"DEBUG i: "<<i<<std::endl;
        //        std::cout<<"DEBUG myHead[i]: "<<head[i]<<std::endl;
        //        std::cout<<"DEBUG otherHead[i]: "<<other.head[i]<<std::endl;
        head[i]=other.head[i];
    }

}

template<typename T>
void stack<T>::nukem()
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
































































































//template<typename T>
//stack<T>::stack(unsigned int size)
//{
//    changeMaxSize(size);
//}

//template<typename T>
//stack<T>::stack(const T& data, unsigned int size)
//{
//    changeMaxSize(size);
//    push(data);
//}

//template<typename T>
//stack<T>::stack(stack<T> &other)
//{
//    stack<T>::copy(other);
//    reverse();
//}

//template<typename T>
//stack<T>::~stack()
//{
//    nukem();
//}

//template<typename T>
//stack<T>& stack<T>::operator=(const stack<T> &other)
//{
//    if(this != &other)
//    {
//        nukem();
//        copy(other);
//    }
//    return *this;
//}

//template<typename T>
//T stack<T>::pop()
//{
//    base_node* tos = base_stack<T>::pop();

//    T data = ((node<T>*) tos)->getData();

//    ((node<T>*) tos)->getData() = T();

//    delete tos;
//    return data;
//}

//template<typename T>
//const T& stack<T>::peek()
//{
//    node<T>* tos = (node<T>*)base_stack<T>::top();

//    T data =tos->getData();

//    return data;
//    //return ((node<T>*) base_stack<T>::top())->getData();
//}

//template<typename T>
//node<T>* stack<T>::baseTop()
//{

//    node<T>* tos = node<T>::getData();

//    return tos;
//}


//template<typename T>
//void stack<T>::push(const T& data)
//{
//    node<T>* newNode = new node<T>(data);
//    base_stack<T>::push((base_node*)newNode);
//}

//template<typename T>
//void stack<T>::clear()
//{
//    nukem();
//}

//template<typename T>
//stack<T>& stack<T>::operator<<(const T& data)
//{
//    push(data);
//    return *this;
//}

//template<typename T>
//stack<T>& stack<T>::operator>>( T& data)
//{
//    data = pop();
//    return *this;
//}

//template<typename T>
//void stack<T>::reverse()
//{
//    unsigned int tempSize=getSize();
//    T temp[tempSize];

//    for (unsigned int i=0;i<tempSize;i++) //empties stack while storing data into a queue
//    {
//        temp[i]=pop();
//    }

//    for (unsigned int i=0;i<tempSize;i++) //fills stacks with data from queue
//    {
//        push(temp[i]);
//    }
//}

//template<typename U>
//ostream& operator<<(ostream& out, /*const*/ stack<U> &s)
//{
//    if(out == cout)
//    {
//        node<U>* ptr = (node<U>*)s.base_stack<T>::top();

//        while(ptr)
//        {
//            out<<ptr->theData()<<"->";

//            ptr=(node<U>*)ptr->nextNode();
//        }
//        cout<<"NULL"<<endl;
//    }
//    else
//    {

//    }

//    return out;
//}


//template<typename U>
//istream& operator>>(istream& in, stack<U> &s)
//{
//    U data;
//    if(in == cin)
//    {
//        cout<<"What data to push into the stack? ";
//        cin>>data;
//        s.push(data);
//    }
//    else
//    {

//    }
//    return in;

//}

//template<typename T>
//void stack<T>::copy(stack<T> &other)
//{
//    nukem();

//    node<T>* ptr = (node<T>*)other.base_stack<T>::top();

//    while(ptr)
//    {
//        push(ptr->getData());

//        ptr=(node<T>*)ptr->nextNode();
//    }


//}

//template<typename T>
//void stack<T>::nukem()
//{
//    while(!empty())
//        base_stack<T>::pop();
//}


#endif // STACK_H
