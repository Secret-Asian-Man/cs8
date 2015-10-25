#ifndef MAP_H
#define MAP_H
#include <iostream>
#include <iterator>
#include "pair.h"


#define MAX 100;

enum MAP_ERRORS {NOT_FOUND, EMPTY, UNABLE_TO_REMOVE};

template<typename key, typename value>//, typename compare = less>
class map
{
public:
    //constructors
    map();
    map(key k, value v);
    map(const map<key,value> &other);

    //destructor
    ~map();


    class const_iterator;
    class iterator;

    class iterator : public std::iterator<std::forward_iterator_tag, pair<key,value>*>
    {
    public:
        //constructors
        iterator();
        iterator(pair<key,value>*other);
        iterator(const iterator &other);
        iterator(const const_iterator &other);

        //destructor
        ~iterator();

        //operators
        iterator& operator=(const iterator &other);
        iterator& operator=(const const_iterator &other);
        iterator& operator=(pair<key,value> *pointer);
        iterator& operator=(const value &aValue);
        pair<key,value>* operator*();
        pair<key,value>* operator->();
        iterator& operator++() /*const*/;
        //        iterator& operator++(int) const;
        iterator& operator--();

        bool operator==(const iterator &other)const;
        bool operator!=(const iterator &other)const;



    private:
        pair<key,value> *ptr;



    };//class iterator END




    class const_iterator : std::iterator<std::forward_iterator_tag, pair<key,value>*>
    {
    public:
        //constructors
        const_iterator();
        const_iterator(pair<key,value>* p);
        const_iterator(const const_iterator &other);
        const_iterator(const iterator &other);

        //destructor
        ~const_iterator();



        //operators
        const_iterator& operator=(const const_iterator &other);
        const_iterator& operator=(const iterator &other);
        const_iterator& operator=(pair<key,value> *pointer);
        bool operator==(const const_iterator &other);
        bool operator!=(const const_iterator &other);

        pair<key,value>* operator*() const;
        pair<key,value>* operator->() const;
        const_iterator& operator++();


    private:
        pair<key,value> *ptr;
    };//class const_iterator END





    //class map CONTINUED*********

    //functions
    iterator begin();
    iterator end();
    iterator find(const key &k);
    //    iterator find(key k); //don't need another, have iterator find(const key &k) already
    bool empty();
    unsigned int size();
    unsigned int max_size();
    iterator at(const key &k);
    iterator insert(key k,value v);
    iterator insert(pair<key,value> *thePair);
    void remove(const key &k, int c=1);
    void swap(map<key,value> &other);
    void clear();
    bool count(const key& k);

    //operators
    map<key,value>& operator=(const map<key,value> &other);
    iterator operator[](const key &k);

    template<typename Key, typename Value>
    friend
    std::ostream& operator<<(std::ostream &out, map<Key,Value> &item);

    template<typename Key, typename Value>
    friend
    std::istream& operator>>(std::istream &in, map<Key,Value> &item);

private: //map private
    pair<key,value> *head;
    pair<key,value> *tail;
    iterator beginning; // made a change here used to be iterator beginning;
    iterator ending;
    unsigned int qty;

    //helper functions
    void copy(const map<key,value> &other);
    void nukem();

};//class map END






//-----------------------START CLASS MAP DEFINITIONS--------------------------
template<typename key, typename value>
map<key,value>::map()
{    
    ending = beginning = head = tail = NULL;

    // beginning = map<key,value>::const_iterator::const_iterator(&head); //replaced by: const_iterator temp(&head); beginning=temp;
    //head is an anchor, so it is initialized already at privates
    qty = 0;
}

template<typename key, typename value>
map<key,value>::map(key k, value v)
{
    //beginning = &head;
    qty = 1;

    tail = head = new pair<key,value>(k,v); //beginning and ending is pointing at the same thing so the forloop in main never runs

    iterator temp(head);
    beginning=ending=temp;

    //beginning=head.next; //I added. //the operator= doesn't seem to be working right





    //beginning and head.next both should not be NULL. This is not the case.
    //    if (beginning==NULL)
    //    {
    //        std::cout<<"beginning IS NULL"<<std::endl;
    //    }
    //    else
    //    {
    //        std::cout<<"beginning NOT NULL"<<std::endl;
    //    }

    //    if (head.next==NULL)
    //    {
    //        std::cout<<"head.next IS NULL"<<std::endl;
    //    }
    //    else
    //    {
    //        std::cout<<"head.next NOT NULL"<<std::endl;
    //        std::cout<<"head.next: "<<*head.next<<std::endl;
    //    }
}

