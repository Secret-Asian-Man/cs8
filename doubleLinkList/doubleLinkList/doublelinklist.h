#ifndef DOUBLELINKEDLIST
#define DOUBLELINKEDLIST
#include <iostream>
#include "node.h"

using std::cin;
using std::cout;

template<typename T>
class doubleLinkedList
{
public:
    doubleLinkedList();
    doubleLinkedList(const T &d, int c=1);
    doubleLinkedList(const doubleLinkedList<T> &other);
    ~doubleLinkedList();

    doubleLinkedList<T>& operator=(const doubleLinkedList<T> &other);
    void insert(const T &d, int c = 1);
    void insert(node<T> *n);
    void remove(const T &d);
    void removeAll();
    bool empty();
    void clear();
    int count(const T &d);
    bool find(const T &d);
    void print();

    template<typename U>
    friend
    std::ostream& operator<<(std::ostream &out, const doubleLinkedList<U> &other);

    template<typename U>
    friend
    std::istream& operator>>(std::istream &in,  doubleLinkedList<U> &other);

private:
    node<T> *head;
    node<T> *tail;

    void nukem();
    void copy(const doubleLinkedList &other);
    node<T>* locate(const T &d);
};

template<typename T>
doubleLinkedList<T>::doubleLinkedList()
{
    head = tail = NULL;
}

template<typename T>
doubleLinkedList<T>::doubleLinkedList(const T &d, int c/*=1*/)
{
    head = tail = new node<T>(d,c);
}

template<typename T>
doubleLinkedList<T>::doubleLinkedList(const doubleLinkedList<T> &other)
{
    copy(other);
}

template<typename T>
doubleLinkedList<T>::~doubleLinkedList()
{
    nukem();
}

template<typename T>
doubleLinkedList<T>& doubleLinkedList<T>::operator=(const doubleLinkedList<T> &other)
{
    if(this != &other)
        copy(other);
    return *this;
}

template<typename T>
void doubleLinkedList<T>::insert(const T &d, int c)
{

    //insert(new node(d,c));










    //    if (tail)//if the list is not empty
    //    {
    //        tail->right=new node<T>(d,c);
    //        tail=tail->right;//add a new node to the end


    //        tail->right=NULL; //set the node at the new end to point to NULL
    //    }
    //    else //the list is empty
    //    {
    //        head=tail=new node<T>(d,c); //make head and tail both point at the new node
    //        head->left=tail->right=NULL; // have the left and right of the new node point to NULL
    //    }
}

template<typename T>
void doubleLinkedList<T>::insert(node<T> *n)
{
    node<T> *ptr=locate(n->data); //searches our list to find if any number matches, returns the location if found, returns NULL if not found.

    if (ptr) //if it is found at this point, that means that it already exists in the list
    {
        ptr->count=ptr->count+1; //increment the count

        delete ptr; //delete the new node

        return; //exit function
    }

    //if I survived to this point, it means that the new node doesn't exist in the list.

    ptr=head; //get ready to search our list again, by restarting the node at our head

    while(ptr && ptr<n) //increments ptr, until NULL, or ptr.data<n.data
        ptr=ptr->right;

    if (ptr)//if something is found at this point, it means that we found a bigger number on the right, so we want to insert on the left
    {
        if (ptr==head)//checks a special condition, if ptr is at head.
        {
            n->right=ptr;
            //n->left=NULL;//already NULL to start with

            ptr->left=n;

            head=n;

            return;
        }
        else //in the middle somewhere (note: don't worry about tail here)
        {
            n->left=ptr->left;
            n->right=ptr;

            ptr->left->right=n;
            ptr->left=n;

            return;
        }

    }
    else //ptr>tail || list is entirely empty
    {
        if (tail) //check if there is something inside the list at all
        {
            //if we made it to this point, then there is something in the list and our new node is bigger than the tail


            return;
        }
        else
        {
            //if we made it to this point, then the list is entirely empty

        }
    }













    //    if (tail)//if the list is not empty
    //    {
    //        tail->right=n;
    //        tail=tail->right;//add a new node to the end


    //        tail->right=NULL; //set the node at the new end to point to NULL
    //    }
    //    else //the list is empty
    //    {
    //        head=tail=n; //make head and tail both point at the new node
    //        head->left=tail->right=NULL; // have the left and right of the new node point to NULL
    //    }


    //    tail=tail->right= n;
    //    tail->right=NULL;

}

