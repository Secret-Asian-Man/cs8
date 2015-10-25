#ifndef DOUBLELINKEDLIST
#define DOUBLELINKEDLIST
#include <iostream>
#include <fstream>
#include <string>
#include "node.h"

using std::cin;
using std::cout;

enum DLL_ERRORS{ UNABLE_TO_REMOVE};
enum DLL_PRINT_DIRECTION{ASCENDING, DESCENDING};

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
    void remove(const T &d,int c=1);
    void removeAll();
    bool empty();
    void clear();
    DLL_PRINT_DIRECTION& printDirection();
    int count(const T &d);
    bool find(const T &d);
    void merge(doubleLinkedList<T> &other);
    void print();

    template<typename U>
    friend
    std::ostream& operator<<(std::ostream &out, doubleLinkedList<U> &other);

    template<typename U>
    friend
    std::istream& operator>>(std::istream &in,  doubleLinkedList<U> &other);

private:
    node<T> *head;
    node<T> *tail;
    DLL_PRINT_DIRECTION direction;

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

    insert(new node<T>(d,c));










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
    node<T> *ptr = head;

    //this is like locate but written differently
    for(; ptr; ptr = ptr->right) //GO THROUGH THE ENTIRE THING FIRST
    {
        if(*ptr == *n) // if n already exists
        {
            //cout << "found -- if n already exists";
            ptr->count += n->count;

            delete n;
            return;
        }
    }

    ptr = head; // bring the ptr back to head


    if(!head) //list is empty
    {
        //cout << "list is empty";
        head = tail = n;

        head->right = NULL; //IWT
        head->left = NULL;//IWT

        return;
    }
    if(*n < *head) //insert before head
    {
        //cout << "insert before head";
        //        n->right = head;
        head->left = n;
        n->right = head; //IWT
        head = n;
        return;
    }
    if(*n > *tail) //insert after tail
    {
        //cout << "insert after tail";
        tail->right = n;
        n->left = tail;
        tail = n;

        // head->right = NULL; //IWT
        //n->right = tail; //IWT
        return;
    }

    for(; *n > *ptr; ptr = ptr->right);//inserting something in the middle


    //cout << "inserting something in the middle";
    //        cout<< "PTR RIGHT IS: "; //THIS IS CORRECT
    //        cout << *ptr;

    n->left = ptr->left;      //iwt
    n->right = ptr;           //iwt
    ptr->left->right = n;     //iwt
    ptr->left = n;            //iwt





    // cout << "did not go through any condition";


    //======================MINE===========================
    //    node<T> *ptr=locate(n->data); //searches our list to find if any number matches, returns the location if found, returns NULL if not found.

    //    if (ptr) //if it is found at this point, that means that it already exists in the list
    //    {
    //        std::cout<<"DEBUG insert FOUND DUPLICATE: "<<std::endl;
    //        ptr->count=ptr->count+1; //increment the count

    //        delete ptr; //delete the new node

    //        return; //exit function
    //    }

    //    //if I survived to this point, it means that the new node doesn't exist in the list.

    //    ptr=head; //get ready to search our list again, by restarting the node at our head
    //    while(ptr && ptr<n) //increments ptr, until NULL, or ptr.data<n.data
    //    {
    //        ptr=ptr->right;
    //    }

    //    if (ptr)//if something is found at this point, it means that we found a bigger number on the right, so we want to insert on the left
    //    {
    //        std::cout<<"DEBUG insert ptr<n: "<<std::endl;

    //        if (ptr==head)//checks a special condition, if ptr is at head.
    //        {
    //            std::cout<<"DEBUG insert ptr<n ptr==head: "<<std::endl;

    //            n->right=ptr;
    //            //n->left=NULL;//already NULL to start with

    //            ptr->left=n;

    //            head=n;

    //            return;
    //        }
    //        else //ptr is in the middle somewhere (note: don't worry about tail here)
    //        {
    //            std::cout<<"DEBUG insert ptr<n middle: "<<std::endl;

    //            n->left=ptr->left;
    //            n->right=ptr;

    //            ptr->left->right=n;
    //            ptr->left=n;

    //            return;
    //        }

    //    }
    //    else //ptr>tail || list is entirely empty
    //    {
    //        if (tail) //check if there is something inside the list at all
    //        {
    //            std::cout<<"DEBUG insert ptr>n: "<<std::endl;

    //            //if we made it to this point, then there is something in the list and our new node is bigger than the tail
    //            n->left=tail;

    //            tail->right=n;

    //            tail=n;

    //            return;
    //        }
    //        else
    //        {
    //            std::cout<<"DEBUG insert EMPTY LIST "<<std::endl;

    //            //if we made it to this point, then the list is entirely empty

    //            head=tail=n;
    ////            n->left=n->right=NULL;//should be done already

    //            return;
    //        }
    //    }
    //========================================================












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
void doubleLinkedList<T>::remove(const T &d, int c)
{
    node<T> *bye = locate(d);
    if(!bye) //if bye is NULL
    {
        throw UNABLE_TO_REMOVE;
    }

    if((bye->count = bye->count - c) < 1 ) //if there is only 1 copy of that node, want to delete that node
    {
        if(bye == head) //special case, if bye is pointing at head
        {
            //head->right->left = NULL;
            head = head->right; //move the head
        }
        else
            if(tail == bye) //special case , if bye is pointing at tail
            {
                tail->left->right = NULL; //set previous node to point to NULL
                tail = tail->left; //set new tail
            }
            else //it's in the middle
            {
                bye->left->right = bye->right;
                bye->right->left = bye->left;
            }
        delete bye;
    }





    //=======================================================================

    //    node<T> *ptr=locate(d);

    //    std::cout<<"DEBUG remove() ptr->data: "<<ptr->data<<std::endl;
    //    std::cout<<"DEBUG remove() head: "<<head->data<<std::endl;
    //    std::cout<<"DEBUG remove() tail: "<<tail->data<<std::endl;


    //    if (ptr)
    //    {

    //        if (ptr==head) //if removing head
    //        {
    //            std::cout<<"DEBUG remove() ptr==head: "<<std::endl;

    //            if (head==tail) //if only one element in the list
    //            {
    //                std::cout<<"DEBUG remove() ptr==head head==tail: "<<std::endl;
    //                head=tail=NULL;
    //            }
    //            else
    //            {
    //                ptr->right->left=NULL;
    //                head=ptr->right;
    //            }

    //            delete ptr;
    //        }

    //        else if (ptr==tail) //if removing tail
    //        {
    //            std::cout<<"DEBUG remove() ptr==tail: "<<std::endl;
    //            ptr->left->right=NULL;

    //            tail=ptr->left;

    //            delete ptr;
    //        }

    //        else //if removing something in middle
    //        {
    //            std::cout<<"DEBUG remove() ptr==middle: "<<std::endl;

    //            node<T> *leftTemp= ptr->left;
    //            node<T> *rightTemp= ptr->right;


    //            std::cout<< "left mem address:" << leftTemp << std::endl;
    //            std::cout<< "right mem address:" << rightTemp << std::endl;

    //            //                        std::cout<< "left val:" << leftTemp->data <<std::endl;
    //            //                        std::cout<< "right val:" << rightTemp->data <<std::endl;

    //            //                        leftTemp->right=rightTemp;
    //            //                        rightTemp->left=leftTemp;

    //            //            ptr->left->right=ptr->right; //PROBLEM RIGHT HERE
    //            //            ptr->right->left=ptr->left; //PROBLEM RIGHT HERE

    //            std::cout<<"DEBUG :FVNJUUNBTRBYHNUJ "<<std::endl;
    //            //           delete ptr;
    //        }
    //    }
    //============================================================================
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
DLL_PRINT_DIRECTION& doubleLinkedList<T>::printDirection()
{
    return direction;
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
void doubleLinkedList<T>::merge(doubleLinkedList<T> &other)
{

    for (node<T> *ptr=other.head;ptr;ptr=ptr->right)
        insert(ptr->data, ptr->count);

    other.clear();

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
std::ostream& operator<<(std::ostream &out, doubleLinkedList<U> &other)
{

    if (out==std::cout)
    {
        if (other.printDirection() == ASCENDING) //print starting from head and incrementing
        {
            node<U> *ptr= other.head; //walker

            while(ptr) //while not NULL
            {
                out<<"["<<ptr->data<<":"<<ptr->count<<"]<->";

                ptr=ptr->right;
            }
            std::cout<<"NULL"<<std::endl;
        }
        else //print starting from tail and decrementing
        {
            node<U> *ptr= other.tail; //walker

            std::cout<<"NULL"<<std::endl;

            while(ptr) //while not NULL
            {
                out<<"<->["<<ptr->data<<":"<<ptr->count<<"]";

                ptr=ptr->left;
            }


        }


    }
    else //write into file
    {
//        std::ofstream myFile;

//        myFile.open ("DoubleLinkListSave.txt");

//        //how would I convert templated data to a string?

//        myFile.close();

    }


    return out;
}

template<typename U>
std::istream& operator>>(std::istream &in,  doubleLinkedList<U> &other)
{
//    if (in == std::cin)
//    {


//        doubleLinkedList<U>::insert();
//    }
//    else
//    {
//        std::ifstream myFile;
//        std::string line;
//        myFile.open("DoubleLinkListSave.txt");

//        if (myFile.is_open())
//        {
//            while(std::getline(myFile, line))
//            {
//                //read from file here and make a doubleLinkedList with data
//            }
//            myFile.close();
//        }
//        else
//        {
//            std::cout<<"UNABLE TO OPEN FILE: "<<std::endl;
//        }
//    }


//    return in;
}

template<typename T>
void doubleLinkedList<T>::nukem()
{
    node<T> *ptr = head;
    node<T>*bye;

    //    std::cout<<"DEBUG nukem()ptr: "<<&ptr<<std::endl;
    //    std::cout<<"DEBUG nukem()ptr: "<<&ptr->right<<std::endl;

    while(ptr)
    {
        bye=ptr;

        ptr=ptr->right;

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

