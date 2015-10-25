#ifndef NODE
#define NODE
#include <iostream>
#include <fstream>
#include <cstdlib>


template<typename T>
struct node
{
    node()
    {
      count = 0;
      left = NULL;
      right = NULL;
      data = T();
    }

    node(const T& d, int c = 1, node<T>* l = NULL, node<T> *r = NULL)
        : count(c), data(d), left(l), right(r)
    {
        //blank

    }

    node(const node<T>&other)
    {

        data = other.data;
        count = other.count;
        left = right = NULL;
    }

    node<T>& operator=(const node<T> &other)
    {
        std::cout<<"DEBUG node<T> operator= FIRED: "<<std::endl;
        if(this != other)
        {
            data = other.data;
            count = other.count;
            left = right = NULL;
        }
        return *this;
    }

    ~node()
    {
        //doesn't like left = right = count = NULL

        left=NULL;
        right=NULL;
        count=NULL;
        data = T();
    }

    template<typename U>
    friend
    std::istream& operator>>(std::istream &in, node<U> &input);


    template<typename U>
    friend
    std::ostream& operator<<(std::ostream &out, const node<U> &output);

    template<typename U>
    friend
    bool operator<(const node<U>& x, const node<U> &y);


    template<typename U>
    friend
    bool operator>(const node<U>& x, const node<U> &y);


    template<typename U>
    friend
    bool operator<=(const node<U>& x, const node<U> &y);


    template<typename U>
    friend
    bool operator>=(const node<U>& x, const node<U> &y);

    template<typename U>
    friend
    bool operator==(const node<U>& x, const node<U> &y);


    template<typename U>
    friend
    bool operator!=(const node<U>& x, const node<U> &y);

    T data;
    int count;
    node *left;
    node *right;
};


template<typename U>
std::istream& operator>>(std::istream &in, node<U> &input)
{
    if (in==std::cin)
    {
        std::cout<<"Data: ";
        in>>input.data;
        std::cout<<"How many? ";
        in>>input.count;
    }
    else
    {
        in>>input.data;
        in>>input.count;
    }

    input.left = input.right = NULL;

    return in;
}


// \/ \/ \/ \/ \/ @@@@@@@@ THIS IS THE CAUSE OF THE AMBIGUOUS OPERATOR>> @@@@@\/ \/ \/ \/ \/ \/ \/ \/
//problem solved: I was supposed to return by reference like this "std::ostream& operator<<" isntead of this "std::ostream operator<<", AND use "const node<U> &output" instead "of const U &output"
template<typename U>
std::ostream& operator<<(std::ostream &out, const node<U> &output)
{
    if(out = std::cout)
        out<<output.data<<"["<<output.count<<"]  ";
    else
    {

    }
    return out;
}


template<typename U>
bool operator<(const node<U>& x, const node<U> &y)
{
    return x.data < y.data;
}


template<typename U>
bool operator>(const node<U>& x, const node<U> &y)
{
    return x.data > y.data;
}


template<typename U>
bool operator<=(const node<U>& x, const node<U> &y)
{
    return x.data <= y.data;
}


template<typename U>
bool operator>=(const node<U>& x, const node<U> &y)
{
    return x.data >= y.data;
}

template<typename U>
bool operator==(const node<U>& x, const node<U> &y)
{
    return x.data == y.data;
}


template<typename U>
bool operator!=(const node<U>& x, const node<U> &y)
{
    return x.data != y.data;
}

#endif // NODE

