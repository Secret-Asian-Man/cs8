#ifndef BST_H
#define BST_H
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "node.h"

using std::cin;
using std::cout;

enum TRAVERSE {PRE_ORDER,IN_ORDER, POST_ORDER};


template<typename T>
class bst
{
public:

    //function Pointers
    typedef void (*functionPointer)(ostream&, node<T>*); //defined the type, still need to create a variable with this type

    //constructors
    bst(TRAVERSE how = IN_ORDER);
    bst(const bst<T> &other);

    //destructors
    ~bst();

    //accessors
    TRAVERSE showTraversal() const;
    unsigned int totalDataItems();

    //mutators
    void setTraversal(TRAVERSE how);

    //functions
    void insert(const T &data, int count = 1);
    bool empty();
    bool remove(const T &data);
    bool balanced();
    void rebalance();
    bool search(const T &data);
    void clear();

    //operators
    bst<T>& operator=(const bst<T> &other);
    bst<T>& operator<<(const T &data);

    template<typename U>
    friend
    ostream& operator<<(ostream& out, const bst<U> &tree);

    template<typename U>
    friend
    istream& operator>>(istream& in, bst<U> &tree);

private:
    node<T> *root;
    functionPointer fptrArray[3];
    TRAVERSE method;

    void copy(const node<T> *what);
    void insert(node<T> *&newNode, node<T> *where);
    void nukem(node<T> *theNode);
    bool find(const T &data, node<T> *node);

    //OMFG I'M GOING TO KILL SOMEONE
    //Let's say we created 3 instances of this class. These 3 functions below are all DYNAMICALLY ALLOCATED to their OWN ADDRESS.
    //So we can't have a function pointer point to an address that won't stand still now can we.
    //Thus, we make the function static, meaning the functions below EACH WILL BE ASSIGNED A STATIC ADDRESS IN MEMORY.
    //revisit: the first instance of the class created is the one who makes the address for the function.
    static void inOrder(ostream& out, node<T> *node);
    static void preOrder(ostream &out, node<T> *node);
    static void postOrder(ostream &out, node<T> *node);
};


template<typename T>
bst<T>::bst(TRAVERSE how)
{
    method = how;
    root = NULL;
    fptrArray[IN_ORDER] = &inOrder;
    fptrArray[PRE_ORDER] = &preOrder;
    fptrArray[POST_ORDER] = &postOrder;
}

template<typename T>
bst<T>::~bst()
{
    nukem(root);
}

template<typename T>
bst<T>::bst(const bst<T> &other)
{
    copy(other.root);
}


template<typename T>
bst<T>& bst<T>::operator=(const bst<T> &other)
{
    if(this != &other)
    {
        nukem(root);
        copy(other.root);
    }
    return *this;
}

template<typename T>
void bst<T>::insert(const T &data, int count)
{
    node<T>* temp=new node<T>(data,count);

    insert(temp, root);
}

template<typename T>
bool bst<T>::empty()
{
    return !root;
}

template<typename T>
void bst<T>::setTraversal(TRAVERSE how)
{
    method = how;
}

template<typename T>
TRAVERSE bst<T>::showTraversal() const
{
    return method;
}

template<typename T>
bool bst<T>::search(const T &data)
{
    return find(data,root);
}

template<typename T>
bst<T>& bst<T>::operator<<(const T &data)
{
    insert(data);
    return *this;
}

template<typename U>
ostream& operator<<(ostream& out, const bst<U> &tree)
{
    tree.fptrArray[tree.method] (out,tree.root);
    return out;
}

template<typename U>
istream& operator>>(istream& in, bst<U> &tree)
{
    U data;
    int count;
    while(in>>data>>count)
        tree.insert(data,count);
    return in;
}


template<typename T>
void bst<T>::copy(const node<T> *what)
{
    insert(what->getData(),what->getCount());
    copy(what->child(LEFT));
    copy(what->child(RIGHT));
}

template<typename T>
void bst<T>::insert(node<T>* &newNode, node<T> *where)
{
    if(!root)
        root = newNode;
    else
        if(where->getData() == newNode->getData())
        {
            where += newNode->getCount();
            delete newNode;
        }

//    if(newNode->getData() < where->getData())
//        if(!where->child(LEFT))

//            newNode = where->child(LEFT) ;
//        else
//            insert(newNode,where->child(LEFT));
//    else
//        if(!where->child(RIGHT))
//            newNode = where->child(RIGHT);
//        else
//            insert(newNode,where->child(RIGHT));
}


template<typename T>
void bst<T>::nukem(node<T>* theNode)
{
    if(theNode->child(LEFT))
        nukem(theNode->child(LEFT));

    if(theNode->child(RIGHT))
        nukem(theNode->child(RIGHT));

    delete theNode;
    theNode = NULL;
}

template<typename T>
bool bst<T>::find(const T &data, node<T> *node)
{
    if(data == node->getData())
        return true;
    if(data < node->getData())
        find(data,node->child(LEFT));
    if(data > node->getData())
        find(data,node->child(RIGHT));
    return false;
}


template<typename T>
void bst<T>::inOrder(ostream& out, node<T> *node)
{
    if(node->child(LEFT))
        inOrder(out, node->child(LEFT));
    cout<<*node<<" ";
    if(node->child(RIGHT))
        inOrder(out, node->child(RIGHT));
}

template<typename T>
void bst<T>::preOrder(ostream &out, node<T> *node)
{
    cout<<*node<<" ";
    if(node->child(LEFT))
        preOrder(out, node->child(LEFT));
    if(node->child(RIGHT))
        preOrder(out, node->child(RIGHT));
}

template<typename T>
void bst<T>::postOrder(ostream &out, node<T> *node)
{
    if(node->child(LEFT))
        postOrder(out, node->child(LEFT));
    if(node->child(RIGHT))
        postOrder(out, node->child(RIGHT));
    cout<<*node<<" ";
}

template<typename T>
bool bst<T>::remove(const T &data)
{

}

template<typename T>
bool bst<T>::balanced()
{

}

template<typename T>
void bst<T>::rebalance()
{

}

template<typename T>
unsigned int bst<T>::totalDataItems()
{

}


template<typename T>
void bst<T>::clear()
{
    nukem(root);
}

#endif // BST_H