template<typename key, typename value>
map<key,value>::map(const map<key,value> &other)
{

    copy(other);

}


template<typename key, typename value>
map<key,value>::~map()
{
    nukem();
}

template<typename key, typename value>
typename map<key,value>::iterator map<key,value>::begin()
{
    //    std::cout<<"DEBUG map<key,value>::begin(): FIRED"<<std::endl;
    //    if (!&beginning)
    //    {
    //        std::cout<<"DEBUG map<key,value>::begin(): NULL"<<std::endl;

    //    }


    return beginning;
}

template<typename key, typename value>
typename map<key,value>::iterator map<key,value>::end()
{
    return ending;
}

template<typename key, typename value>
typename map<key,value>::iterator map<key,value>::find(const key &k)
{
    pair<key,value> *ptr = head;

    for(; ptr && ptr->first != k; ptr = ptr->next); //ptr && ptr->first: ptr &&, means if ptr!=NULL
    if(!ptr)//if ptr !=NULL
    {
        iterator temp(NULL) ;//why does this work and the below doesn't?
        return temp;
//        throw NOT_FOUND;
    }

    iterator temp(ptr) ;//why does this work and the below doesn't?
    return temp;

    //    return typename map<key,value>::iterator(ptr); //already have a constructor that thats a pair pointer so, why cant it find it?

}

template<typename key, typename value>
bool map<key,value>::empty()
{
    return !qty; //if the qty is currently NULL, it will change into a 1, which returns true
}

template<typename key, typename value>
unsigned int map<key,value>::size()
{
    return qty;
}

template<typename key, typename value>
unsigned int map<key,value>::max_size()
{
    return MAX;
}

template<typename key, typename value>
typename map<key,value>::iterator map<key,value>::at(const key &k)//SUSPICIOUS should it be returned by reference?
{
    return insert(k,0);
}

template<typename key, typename value>
typename map<key,value>::iterator map<key,value>::insert(key k,value v)
{
    return insert(new pair<key,value>(k,v));
}


template<typename key, typename value>
typename map<key,value>::iterator map<key,value>::insert(pair<key, value> *thePair) //automatically detects where to insert using the letters
{
    //=================================iterator version===============================

    //    iterator it(head);
    //    iterator otherIt(thePair);


    //    //this is like locate but written differently
    //    for(; *it; ++it) //GO THROUGH THE ENTIRE THING FIRST
    //    {
    //        if(*it == *otherIt) // if n already exists
    //        {
    //            //cout << "found -- if n already exists";
    //            it->second += otherIt->second;

    //            delete *otherIt;

    //            return it; //don't need to increment count, cant return new pair, so return pair we edited
    //        }
    //    }

    //    it = head; // bring the ptr back to head


    //    if(!head) //list is empty
    //    {
    //        //cout << "list is empty";
    //        head = tail = *otherIt;

    //        head->next = NULL; //IWT
    //        head->prev = NULL;//IWT

    //        qty++;
    //        return otherIt;
    //    }
    //    if(*otherIt < head) //insert before head
    //    {
    //        //cout << "insert before head";
    //        //        n->right = head;
    //        head->prev = *otherIt;

    //        //*otherIt->next = head; //IWT
    //        ++otherIt;
    //        otherIt=head;
    //        --otherIt;

    //        head = *otherIt;

    //        qty++;
    //        return otherIt;
    //    }
    //    if(*otherIt > tail) //insert after tail
    //    {
    //        //cout << "insert after tail";
    //        tail->next = *otherIt;
    //        otherIt->prev = tail; //SUSPICIOUS
    //        tail = *otherIt;

    //        // head->right = NULL; //IWT
    //        //n->right = tail; //IWT
    //        qty++;
    //        return otherIt;
    //    }

    //    for(; *otherIt > *it; ++it);//inserting something in the middle


    //    //cout << "inserting something in the middle";
    //    //        cout<< "PTR RIGHT IS: "; //THIS IS CORRECT
    //    //        cout << *ptr;

    //    otherIt->prev = it->prev;      //iwt
    //    otherIt->next = *it;           //iwt
    //    it->prev->next = *otherIt;     //iwt
    //    it->prev = *otherIt;            //iwt

    //    qty++;
    //    return otherIt;
    //==========================================================================



    //=================================pair pointer version===============================
    pair<key,value> *ptr = head;
    pair<key,value> *otherPtr= thePair;

    //this is like locate but written differently
    for(; ptr; ptr = ptr->next) //GO THROUGH THE ENTIRE THING FIRST
    {
        if(*ptr == *otherPtr) // if n already exists
        {
            //cout << "found -- if n already exists";
            ptr->second += otherPtr->second;

            delete otherPtr;

            return iterator(ptr); //don't need to increment count, cant return new pair, so return pair we edited
        }
    }

    ptr = head; // bring the ptr back to head


    if(!head) //list is empty
    {
        //cout << "list is empty";
        head = tail = otherPtr;

        iterator temp(head);
        beginning=ending=temp;

        head->next = NULL; //IWT
        head->prev = NULL;//IWT

        qty++;
        return iterator(otherPtr);
    }

    if(*otherPtr < *head) //insert before head
    {
        //std::cout << "insert before head";
        //        n->right = head;
        head->prev = otherPtr;
        otherPtr->next = head; //IWT
        head = otherPtr;

        iterator temp(head);
        beginning = temp;


        qty++;
        return iterator(otherPtr);
    }
    if(*otherPtr > *tail) //insert after tail
    {
        //cout << "insert after tail";
        tail->next = otherPtr;
        otherPtr->prev = tail;
        tail = otherPtr;

        iterator temp(tail);
        ending = temp;


        // head->right = NULL; //IWT
        //n->right = tail; //IWT
        qty++;
        return iterator(otherPtr);
    }

    for(; *otherPtr > *ptr; ptr = ptr->next);//inserting something in the middle


    //cout << "inserting something in the middle";
    //        cout<< "PTR RIGHT IS: "; //THIS IS CORRECT
    //        cout << *ptr;

    otherPtr->prev = ptr->prev;      //iwt
    otherPtr->next = ptr;           //iwt
    ptr->prev->next = otherPtr;     //iwt
    ptr->prev = otherPtr;            //iwt

    qty++;
    return iterator(otherPtr);
    //========================================================================

}

