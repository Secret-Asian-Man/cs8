#ifndef BASE_NODE_H
#define BASE_NODE_H
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>

using std::cin;
using std::cout;

class base_node
{
    public:
        base_node();
        ~base_node();
        void*& theData();
        base_node*& nextNode();
        base_node* theNode();

    protected:



    private:
        void* data;
        base_node *next;

};

#endif // BASE_NODE_H
