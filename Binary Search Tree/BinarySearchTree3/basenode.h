#ifndef BASE_NODE_H
#define BASE_NODE_H
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>

using std::cin;
using std::cout;
enum CHILD {LEFT, RIGHT};

class base_node
{
    public:
        base_node();
        ~base_node();
        void*& theData();
        void *theData() const;
        base_node*& child(CHILD which);
        base_node* theNode();
        int getCount();
        int getCount() const;
        base_node& operator--();
        base_node& operator++();
        base_node& operator--(int);
        base_node& operator++(int);
        base_node& operator+=(int x);\
        base_node& operator-=(int x);

        void setCount(unsigned int x);


    private:
        void* data;
        int count;
        base_node *myChild[2];

};
#endif
