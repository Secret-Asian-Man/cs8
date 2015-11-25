#ifndef BST_H
#define BST_H
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include "node.h"

using std::cin;
using std::cout;

enum TRAVERSE {PRE_ORDER,IN_ORDER, POST_ORDER};


template<typename T>
class bst
{
public:
    typedef void (bst<T>::*fptr)(ostream&, node<T>* ) const;
    bst(TRAVERSE how = IN_ORDER);
    ~bst();
    bst(const bst<T> &other);
    bst<T>& operator=(const bst<T> &other);
    bool remove(const T &data);
    void insert(const T &data, int count = 1);
    bool empty() const;
    void setTraversal(TRAVERSE how);
    TRAVERSE showTraversal() const;
    bool search(const T &data);
    bst<T>& operator<<(const T &data);
    bool balanced();
    void rebalance(node<T>* &parent);

    unsigned int totalDataItems();
    void clear();
    int depth();

    template<typename U>
    friend
    ostream& operator<<(ostream& out, const bst<U> &tree);

    template<typename U>
    friend
    istream& operator>>(istream& in, bst<U> &tree);

private:
    node<T> *root;
    fptr howToTraverse[3];
    TRAVERSE method;

    node<T>* locate(const T &data, node<T> *node);
    void copy(const node<T> *what);
    void insert(node<T> *&newNode, node<T> *where);
    void nukem(node<T>* &theNode);
    bool find(const T &data, node<T> *node);
    void inOrder(ostream& out, node<T> *node) const;
    void preOrder(ostream &out, node<T> *node)const ;
    void postOrder(ostream &out, node<T> *node) const;
    node<T>* findParent(node<T>* start, const T &data, CHILD &which) const;
    node<T>* findRightMostChild( node<T> *currentNode) const;
    node<T>* findLeftMostChild( node<T> *currentNode) const;
    unsigned int totalDataItems(node<T>* top);
    int depth(node<T> *subTreeRoot);
    bool balanced(node<T> *subTreeRoot);
    node<T> *rotateWithLeftChild(node<T>* target);
    node<T> *rotateWithRightChild(node<T> *target);
    node<T>* doubleRotateWithLeftChild(node<T> *k3);
    node<T>* doubleRotateWithRightChild(node<T> *k1);
    void AlexPrint(node<T>* root, int depth) const;

};


template<typename T>
bst<T>::bst(TRAVERSE how)
{
    method = how;
    root = NULL;
    howToTraverse[IN_ORDER] = &bst<T>::inOrder;
    howToTraverse[PRE_ORDER] = &bst<T>::preOrder;
    howToTraverse[POST_ORDER] = &bst<T>::postOrder;
}

template<typename T>
bst<T>::~bst()
{
    nukem(root);
}

template<typename T>
bst<T>::bst(const bst<T> &other)
{
    copy(other.root);
}


template<typename T>
bst<T>& bst<T>::operator=(const bst<T> &other)
{
    if(this != &other)
    {
        nukem(root);
        copy(other.root);
    }
    return *this;
}

template<typename T>
void bst<T>::insert(const T &data, int count)\
{
    node<T>* newNode = new node<T>(data,count);
    insert(newNode, root);
}

template<typename T>
bool bst<T>::empty() const
{
    return !root;
}

template<typename T>
void bst<T>::setTraversal(TRAVERSE how)
{
    method = how;
}

template<typename T>
TRAVERSE bst<T>::showTraversal() const
{
    return method;
}

template<typename T>
bool bst<T>::search(const T &data)
{
    return find(data,root);
}

template<typename T>
bst<T>& bst<T>::operator<<(const T &data)
{
    insert(data);
    return *this;
}

template<typename Z>
ostream& operator<<(ostream& out, const bst<Z> &tree)
{
    if(tree.empty())
    {
        out<<"Emtpy tree!"<<endl;
        return out;
    }
//    typename bst<Z>::fptr whatToDo = tree.howToTraverse[tree.method];
//    (tree.*whatToDo)(out,tree.root);

    tree.AlexPrint(tree.root, 0);


    //Let's say there are 100 trees all using the same 4 functions
    // "tree.*whatTodo" tells us which data from which tree we are about to use in the function.
    //whatToDo(parameters) actually dereferences and uses the function
    return out;
}