template<typename key, typename value>
void map<key,value>::remove(const key &k, int c)
{

    //iterator has trouble removing pairs in middle
    //    iterator bye = find(k);

    //    if(! *bye) //if bye is NULL
    //    {
    //        throw UNABLE_TO_REMOVE;
    //    }

    //    if((bye->second = bye->second - c) < 1 ) //if there is only 1 copy of that node, want to delete that node
    //    {
    //        if(*bye == head) //special case, if bye is pointing at head
    //        {
    //            //head->right->left = NULL;
    //            head = head->next; //move the head

    //            iterator temp(head);
    //            beginning=temp;

    //        }
    //        else
    //            if(tail == *bye) //special case , if bye is pointing at tail
    //            {
    //                tail->prev->next = NULL; //set previous node to point to NULL
    //                tail = tail->prev; //set new tail

    //                iterator temp(tail);
    //                ending=temp;

    //            }
    //            else //it's in the middle
    //            {
    //                *bye->prev->next = *bye->next;
    //                *bye->next->prev = *bye->prev;
    //            }

    //        delete *bye; //SUSPICIOUS, would I need to delete the pair ptr inside the iterator before i delete the actual iterator?
    //    }


    //pair works fine
    pair<key,value> *ptr=*find(k);

    if(!ptr) //if bye is NULL
    {
        throw UNABLE_TO_REMOVE;
    }

    if((ptr->second = ptr->second - c) < 1 ) //if there is only 1 copy of that node, want to delete that node
    {
        if(ptr == head) //special case, if bye is pointing at head
        {
            //head->right->left = NULL;
            head = head->next; //move the head

            iterator temp(head);
            beginning=temp;

        }
        else
            if(tail == ptr) //special case , if bye is pointing at tail
            {
                tail->prev->next = NULL; //set previous node to point to NULL
                tail = tail->prev; //set new tail

                iterator temp(tail);
                ending=temp;

            }
            else //it's in the middle
            {
                ptr->prev->next = ptr->next;
                ptr->next->prev = ptr->prev;
            }

        --qty;
        delete ptr; //SUSPICIOUS, would I need to delete the pair ptr inside the iterator before i delete the actual iterator?
    }






















}

