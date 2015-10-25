#ifndef MAP
#define MAP
#include "pair.h"
#include <iostream>

template<typename key, typename value>//, typename compare = less>
class map
{
public:
    //contructors
    map();
    map(key k, value v);
    map(const map<key,value> &other);

    //destructor
    ~map();

    //assignment operator
    map<key,value>& operator=(const map<key,value> &other);



    class const_iterator;
    class iterator;



    class iterator : public std::iterator<std::forward_iterator_tag, pair<key,value>*>
    {
    public:
        iterator();
        iterator(pair<key,value>*other);
        iterator(iterator &other);
        iterator(const_iterator &other);
        iterator& operator=(iterator &other);
        iterator& operator=(const const_iterator &other);
        iterator& operator=(pair<key,value> *pointer);
        ~iterator();
        pair<key,value>& operator*();
        pair<key,value>* operator->();
        iterator& operator++() /*const*/;
        iterator& operator++(int) const;

    private:
        pair<key,value> *ptr;


    };//class iterator END





    class const_iterator : std::iterator<std::forward_iterator_tag, pair<key,value>*>
    {
    public:
        const_iterator();
        const_iterator(pair<key,value>*);
        const_iterator(const const_iterator &other);
        const_iterator(iterator &other);
        const_iterator& operator=(const const_iterator &other);
        const_iterator& operator=(iterator &other) const;
        const_iterator& operator=(pair<key,value> *pointer);
        ~const_iterator();

        pair<key,value>& operator*() const;
        pair<key,value>* operator->() const;
        const_iterator& operator++() /*const*/;
        const_iterator& operator++(int) const;


    private:
        pair<key,value> *ptr;
    };//class const_iterator END







    //class map CONTINUED


    //functions
    const_iterator begin();
    const_iterator end();
    iterator find(const key &k);

    //accessors
    bool empty();
    int size();
    int max_size();

    value& operator[](const key &k);
    value& at(const key &k);
    iterator insert(const pair<key,value> &thePair);
    void erase(const key &k);
    void swap(map<key,value> &other);
    void clear();
    int count(const key& k);

    const_iterator& operator=(const const_iterator &other);


    template<typename Key, typename Value>
    friend
    std::ostream& operator<<(std::ostream &out, const map<Key,Value> &item);

    template<typename Key, typename Value>
    friend
    std::istream& operator>>(std::istream &in, map<Key,Value> &item);

private:
    pair<key,value> head;
    pair<key,value> *tail;
    const_iterator beginning; //@@ made a change here used to be iterator beginning;
    const_iterator ending;
    int qty;

    void copy(const map<key,value> &other);
    void nukem();

};//class map END

//----------------map Class-----------------
template<typename key, typename value>
map<key,value>::map()
{

}

template<typename key, typename value>
map<key,value>::map(key k, value v)
{

}

template<typename key, typename value>
map<key,value>::map(const map<key,value> &other)
{

}

template<typename key, typename value>
map<key,value>::~map()
{

}

template<typename key, typename value>
map<key,value>& map<key,value>::operator=(const map<key,value> &other)
{

}

template<typename key, typename value>
typename map<key,value>::const_iterator map<key,value>::begin()
{

}

template<typename key, typename value>
typename map<key,value>::const_iterator map<key,value>::end()
{

}

template<typename key, typename value>
typename map<key,value>::iterator map<key,value>::find(const key &k)
{

}

template<typename key, typename value>
bool map<key,value>::empty()
{

}

template<typename key, typename value>
int map<key,value>::size()
{

}

template<typename key, typename value>
int map<key,value>::max_size()
{

}

template<typename key, typename value>
value& map<key,value>::operator[](const key &k)
{

}

template<typename key, typename value>
value& map<key,value>::at(const key &k)
{

}

template<typename key, typename value>
typename map<key,value>::iterator map<key,value>::insert(const pair<key,value> &thePair)
{

}

template<typename key, typename value>
void map<key,value>::erase(const key &k)
{

}

template<typename key, typename value>
void map<key,value>::swap(map<key,value> &other)
{

}

template<typename key, typename value>
void map<key,value>::clear()
{

}

template<typename key, typename value>
int map<key,value>::count(const key& k)
{

}

template<typename key, typename value>
typename map<key,value>::const_iterator& map<key,value>::operator=(const const_iterator &other)
{

}

template<typename key, typename value>
std::ostream& operator<<(std::ostream &out, const map<key,value> &item)
{

}

template<typename key, typename value>
std::istream& operator>>(std::istream &in, map<key,value> &item)
{

}

template<typename key, typename value>
void map<key,value>::copy(const map<key,value> &other)
{

}

template<typename key, typename value>
void map<key,value>::nukem()
{

}




//----------------iterator Class-----------------



//----------------const_iterator Class-----------------


#endif // MAP

