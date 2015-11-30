#include "basenode.h"

base_node::base_node()
{
    count = 0;
    data = myChild[LEFT] = myChild[RIGHT] = NULL;
}

base_node::~base_node()
{
    count = 0;
    data = myChild[LEFT] = myChild[RIGHT] = NULL;
}

void* base_node::theData() const
{
    return data;
}


void*& base_node::theData()
{
    return data;
}


base_node*& base_node::child(CHILD which)
{
    return myChild[which];
}

base_node* base_node::theNode()
{
    return this;
}

int base_node::getCount()
{
    return count;
}

int base_node::getCount() const
{
    return count;
}

base_node& base_node::operator--(int)
{
    count--;
    return *this;
}

base_node& base_node::operator++(int)
{
    base_node temp = *this;
    count++;
    return temp;
}

base_node& base_node::operator--()
{
    count--;
    return *this;
}

base_node& base_node::operator++()
{
    count++;
    return *this;
}

base_node& base_node::operator+=(int x)
{
    count += x;
    return *this;
}

void base_node::setCount(unsigned int x)
{
    count = x;
}

base_node& base_node::operator-=(int x)
{
    count -= x;
    return *this;
}