template<typename T>
void doubleLinkedList<T>::remove(const T &d)
{
    std::cout<<"AWDAEEG "<<std::endl;
    node<T> *ptr=locate(d);

    std::cout<<"DEBUG remove() ptr->data: "<<ptr->data<<std::endl;
    std::cout<<"DEBUG remove() head: "<<head->data<<std::endl;
    std::cout<<"DEBUG remove() tail: "<<tail->data<<std::endl;


    if (ptr)
    {

        if (ptr==head) //if removing head
        {
            std::cout<<"DEBUG remove() ptr==head: "<<std::endl;

            if (head==tail) //if only one element in the list
            {
                std::cout<<"DEBUG remove() ptr==head head==tail: "<<std::endl;
                head=tail=NULL;
            }
            else
            {
                ptr->right->left=NULL;
                head=ptr->right;
            }

            delete ptr;
        }

        else if (ptr==tail) //if removing tail
        {
            std::cout<<"DEBUG remove() ptr==tail: "<<std::endl;
            ptr->left->right=NULL;

            tail=ptr->left;

            delete ptr;
        }

        else //if removing something in middle
        {
            std::cout<<"DEBUG remove() ptr==middle: "<<std::endl;

            node<T> *leftTemp= ptr->left;
            node<T> *rightTemp= ptr->right;


            std::cout<< "left mem address:" << leftTemp << std::endl;
            std::cout<< "right mem address:" << rightTemp << std::endl;

            //                        std::cout<< "left val:" << leftTemp->data <<std::endl;
            //                        std::cout<< "right val:" << rightTemp->data <<std::endl;

            //                        leftTemp->right=rightTemp;
            //                        rightTemp->left=leftTemp;

            //            ptr->left->right=ptr->right; //PROBLEM RIGHT HERE
            //            ptr->right->left=ptr->left; //PROBLEM RIGHT HERE

            std::cout<<"DEBUG :FVNJUUNBTRBYHNUJ "<<std::endl;
            //           delete ptr;
        }
    }

}

template<typename T>
void doubleLinkedList<T>::removeAll()
{
    nukem();
}

template<typename T>
bool doubleLinkedList<T>::empty()
{
    return !head;
}

template<typename T>
void doubleLinkedList<T>::clear()
{
    nukem();
}

template<typename T>
int doubleLinkedList<T>::count(const T &d)
{
    node<T> *ptr = locate(d);
    return ptr ? ptr->count : 0;
}

template<typename T>
bool doubleLinkedList<T>::find(const T &d)
{
    return locate(d);
}

template<typename T>
void doubleLinkedList<T>::print()
{
    node<T> *ptr=head;

    while(ptr)
    {
        std::cout<<"["<<ptr->data<<"]<->";

        ptr=ptr->right;
    }

    cout<<"NULL"<<std::endl;
}


template<typename U>
std::ostream& operator<<(std::ostream &out, const doubleLinkedList<U> &other)//@@@@@@@@@@
{
    node<U> *ptr= other.head; //walker

    if (out==std::cout)
    {
        while(ptr) //while not NULL
        {
            out<<"["<<ptr->data<<"]<->";

            ptr=ptr->right;
        }
        std::cout<<"NULL"<<std::endl;

    }
    else
    {
        while(ptr)
        {
            out<<ptr->data;

            ptr=ptr->right;
        }

    }


    return out;
}

template<typename U>
std::istream& operator>>(std::istream &in,  doubleLinkedList<U> &other)
{

    //why do I even need to cin an entire doubleLinkList? What would that even do?

    //    if (in == std::cin)
    //    {
    //    }
    //    else
    //    {

    //    }


    //    return in;
}

template<typename T>
void doubleLinkedList<T>::nukem()
{
    node<T> *ptr = head;
    node<T>*bye;

    std::cout<<"DEBUG ptr: "<<&ptr<<std::endl;
    std::cout<<"DEBUG ptr: "<<&ptr->right<<std::endl;
    while(ptr)
    {
        bye=ptr;

        ptr=ptr->right;//<-------

        delete bye;
    }
    //    for(; ptr; bye = ptr ,ptr = ptr->right, delete bye);

    head = tail = NULL;
}

template<typename T>
void doubleLinkedList<T>::\

copy(const doubleLinkedList &other)
{
    nukem(); //clear my list

    node<T> *ptr = other.head; //walker

    while(ptr) //while ptr is not NULL
    {
        insert(new node<T>(*ptr)); //insert a new node using data from the other list. WARNING: node(node) constructor not working
        ptr=ptr->right; //increment the ptr
    }





}

template<typename T>
node<T>* doubleLinkedList<T>::locate(const T &d)//make sure it returns NULL if not found!!!
{
    node<T> *ptr = head;//creates ptr at head

    while(ptr && ptr->data != d) //while ptr isn't NULL, and the data isn't found
        ptr = ptr->right; // increment pointer

    //    std::cout<<"DEBUG locate returning: "<<&ptr<<"  "<<ptr->data<<std::endl;

    //std::cout<<"DEBUG doubleLinkedList<T>::locate : "<<&ptr<<std::endl;
    return ptr; //returns the pointer location of where data was found, or returns NULL if nothing was found
}



#endif // DOUBLELINKEDLIST