template<typename key, typename value>
void map<key,value>::swap(map<key, value> &other)
{
    //    swap each privates of both map classes

    pair<key,value> *temp_pair;
    iterator temp_It;
    int temp_int;

    temp_pair=head;
    temp_It=beginning;
    temp_int=qty;

    head=other.head;
    beginning=other.beginning;
    qty=other.qty;

    other.head=temp_pair;
    other.beginning=temp_It;
    other.qty=temp_int;

    temp_pair=tail;
    temp_It=ending;

    tail=other.tail;
    ending=other.ending;

    other.tail=temp_pair;
    other.ending=temp_It;






    //    pair<key,value> *temp = head;
    //    int qty = qty;
    //    qty = other.qty;
    //    other.qty = qty;
    //    head = other.head;
    //    other.head = temp;
    //    temp = tail;
    //    tail = other.tail;
    //    other.tail = temp;
}

template<typename key, typename value>
void map<key,value>::clear()
{
    nukem();
}

template<typename key, typename value>
bool map<key,value>::count(const key &k)
{

    return *find(k);

}

template<typename key, typename value>
map<key, value>& map<key,value>::operator=(const map<key, value> &other)
{
    if(this != &other)
        copy(other);
    return *this;
}



template<typename key, typename value>
typename map<key,value>::iterator map<key,value>::operator[](const key &k)
{
    return insert(k,0);
}


//template<typename key, typename value>
//typename map<key,value>::const_iterator &map<key,value>::operator=(const map<key,value>::const_iterator &other)
//{

//}

template<typename Key, typename Value>
std::ostream& operator<<(std::ostream &out, map<Key,Value> &item)
{
    typename map<Key,Value>::iterator it=item.begin();
    pair<Key,Value> *ptr=item.head;

    if(out == std::cout)
    {
        while(ptr)
        {
            std::cout<<"("<<ptr->first<<","<<ptr->second<<")<->";
            ptr=ptr->next;
        }
        std::cout<<"NULL"<<std::endl;

    }
    else
    {

    }

    return out;
}


template<typename Key, typename Value>
std::istream& operator>>(std::istream &in, map<Key,Value> &item)
{
    if(in == std::cin)
    {
        std::cout<<"Enter qty: ";
        in>>item.qty;
    }
    else
        in>>item.qty;
    return in;
}

template<typename key, typename value>
void map<key,value>::copy(const map<key, value> &other)
{
    nukem();

    pair<key,value> *ptr=other.head;

    while(ptr)
    {
        insert(new map<key,value>(*ptr));
        ptr=ptr->next;
    }




















    //    pair<key,value> *ptr = &head.next;
    //    pair<key,value> *other_ptr = &other.head.next;

    //    qty = other.qty;

    //    while(&other_ptr)
    //    {
    //        *ptr=*other_ptr;


    //        ptr=ptr->next;
    //        other_ptr=other_ptr->next;
    //    }

    //    ptr->next=NULL;

    //    for(; other_ptr; ++other_ptr)
    //    {
    //        ptr->next = other_ptr;
    //        ptr = ptr->next;
    //    }
}

template<typename key, typename value>
void map<key,value>::nukem()
{
    pair<key,value> *ptr = head;
    pair<key,value> *bye;


    while(ptr)
    {
        bye=ptr;

        ptr=ptr->next;

        delete bye;
        --qty;
    }

    head = tail = NULL;

    iterator temp(NULL);
    ending = temp;
    beginning = temp;



}
//-----------------------END CLASS MAP DEFINITIONS--------------------------




//-----------------------START CLASS ITERATOR DEFINITIONS--------------------------
template<typename key, typename value>
map<key,value>::iterator::iterator()//@@@@@@@@@@@@@@
{
    ptr = NULL;
}

template<typename key, typename value>
map<key,value>::iterator::iterator(pair<key,value> *other)
{
    ptr=other;
}

template<typename key, typename value>
map<key,value>::iterator::iterator(const map<key,value>::iterator &other)
{
    ptr = other.ptr;
}

template<typename key, typename value>
map<key,value>::iterator::iterator(const map<key,value>::const_iterator &other)
{
    ptr = other.ptr;
}

template<typename key, typename value>
map<key,value>::iterator::~iterator()
{
    ptr = NULL;
}

template<typename key, typename value>
typename map<key,value>::iterator& map<key,value>::iterator::operator=(const iterator &other)
{
    if(this != &other)
        ptr = other.ptr;

    return *this;
}

