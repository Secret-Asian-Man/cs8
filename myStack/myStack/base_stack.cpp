#include "base_stack.h"

base_stack::base_stack()
{
    size = 0;
    maxSize = 10;
    tos=NULL;
}

bool base_stack::empty() const
{
    return !tos;
}

bool base_stack::full() const
{
    return size >= maxSize;
}

base_node* base_stack::pop()
{
    if(empty())
        throw EMPTY;

    base_node *temp = tos;
    tos = tos->nextNode(); //tos is NULL atm

    --size;
    return temp;
}

base_node* base_stack::top() const
{
    if(empty())
        throw EMPTY;

    return tos;
}

void base_stack::push(base_node* node)
{
    if(full())
        throw FULL;

//    std::cout<<"DEBUG node->nextNode(): "<<node->nextNode()<<std::endl;
//    std::cout<<"DEBUG tos->nextNode(): "<<tos<<std::endl; //something wrong with tos.next()

    node->nextNode() = tos;
    tos = node;

    ++size;
}

//Why would we want to be able to change the size, that would be a bad thing.
//Sizes should be the amount of nodes there is in the list not some random user input.
//void base_stack::changeSize(unsigned int newSize)
//{
//    if(newSize == 0 || newSize > maxSize)
//        throw ILLEGAL_SIZE;
//    size = newSize;
//}

void base_stack::changeMaxSize(unsigned int newMaxSize)
{
    if(newMaxSize <= 0)
        throw ILLEGAL_SIZE;

    maxSize = newMaxSize;
}

unsigned int base_stack::getSize()
{
    return size;
}
