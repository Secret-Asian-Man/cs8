#include "base_node.h"

base_node::base_node()
{
    data = next = NULL;
}

base_node::~base_node()
{
    data = next = NULL;
}

void*& base_node::theData()
{
    return data;
}

base_node*& base_node::nextNode()
{
//    std::cout<<"DEBUG nextNode() next: "<<next<<std::endl;
    return next;
}

base_node* base_node::theNode()
{
    return this;
}
