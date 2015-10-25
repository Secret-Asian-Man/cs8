#ifndef BASE_STACK_H
#define BASE_STACK_H
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "base_node.h"

enum BASE_STACK_ERRORS {EMPTY, FULL, ILLEGAL_SIZE};

class base_stack
{
    public:
        base_stack();
        bool empty() const;
        bool full() const;

    protected:
        base_node* pop(); //pops head
        base_node *top() const; //peeks at head
        void push(base_node* node); //pushes right behind head
//        void changeSize(unsigned int newSize);
        void changeMaxSize(unsigned int newMaxSize);
        unsigned int getSize();

    private:
        //to make a stack,
        base_node* tos; //top of stack, should behave like head
        unsigned int size, maxSize;
};

#endif // BASE_STACK_H
