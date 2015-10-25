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
    return next;
}

base_node* base_node::theNode()
{
    return this;
}
