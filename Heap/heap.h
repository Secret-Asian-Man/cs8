/**
    CS8
    heap.h
    Purpose: Praticing Heaps

    @author David Wu
    @version 1.0.0 (2:48 PM Thursday, November 12, 2015)
*/
#ifndef HEAP
#define HEAP
#include <iostream>
#include <bitset>
#include <cstdlib>
#include <cmath>

using std::bitset;
using std::string;


enum HEAP_ERRORS { EMPTY };
enum HEAP_TYPE { LESSTHAN, GREATERTHAN };
enum HEAP_BRANCH { LEFT, RIGHT };

template <typename T>
struct node
{
    T data;
    node *which[2];

    inline node(T theData = T())
    {
        data = theData;
        which[0] = which[1] = NULL;
    }
};

template<typename T>
class heap
{
public:
    typedef bool (heap<T>::*fptr)(const T &x,const  T &y);
    heap(HEAP_TYPE t = LESSTHAN);
    ~heap();
    heap(const heap<T> &other);
    heap<T>& operator=(const heap<T> &other);
    heap<T>& operator<<(const T &data);
    heap<T>& operator>>(T &data);
    void clear();
    bool empty();
    void AlexPrint(node<T>* root, unsigned int depth) const;


    void insert(const T &data);
    T remove(T &data);
    //        void displayTree(node<T>* r, int level, int width);

private:
    node<T> *root;
    int lastChildEntered;
    HEAP_TYPE heapType;
    fptr heapSortingMethod[2];


    void copy(const heap<T> &otherHeap);
    void copy(node<T>* &parent, node<T> *otherParent);
    bool lessThan(const T &x,const  T &y);
    bool greaterThan(const T &x,const  T &y);
    T smallerOf(const T& a, const T &b);
    void nukem(node<T>* &n);
    //    node<T>* findParent(node<T>* target);
    node<T>* findLastChild(unsigned int childNumber);
    node<T>* findParent(unsigned int childNumber);
    void reheapifyDown();
    void reheapifyUp();
    void swap(T &x, T &y);
    unsigned int findDepth(unsigned int childIdNumber);

};

template<typename T>
heap<T>::heap(HEAP_TYPE t)
{
    root = NULL;
    lastChildEntered = 0;
    heapType = t;
    heapSortingMethod[LESSTHAN] = &heap<T>::lessThan;
    heapSortingMethod[GREATERTHAN] = &heap<T>::greaterThan;
}

template<typename T>
heap<T>::~heap()
{
    nukem(root);
}

template<typename T>
heap<T>::heap(const heap<T> &other)
{
    copy(other);
}

template<typename T>
heap<T>& heap<T>::operator=(const heap<T> &other)
{
    if(this != &other)
    {
        nukem(root);
        copy(other);
    }
    return *this;
}


template<typename T>
heap<T>& heap<T>::operator<<(const T &data)
{
    if(empty())
    {
        root = new node<T>(data);

        lastChildEntered = 1;

//        std::cout<<"DEBUG @@@@@@@@@@@@@@@@@@@@@@ "<<std::endl;
//        AlexPrint(root,findDepth(lastChildEntered));

    }
    else
    {
        lastChildEntered++;

        node<T>* parent = findParent(lastChildEntered);//problem here? what if there is no parent
        //        std::cout<<"DEBUG 11111111111111111111 "<<std::endl;
        //        AlexPrint(root,findDepth(lastChildEntered));


        //        if(parent)
        //        {
        //            std::cout<<"FOUND PARENT!!!"<<std::endl;
        //            std::cout<<parent->data<<std::endl;
        //        }
        //        else
        //        {
        //            std::cout<<"NO PARENT!!"<<std::endl;
        //        }
        if(parent)
        {
            parent->which[lastChildEntered%2] = new node<T>(data);
            reheapifyUp();
        }

//        std::cout<<"DEBUG @@@@@@@@@@@@@@@@@@@@@@ "<<std::endl;
//        AlexPrint(root,findDepth(lastChildEntered));


    }
    return *this;
}

