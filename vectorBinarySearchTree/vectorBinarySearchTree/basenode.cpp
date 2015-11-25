#include "basenode.h"

base_node::base_node()
{
    data = myChild[LEFT] = myChild[RIGHT] = NULL;
}

base_node::~base_node()
{
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

void base_node::operator--(int)
{
    count--;
}

void base_node::operator++(int)
{
    count++;
}

void base_node::operator--()
{
    count--;
}

void base_node::operator++()
{
    count++;
}

void base_node::operator+=(int x)
{
    count += x;
}

void base_node::setCount(unsigned int x)
{
    count = x;
}

void base_node::operator-=(int x)
{
    count -= x;
}