template<typename key, typename value>
typename map<key,value>::iterator& map<key,value>::iterator::operator=(const const_iterator &other)
{
    if(this != &other)
        ptr = other.ptr;

    return *this;
}

template<typename key, typename value>
typename map<key,value>::iterator& map<key,value>::iterator::operator=(pair<key,value> *pointer)
{
    if (*this != pointer)
    {
        iterator temp(pointer);
        return temp;
    }

    return *this;
}

template<typename key, typename value>
typename map<key,value>::iterator& map<key,value>::iterator::operator=(const value &aValue)
{
    ptr->second=aValue;

    return *this;
}

template<typename key, typename value>
pair<key,value>* map<key,value>::iterator::operator*()
{
    return ptr;
}

template<typename key, typename value>
pair<key,value>* map<key,value>::iterator::operator->()
{
    return ptr;
}

template<typename key, typename value>
typename map<key,value>::iterator::iterator& map<key,value>::iterator::operator++() /*const*/
{
    if (ptr)
    {
        ptr = ptr->next;
    }
}

//template<typename key, typename value>
//typename map<key,value>::iterator::iterator& map<key,value>::iterator::operator++(int) const
//{
//    if (ptr)
//    {
//        ptr = ptr->next;
//    }
//}

template<typename key, typename value>
typename map<key,value>::iterator::iterator& map<key,value>::iterator::operator--()
{
    if (ptr)
    {
        ptr = ptr->prev;
    }
}

template<typename key, typename value>
bool map<key,value>::iterator::operator==(const map<key,value>::iterator &other)const
{
    return (ptr==other.ptr);
}

template<typename key, typename value>
bool map<key,value>::iterator::operator!=(const map<key,value>::iterator &other)const
{
    return (ptr!=other.ptr);

}
//-----------------------END CLASS ITERATOR DEFINITIONS--------------------------











//-----------------------START CLASS CONST_ITERATOR DEFINITIONS--------------------------
template<typename key, typename value>
map<key,value>::const_iterator::const_iterator()
{
    ptr = NULL;
}

template<typename key, typename value>
map<key,value>::const_iterator::const_iterator(pair<key,value>* p)
{
    ptr = p;
}

template<typename key, typename value>
map<key,value>::const_iterator::const_iterator(const const_iterator &other)
{
    ptr = other.ptr;
}

template<typename key, typename value>
map<key,value>::const_iterator::const_iterator(const iterator &other)
{
    ptr = other.ptr;
}

template<typename key, typename value>
map<key,value>::const_iterator::~const_iterator()
{
    ptr = NULL;
}

template<typename key, typename value>
typename map<key,value>::const_iterator& map<key,value>::const_iterator::operator=(const const_iterator &other)
{
    if(this != &other)
        ptr = other.ptr;
    return *this;
}

template<typename key, typename value>
bool map<key,value>::const_iterator::operator==(const const_iterator &other)
{

    return (ptr->first == other.ptr->first && ptr->second == other.ptr->second); //compares the 2 values inside both the pairs

}

template<typename key, typename value>
bool map<key,value>::const_iterator::operator!=(const const_iterator &other)
{
    return !(*this == other); //takes advantage of the overloaded operator== I wrote above
}

template<typename key, typename value>
typename map<key,value>::const_iterator& map<key,value>::const_iterator::operator=(const iterator &other)
{
    ptr = other.ptr;
    return *this;
}

template<typename key, typename value>
typename map<key, value>::const_iterator &map<key, value>::const_iterator::operator=(pair<key, value> *pointer)
{
    if (*this != pointer)
    {
        const_iterator temp(pointer);
        return temp ;
    }

    return *this;
}

template<typename key, typename value>
pair<key,value>* map<key,value>::const_iterator::operator*() const
{
    return *ptr;
}

template<typename key, typename value>
pair<key,value>* map<key,value>::const_iterator::operator->() const
{
    return ptr;
}

template<typename key, typename value>
typename map<key,value>::const_iterator& map<key,value>::const_iterator::operator++()
{
    if (ptr)
    {
        ptr = ptr->next;
    }
    //return *this;
}
//-----------------------END CLASS CONST_ITERATOR DEFINITIONS--------------------------

























//This is a redeclaration
//template<typename key, typename value>
//map<key,value>::iterator::iterator(pair<key,value> *other)
//{
//    ptr = other;
//}
























#endif // MAP_H