template<typename U>
istream& operator>>(istream& in, bst<U> &tree)
{
    U data;
    int count;
    while(in>>data>>count)
        tree.insert(data,count);
    return in;
}


template<typename T>
void bst<T>::copy(const node<T> *what)
{
    insert(what->getData(),what->getCount());
    copy(what->child(LEFT));
    copy(what->child(RIGHT));
}


template<typename T>
void bst<T>::insert(node<T>* &newNode, node<T> *where)
{
    if(!root) // same as if(root == NULL)
    {
        cout<<"Empty tree gets new root"<<endl;
        root = newNode;
    }
    else
    {
        if(where->getData() == newNode->getData())//if that piece of data exists already
        {
            where->setCount((where->getCount()+newNode->getCount())) ; //add on the count onto the existing node.
            delete newNode; //destroy the new node after, we don't need it anymore
        }

        //----------------organizes the tree----------
        else if(newNode->getData() < where->getData()) //if my new data is smaller
        {
            if(!where->child(LEFT)) //if there is nothing left on the left side
                where->child(LEFT) = newNode; //put in the new node
            else
                insert(newNode,where->child(LEFT)); //else keep going left.
        }
        else //my new data is bigger
        {
            if(!where->child(RIGHT))
                where->child(RIGHT) = newNode;
            else
                insert(newNode,where->child(RIGHT));
        }
        //--------------------------------------------

    }

    rebalance(newNode);
}


template<typename T>
void bst<T>::nukem(node<T>* &theNode)
{
    if (theNode)
    {
        if(theNode->child(LEFT))
            nukem(theNode->child(LEFT));
        if(theNode->child(RIGHT))
            nukem(theNode->child(RIGHT));
        delete theNode;
        theNode = NULL;
    }

}

template<typename T>
bool bst<T>::find(const T &data, node<T> *node)
{
    if (!root)
        return false;

    if (data==node->readData())
        return true;

    if (node->child(LEFT) && data < node->readData())
        return find(data, node->child(LEFT));
    else if (node->child(RIGHT))
        return find(data, node->child(RIGHT));

    return false;
}

template<typename T>
int bst<T>::depth()
{
    return depth(root);
}

template<typename T>
int bst<T>::depth(node<T> *subTreeRoot)
{
    return subTreeRoot ? 1 + (depth(subTreeRoot->child(LEFT)), depth(subTreeRoot->child(RIGHT)))
                       : 0;
}

template<typename T>
void bst<T>::inOrder(ostream& out, node<T> *node) const
{
    if(node)
    {
        if(node->child(LEFT) )
            inOrder(out, node->child(LEFT));
        out<<*node<<" ";
        if(node->child(RIGHT))
            inOrder(out, node->child(RIGHT));
    }
}

template<typename T>
void bst<T>::preOrder(ostream &out, node<T> *node) const
{
    if(node)
    {
        out<<*node<<" ";
        if(node->child(LEFT))
            preOrder(out, node->child(LEFT));
        if(node->child(RIGHT))
            preOrder(out, node->child(RIGHT));
    }
}

template<typename T>
void bst<T>::postOrder(ostream &out, node<T> *node) const
{
    if(node)
    {
        if(node->child(LEFT))
            postOrder(out, node->child(LEFT));
        if(node->child(RIGHT))
            postOrder(out, node->child(RIGHT));
        out<<*node<<" ";
    }
}

template<typename T>
node<T>* bst<T>::locate(const T &data, node<T> *node)
{
    if (!root)
        return NULL;

    if (data==node->readData())
        return node;

    if (node->child(LEFT) && data < node->readData())
        return locate(data, node->child(LEFT));
    else if (node->child(RIGHT))
        return locate(data, node->child(RIGHT));

}