template<typename T>
heap<T>& heap<T>::operator>>(T &data)
{
    //swap root with last element
    //delete last element


    if (!root)
        throw EMPTY;

    data=root->data;
            std::cout<<"DEBUG @@@@@@@@@@@@@@@@@@@@@@ "<<std::endl;
            AlexPrint(root,findDepth(lastChildEntered));


    node<T>* lastChild=findLastChild(lastChildEntered);
    std::cout<<"DEBUG lastChild->data: "<<lastChild->data<<std::endl;

    swap(root->data, lastChild->data); //swaps once only

    delete lastChild;
    lastChild = NULL;

    --lastChildEntered;

    reheapifyDown();

    return *this;
























    //    if(empty())
    //        throw(EMPTY);

    //    data = root->data;
    //    node<T> *parent = findParent(lastChildEntered);
    //    if (parent)
    //    {
    //        bool whichSideIsTheChild = lastChildEntered%2;
    //        swap(root->data, parent->which[whichSideIsTheChild]->data);
    //        delete parent->which[whichSideIsTheChild];
    //        parent->which[whichSideIsTheChild] = NULL;
    //        lastChildEntered--;

    //        reheapifyDown();
    //    }

    return *this;

}

template<typename T>
void heap<T>::clear()
{
    nukem(root);
}

template<typename T>
bool heap<T>::empty()
{
    return !root;
}

template<typename T>
void heap<T>::AlexPrint(node<T>* root, unsigned int depth) const
{
    if (root)
    {
        AlexPrint(root->which[LEFT], depth + 1);
        for (int i = 0; i < 2*depth; i++) std::cout << " ";
        std::cout << depth<<":";
        std::cout << root->data << std::endl;
        AlexPrint(root->which[RIGHT], depth + 1);

    }
}

template<typename T>
void heap<T>::insert(const T &data) //should work
{

    if(empty())
    {
        root = new node<T>(data);
        lastChildEntered = 1;
    }
    else
    {
        lastChildEntered++;
        node<T>* parent = findParent(lastChildEntered);
        parent->which[lastChildEntered%2] = new node<T>(data);
        reheapifyUp();
    }
}

template<typename T>
T heap<T>::remove(T &data) //should work
{
    if(empty())
        throw(EMPTY);

    data = root->data;
    node<T> *parent = findParent(lastChildEntered);
    bool whichSideIsTheChild = lastChildEntered%2;
    swap(root->data, parent->which[whichSideIsTheChild]->data);
    delete parent->which[whichSideIsTheChild];
    parent->which[whichSideIsTheChild] = NULL;
    lastChildEntered--;

    reheapifyDown();

    return data;
}

template<typename T>
void heap<T>::copy(const heap<T> &otherHeap)
{
    copy(otherHeap.root);
}


template<typename T>
void heap<T>::copy(node<T>* &parent, node<T> *otherParent)
{
    if(otherParent)
    {
        parent = new node<T>(otherParent->data);
        copy(parent->which[LEFT], otherParent->which[LEFT]);
        copy(parent->which[RIGHT], otherParent->which[RIGHT]);
    }
}

template<typename T>
void heap<T>::nukem(node<T>* &n)
{

    if(n && n->which[LEFT])
        nukem(n->which[LEFT]);
    if(n && n->which[RIGHT])
        nukem(n->which[RIGHT]);
    if(n)
        ( n->data = T(), n->which[LEFT] = n->which[RIGHT] = NULL, delete n);
}

//template<typename T>
//node<T>* heap<T>::findParent(node<T>* target)
//{

//}

template<typename T>
node<T>* heap<T>::findLastChild(unsigned int childNumber)
{
    unsigned int depth=findDepth(childNumber); //finds depth of the child

    if (!root)
        throw EMPTY;

    if (!depth)//if the depth is 0 return the root
        return root;

    bitset<32> bits(childNumber);

    node<T>* child=root;

    for (int i=depth-1;i>=0;--i) //by stopping at depth-1 I stop at my parent, otherwise I would go back to myself
        child=child->which[bits[i]]; //bit positions are backwards!!!


    return child;
}

template<typename T>
node<T>* heap<T>::findParent(unsigned int childNumber) //can find myself with parent->which[lastChildEntered%2]
{
    unsigned int depth=findDepth(childNumber); //finds depth of the child

    if (!depth)
        return NULL;

    bitset<32> bits(childNumber);

    node<T>* parent=root;
    for (unsigned int i=depth-1;i>0;--i) //by stopping at depth-1 I stop at my parent, otherwise I would go back to myself
    {
        parent=parent->which[bits[i]];
    }

    return parent;

}

