#ifndef PAIR_H
#define PAIR_H
#include <iostream>


template<typename key, typename value>
struct pair
{
    pair();
    pair(key k, value v);
    pair(const pair<key,value> &other);
    pair<key,value>& operator=(const pair<key,value> &other);
    pair<key,value>& operator=(const value &other);
    ~pair();

    template<typename Key, typename Value>
    friend
    std::ostream& operator<<(std::ostream &out, const pair<Key,Value> &item);

    template<typename Key, typename Value>
    friend
    std::istream& operator>>(std::istream &in, const pair<Key,Value> &item);

    template<typename Key, typename Value>
    friend
    bool operator <(const pair<Key,Value>& x, const pair<Key,Value> &y);


    template<typename Key, typename Value>
    friend
    bool operator >(const pair<Key,Value>& x, const pair<Key,Value> &y);


    template<typename Key, typename Value>
    friend
    bool operator <=(const pair<Key,Value>& x, const pair<Key,Value> &y);


    template<typename Key, typename Value>
    friend
    bool operator >=(const pair<Key,Value>& x, const pair<Key,Value> &y);

    template<typename Key, typename Value>
    friend
    bool operator ==(const pair<Key,Value>& x, const pair<Key,Value> &y);


    template<typename Key, typename Value>
    friend
    bool operator !=(const pair<Key,Value>& x, const pair<Key,Value> &y);


    key first;
    value second;
};


template<typename key, typename value>
pair<key,value>::pair()
{
    first = key();
    second = value();
}

template<typename key, typename value>
pair<key,value>::pair(key k, value v)
{
    first = k;
    second = v;
}

template<typename key, typename value>
pair<key,value>::pair(const pair<key,value> &other)
{
    first = other.first;
    second = other.second;
}

template<typename key, typename value>
pair<key,value>& pair<key,value>::operator=(const pair<key,value> &other)
{
    if(this != &other)
    {
        first = other.first;
        second = other.second;
    }

    return *this;
}

template<typename key, typename value>
pair<key,value>& pair<key,value>::operator=(const value &other)
{
    if(this != &other)
        second=other;

    return *this;

}

template<typename key, typename value>
pair<key,value>::~pair()
{
    first = key();
    second = value();
}

template<typename Key, typename Value>
std::ostream& operator<<(std::ostream &out, const pair<Key,Value> &item)
{
    if(out == std::cout)
        out<<"first: "<<item.first<<" second: "<<item.second<<" ";
    else
        out<<item.first<<std::endl<<item.second<<std::endl;
    return out;
}

template<typename Key, typename Value>
std::istream& operator>>(std::istream &in, const pair<Key,Value> &item)
{
    std::cout<<"first: ";
    in>>item.first;
    std::cout<<std::endl;
    std::cout<<"second: ";
    in>>item.second;

    return in;
}


template<typename key, typename value>
bool operator<(const pair<key,value>& x, const pair<key,value> &y)
{
    return (x.first<y.first);
}


template<typename key, typename value>
bool operator>(const pair<key,value>& x, const pair<key,value> &y)
{
    return (x.first>y.first);
}


template<typename key, typename value>
bool operator<=(const pair<key,value>& x, const pair<key,value> &y)
{
    return (x.first<=y.first);
}


template<typename key, typename value>
bool operator>=(const pair<key,value>& x, const pair<key,value> &y)
{
    return (x.first>=y.first);
}

template<typename key, typename value>
bool operator==(const pair<key,value>& x, const pair<key,value> &y)
{
    return (x.first==y.first);
}


template<typename key, typename value>
bool operator!=(const pair<key,value>& x, const pair<key,value> &y)
{
    return (x.first!=y.first);
}



#endif // PAIR_H