template<typename T>
bool bst<T>::remove(const T &data)
{
    if(!root)// if tree is completely empty
        return false; //get out, don't do anything.

    if (!locate(data,root))
        return false;

    CHILD which;

    node<T> fakeParent;
    fakeParent.child(LEFT) = fakeParent.child(RIGHT) = root;//fake parent

    node<T>*parent = findParent(&fakeParent,data,which);
    if(!parent)
        return false;

    node<T>* target = parent->child(which);

    if((--(*target)).getCount() < 1 ) //decrement the count and if the count becomes 0
    {
        /*
                      How am I going to be deleting this node:

                        1. The node to be deleted has no children. So, just make
                           the appropriate link to the node to be deleted point to NULL.

                        2. Node to be deleted is the left child of the parent
                            a. The node to be deleted does not have a right child, so
                               connect the left child to its grandparent and end
                            b. If the node to be deleted does have a right child, attach the
                               right child to the left side of its grandparent, and then
                               attach the left child to the left-most child of the right child
                               of the node to be deleted.

                        3. Node to be deleted is the right child of the parent
                            a. The node to be deleted does not have a right child.
                               Then we just promote the left child.
                            b. If the node to be deleted does have a right child, promote it
                               and then find the left most child of the right child and attach
                               the left subtree to the left-most child.
                     */
        /*
                      The following if, which would be done by a programmer,
                      can be made more efficient by de Morgan's Laws to the
                      if we are using

                        if(!target->child(left) && !target->child(right))
                   */
        if(!(target->child(LEFT) || target->child(RIGHT)))//The node to be deleted has no children.
            parent->child(which) = NULL;//So, just make the appropriate link to the node to be deleted point to NULL.
        else
            if(target->child(RIGHT))
            {
                parent->child(which)= target->child(RIGHT);
                node<T> *leftMost = findLeftMostChild(target->child(RIGHT));
                leftMost->child(LEFT) = target->child(LEFT);
            }
            else
            {

                parent->child(which) = target->child(LEFT);
                node<T> *rightMost = findRightMostChild(target->child(LEFT));
                rightMost->child(RIGHT) = target->child(RIGHT);
            }

        delete target;
    }

    if(&fakeParent == parent)
        root = parent->child(which);

    return true;

}

template<typename T>
bool bst<T>::balanced()
{
    return balanced(root);
}

template<typename T>
bool bst<T>::balanced(node<T> *subTreeRoot)
{
    return  !root ? true : abs(depth(subTreeRoot->child(LEFT)) - depth(subTreeRoot->child(RIGHT))) <= 1;
}

template<typename T>
void bst<T>::rebalance(node<T>* &parent)
{
    if(balanced(parent)) //if tree is already balanced return without extra work
        return;

    int leftChildDepth = depth(parent->child(LEFT));
    int rightChildDepth = depth(parent->child(RIGHT));

    bool whichChild = rightChildDepth < leftChildDepth; //at this point will be off balanced.
    CHILD child[] = {LEFT,RIGHT};//keeps track of which child is bigger

    node<T>* grandparent = findParent(root, parent->getData(), child[whichChild]);
    if(whichChild)
        //this means the left side has a larger depth
        //this means a RIGHT rotaion
        if(parent->child(LEFT)->child(LEFT))
            rotateWithLeftChild(grandparent);
        else
            doubleRotateWithLeftChild(grandparent);
    else
        if(parent->child(RIGHT)->child(RIGHT))
            rotateWithRightChild(grandparent);
        else
            doubleRotateWithRightChild(grandparent);
}

/* Rotate binary tree node with left child */
template<typename T>
node<T>* bst<T>::rotateWithLeftChild(node<T>* target)
{
    //https://www.youtube.com/watch?v=uZueM4b9qA0
    //need parent to hold the rotation together

    CHILD which;
    node<T>* parent=findParent(root,target->readData(),which);

    if (!parent) //if I have no parents make a fake parent
    {
        parent=new node<T>;
        parent->child(LEFT)=target;
        parent->child(RIGHT)=target;
    }

    node<T>* targetsRight=target->child(RIGHT);
    node<T>* targetsRightsLeft=targetsRight->child(LEFT);
    node<T>*targetsRightsRight=targetsRight->child(RIGHT);

    parent->child(which)=targetsRight;
    targetsRight->child(LEFT)=target;
    target->child(RIGHT)=targetsRightsLeft;
    targetsRight->child(RIGHT)=targetsRightsRight;

    return target;



    //    node<T> *me = k2->child(LEFT);
    //    k2->child(LEFT) = me->child(RIGHT);
    //    me->child(RIGHT) = k2;
    //    return me;
}