template<typename T>
void heap<T>::reheapifyDown() //for removing root
{
    //reheapify down by swapping new root with the bigger of the 2 children until NULL.

    //    node<T>* walker=root;
    //    bool loopAgain;


    //    while(walker && loopAgain)
    //    {
    ////        if ((walker->which[LEFT] && walker->which[RIGHT]));

    //    }






    //MINNNNEEEE
    node<T>* walker=root;
    bool loopAgain;


    while(walker && loopAgain)
    {

        if (walker->which[LEFT] && walker->data > walker->which[LEFT]->data)
        {
            swap(walker->data,walker->which[LEFT]->data);

            walker=walker->which[LEFT];
        }
        else if(walker->which[RIGHT] && walker->data > walker->which[RIGHT]->data)
        {
            swap(walker->data,walker->which[RIGHT]->data);

            walker=walker->which[RIGHT];
        }
        else
            loopAgain=false;

    }







    //WILKISON
    //        node<T> *childToSwitchWith, *parent = root;
    //        bool reheapify = true;
    //        while(reheapify && parent->which[LEFT])
    //        {
    //            if(!parent->which[RIGHT])
    //                childToSwitchWith = parent->which[LEFT];
    //            else
    //                childToSwitchWith = (this->*heapSortingMethod[heapType])(parent->which[LEFT]->data, parent->which[RIGHT]->data)
    //                        ? parent->which[LEFT]
    //                          : parent->which[RIGHT];
    //            if((this->*heapSortingMethod[heapType])(parent->data, childToSwitchWith->data))
    //            {
    //                swap(parent->data,childToSwitchWith->data);
    //                parent = childToSwitchWith;
    //            }
    //            else
    //                reheapify = false;
    //        }
}

template<typename T>
void heap<T>::reheapifyUp() //for inserting
{
    //insert at last element
    //folowing the last element, check if the parent is greater, if it is, swap the two.

    node<T>*parent= findParent(lastChildEntered); //finds my parent
    std::cout<<"DEBUG parent: "<<parent->data<<std::endl;
    unsigned int currentChild=lastChildEntered;

    //    unsigned int debugCount=0;

    while(parent && parent->which[currentChild%2] && (parent->which[currentChild%2]->data < parent->data)) //while I have a parent and I am bigger than my parent, change places
    {
        std::cout<<"DEBUG SWAPPING@@@@@@@@: "<<std::endl;
        swap(parent->which[currentChild%2]->data,parent->data); //swap the data

        currentChild=currentChild/2; //my child walker, decrements
        parent=findParent(currentChild); //finds the new parent 1 generation back

        //        ++debugCount;
        //        std::cout<<"DEBUG debugCount: "<<debugCount<<std::endl;
    }



    //    int parent = lastChildEntered / 2,
    //            child = lastChildEntered;
    //    node<T> *parentPtr = findParent(child),
    //            *childPtr = parentPtr->which[child%2];
    //    while(!(this->*heapSortingMethod[heapType])(parentPtr->data, childPtr->data))
    //    {
    //        child = child / 2;
    //        parent = child / 2;
    //        parentPtr = findParent(child);
    //        childPtr = parentPtr->which[child%2];
    //    }
}


template<typename T>
void heap<T>::swap(T &x, T &y)
{
    T temp = x;
    x = y;
    y = temp;
}

template<typename T>
unsigned int heap<T>::findDepth(unsigned int childIdNumber) //0 based, finds the depth of the given child id
{
    unsigned int depth=floor(log10(childIdNumber*1.)/log10(2.));

    return depth;
}

template<typename T>
bool heap<T>::lessThan(const T &x,const  T &y)
{
    return x < y;
}

template<typename T>
bool heap<T>::greaterThan(const T &x,const  T &y)
{
    return x > y;
}

template<typename T>
T heap<T>::smallerOf(const T& a, const T &b)
{
    if(a<b)
        return a;
    else
        return b;
}


#endif // HEAP

