#ifndef PAIR
#define PAIR
#include <iostream>

template<typename key, typename value>
struct pair
{
    pair();
    pair(key k, value v);
    pair(const pair<key,value> &other);
    pair<key,value>& operator=(const pair<key,value> &other);
    ~pair();


    template<typename Key, typename Value>
    friend
    std::ostream& operator<<(std::ostream &out, const pair<Key,Value> &item);

    template<typename Key, typename Value>
    friend
    std::istream& operator>>(std::istream &in, pair<Key,Value> &item);

    key first;
    value second;
    pair<key,value>* next; //why do we need this?

};



template<typename key, typename value>
pair<key,value>::pair()
{
    first= key(); //sets type value to the default. ie: if a int is provided in the template first is set to 0
    //if a string is provided first is set to a empty string
    second=value();
    next=NULL;
}

template<typename key, typename value>
pair<key,value>::pair(key k, value v)
{
    first=k;
    second=v;
    next=NULL;
}

template<typename key, typename value>
pair<key,value>::pair(const pair<key,value> &other)
{
    first=other.first;
    second=other.second;
    next=other.next;
}

template<typename key, typename value>
pair<key,value>& pair<key,value>::operator=(const pair<key,value> &other)
{
    if (this !=&other)
    {
        first=other.first;
        second=other.second;
        next=other.next;
    }
    return *this;

}

template<typename key, typename value>
pair<key,value>::~pair()
{
    first=key();
    second=value();
}

template<typename key, typename value>
std::ostream &operator<<(std::ostream &out, const pair<key,value> &item)
{
    out<<"First: "<<item.first<<"   "<<"Second: "<<item.second;
    return out;
}

template<typename key, typename value>
std::istream &operator>>(std::istream &in, pair<key,value> &item)
{
    in >> item.first >> item.second;
    return in;
}

#endif // PAIR