/* Rotate binary tree node with right child */
template<typename T>
node<T>* bst<T>::rotateWithRightChild(node<T> *target)
{
    CHILD which;
    node<T>* parent=findParent(root,target->readData(),which);

    if (!parent) //if I have no parents make a fake parent
    {
        parent=new node<T>;
        parent->child(LEFT)=target;
        parent->child(RIGHT)=target;
    }

    node<T>* targetsLeft=target->child(LEFT);
    node<T>* targetsLeftsRight=targetsLeft->child(RIGHT);
    node<T>*targetsLeftsLeft=targetsLeft->child(LEFT);

    parent->child(which)=targetsLeft;
    targetsLeft->child(RIGHT)=target;
    target->child(LEFT)=targetsLeftsRight;
    targetsLeft->child(LEFT)=targetsLeftsLeft;

    return target;





    //    node<T> *k2 = k1->child(RIGHT);
    //    k1->child(RIGHT) = k2->child(LEFT);
    //    k2->child(LEFT) = k1;
    //    return k2;
}

/*
 * Double rotate binary tree node: first left child
 * with its right child; then node k3 with new left child
 */
template<typename T>
node<T> *bst<T>::doubleRotateWithLeftChild(node<T> *k3)
{
    k3->child(LEFT) = rotateWithRightChild(k3->child(LEFT));
    return rotateWithLeftChild(k3);
}

/*
 * Double rotate binary tree node: first right child
 * with its left child; then node k1 with new right child
 */
template<typename T>
node<T>* bst<T>::doubleRotateWithRightChild(node<T> *k1)
{
    k1->child(RIGHT) = rotateWithLeftChild(k1->child(RIGHT));
    return rotateWithRightChild(k1);
}

template<typename T>
void bst<T>::AlexPrint(node<T>* root, int depth) const
{
    if (root)
    {
        AlexPrint(root->child(LEFT), depth + 1);
        for (int i = 0; i < 2*depth; i++) cout << " ";
        cout << depth<<":";
        cout << *root << endl;
        AlexPrint(root->child(RIGHT), depth + 1);
    }
}

template<typename T>
unsigned int bst<T>::totalDataItems()
{
    return totalDataItems(root);
}

template<typename T>
unsigned int bst<T>::totalDataItems(node<T>*currentNode)
{
    return currentNode ? currentNode->getCount()
                         +
                         totalDataItems(currentNode->child(LEFT))
                         +
                         totalDataItems(currentNode->child(RIGHT))
                       : 0;
}

template<typename T>
node<T>* bst<T>::findParent(node<T>* start, const T &data, CHILD &which) const
{

    node<T> *top = start;
    bool cont = true;


    if (top && data == top->readData()) //if I'm at the root then I have no parents return NULL

        return NULL;


    while(top && cont)

    {

        if(top->child(LEFT)&&top->child(LEFT)->readData() == data) //I found the data on the left side

        {
            which = LEFT;
            cont = false;
        }

        else if(top->child(RIGHT)&&top->child(RIGHT)->readData() == data)//I found the data on the right side

        {
            which = RIGHT;
            cont = false;
        }

        if(cont && top->child(RIGHT) && data > top->readData()) //dereferencing a NULL here(fixed) //cont stops the incrementing once found
            top = top->child(RIGHT); //increment to my left side


        else if(cont && top->child(LEFT))//cont stops the incrementing once found
            top = top->child(LEFT);//increment to my right side //dereferencing a NULL here(fixed)

    }

    return top;
}

template<typename T>
node<T>* bst<T>::findRightMostChild(node<T> *currentNode) const
{
    node<T>* top = currentNode;
    while(top->child(RIGHT))
        top = top->child(RIGHT);
    return top;
}

template<typename T>
node<T>* bst<T>::findLeftMostChild(node<T> *currentNode) const
{
    node<T>* top = currentNode;
    while(top->child(LEFT) && (top = top->child(LEFT)));
    return top;
}

template<typename T>
void bst<T>::clear()
{
    nukem(root);
}

#endif // BST_H
