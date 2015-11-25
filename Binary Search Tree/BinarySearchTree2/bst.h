//How children find parents: [(childIndex-1)/2]
//How parent finds LEFT child [2 * parentIndex + 1]
//How parent finds RIGHT child [2 * parentIndex + 2]



#ifndef BST_H
#define BST_H
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "node.h"

using std::cin;
using std::cout;

enum TRAVERSE {PRE_ORDER,IN_ORDER, POST_ORDER, REVERSE_IN_ORDER};


template<typename T>
class bst
{
public:
    typedef void (bst<T>::*fptr)(ostream&, node<T>* ) const;
    bst(TRAVERSE how = IN_ORDER);
    ~bst();
    bst(const bst<T> &other);
    bst<T>& operator=(const bst<T> &other);

    void insert(const T &data, int count = 1);
    bool empty() const;
    void setTraversal(TRAVERSE how);
    TRAVERSE showTraversal() const;
    bool search(const T &data);
    bst<T>& operator<<(const T &data);
    bool remove(const T &data);
    bool balanced();
    void rebalance();
    unsigned int totalDataItems();
    void clear();

    node<T>* findParent(node<T>* start, const T &data, CHILD &which) const;
    node<T>* findRightMostChild(node<T>* &currentNode) const;
    node<T>* findLeftMostChild(node<T>* &currentNode) const;

    template<typename U>
    friend
    ostream& operator<<(ostream& out, const bst<U> &tree);

    template<typename U>
    friend
    istream& operator>>(istream& in, bst<U> &tree);

private:
    node<T> *root;
    fptr howToTraverse[4];
    TRAVERSE method;

    void copy(const node<T> *what);
    void insert(node<T> *&newNode, node<T> *where);
    void nukem(node<T>* &theNode);
    bool find(const T &data, node<T> *node);
    node<T>* locate(const T &data, node<T> *node);
    void inOrder(ostream& out, node<T> *node) const;
    void preOrder(ostream &out, node<T> *node)const ;
    void postOrder(ostream &out, node<T> *node) const;
    void reverseInOrder(ostream& out, node<T> *node) const;
    void swap2Things(T& thing1, T& thing2);
};


template<typename T>
bst<T>::bst(TRAVERSE how)
{
    method = how;
    root = NULL;
    howToTraverse[IN_ORDER] = &bst<T>::inOrder;
    howToTraverse[PRE_ORDER] = &bst<T>::preOrder;
    howToTraverse[POST_ORDER] = &bst<T>::postOrder;
    howToTraverse[REVERSE_IN_ORDER] = &bst<T>::reverseInOrder;
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
    typename bst<Z>::fptr whatToDo = tree.howToTraverse[tree.method];
    (tree.*whatToDo)(out,tree.root);

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
}

template<typename T>
void bst<T>::nukem(node<T>* &theNode) //PROBLEM HEREEEEEEEEEEEEE@@@@@@@@@@@@#@#@############@#@#@
{
    if(theNode->child(LEFT))
        nukem(theNode->child(LEFT));
    if(theNode->child(RIGHT))
        nukem(theNode->child(RIGHT));

    theNode = NULL;
    delete theNode;
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
void bst<T>::inOrder(ostream& out, node<T> *node) const
{
    if(node) //if the node exists
    {
        if(node->child(LEFT) ) //keeps doing the left side, unti    l there is no more left side, then comes back and continues on with this function
            inOrder(out, node->child(LEFT));

        //-------processing--------- //order significantly matters here
        out<<*node<<":"<<node->getCount()<<" ";//our processing, this is the most important part that dictates what order our tree will take.

        //--------------------------

        if(node->child(RIGHT))//keeps doing the right side, until there is no more right side, then comes back and continues on with this function
            inOrder(out, node->child(RIGHT));
    }
}

template<typename T>
void bst<T>::preOrder(ostream &out, node<T> *node) const
{
    if(node)
    {
        out<<*node<<":"<<node->getCount()<<" ";//our processing, this is the most important part that dictates what order our tree will take.
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
        out<<*node<<":"<<node->getCount()<<" ";//our processing, this is the most important part that dictates what order our tree will take.
    }
}

template<typename T>
void bst<T>::reverseInOrder(ostream& out, node<T> *node) const
{
    if(node) //if the node exists
    {
        if(node->child(RIGHT))//keeps doing the right side, until there is no more right side, then comes back and continues on with this function
            inOrder(out, node->child(RIGHT));

        //-------processing--------- //order significantly matters here
        out<<*node<<":"<<node->getCount()<<" ";//our processing, this is the most important part that dictates what order our tree will take.
        //--------------------------
        if(node->child(LEFT) ) //keeps doing the left side, until there is no more left side, then comes back and continues on with this function
            inOrder(out, node->child(LEFT));

    }
}

template <typename T>
void swap2Things(T& thing1, T& thing2)
{
    T bank=0;

    bank=thing1;
    thing1=thing2;
    thing2=bank;
}

template<typename T>
bool bst<T>::remove(const T &data)
{




















//    //---------------------------------------------------

//    //start at target

//    //if right child exists go right one child
//    //go to the LEFT most child of that child
//    //swap LEFT most child with target

//    //else if right doesn't exist go left 1 child
//    //go to the RIGHT most child of that child
//    //swap RIGHT most child with target

//    if (!root)//if the list is completly empty
//    {
//        return false;
//    }

//    node<T>* target=locate(data,root);

//    if (target && target->getCount()>1) //if I have more than 1 duplicate
//    {
//         target->setCount(target->getCount()-1);//decrement count

//        return true;
//    }

//    if (!target->child(LEFT) && !target->child(RIGHT))//if I have no children
//    {
//        delete target;
//        target=NULL;

//        return true;
//    }

//    if (target->child(RIGHT)) //if my right child exists
//    {
//        node<T>* leftMost= findLeftMostChild(target->child(RIGHT)); //goes to the leftmost child of target's child
//        CHILD whichChild;
//        if (leftMost->child(RIGHT))//if the leftMost child has a right child
//        {
//            //have the leftMost child's parent's left, point to leftMost child's right child
//            node<T>* parentOfLeftMost = findParent(leftMost,leftMost->readData(),whichChild);
//            parentOfLeftMost->child(LEFT)=leftMost->child(RIGHT);
//        }

//        //swap leftMost with Target
//        leftMost->child(LEFT)=target->child(LEFT);
//        leftMost->child(RIGHT)=target->child(RIGHT);

//        //delete target
//        target->child(LEFT)=NULL;
//        target->child(RIGHT)=NULL;

//        delete target;

//        return true;
//    }
//    else //else my left child MUST exist
//    {
//        node<T>* rightMost= findRightMostChild(target->child(LEFT)); //goes to the rightmost child of target's child
//        CHILD whichChild;
//        if (rightMost->child(LEFT))//if the leftMost child has a left child
//        {
//            //have the leftMost child's parent's left, point to leftMost child's right child
//            node<T>* parentOfLeftMost = findParent(rightMost,rightMost->readData(),whichChild);
//            parentOfLeftMost->child(RIGHT)=rightMost->child(LEFT);
//        }

//        //swap leftMost with Target
//        rightMost->child(LEFT)=target->child(LEFT);
//        rightMost->child(RIGHT)=target->child(RIGHT);

//        //delete target
//        target->child(LEFT)=NULL;
//        target->child(RIGHT)=NULL;

//        delete target;


//        return true;
    }
    //---------------------------------------------------



    //---------------------------------------------------
    //    //GET READY TO SWAP WITH RIGHT CHILD
    //    //  make a fakeParent to be root's parent
    //    //  keep track of my left side
    //    //  keep track of parent

    //    //PROMOTE RIGHT CHILD
    //    //  set parent's left to my right
    //    //  find parent's LAST left child
    //    //  set parent's last left child's left to MY left side

    //    //DELETE MYSELF
    //    if(!root)
    //        return false;

    //    CHILD which;
    //    node<T>* tempRoot;
    //    std::cout<<"DEBUGYBFIBAFIYBI : "<<std::endl;
    //    tempRoot->child(LEFT) = tempRoot->child(RIGHT) = root;// PROBLEM HERE!! can't set tempRoot->child(LEFT) or tempRoot->child(RIGHT) equal to something
    //    std::cout<<"DEBUG root: "<<root<<std::endl;
    //    std::cout<<"DEBUG tempRoot->child(LEFT): "<<tempRoot->child(LEFT)<<std::endl;
    //    std::cout<<"DEBUG tempRoot->child(RIGHT): "<<tempRoot->child(RIGHT)<<std::endl;

    //    node<T>* parent = findParent(tempRoot,data,which);

    //    if(!parent)
    //        return false;

    //    node<T>* seeYa = parent->child(which);

    //    if(seeYa->getCount() <= 1 )
    //    {
    //        parent->child(which) = seeYa->child(RIGHT);
    //        delete seeYa;
    //    }
    //    else
    //    {
    //        --seeYa;
    //    }
    //---------------------------------------------------

















    //--------------------------------------------------
    //MEJAN'S
    //        CHILD mySide;
    //        node<T>* myParent=findParent(root,data,mySide);
    //        node<T>* priorityPointer=NULL;

    //        node<T>* me=myParent->child(mySide);


    //        if (myParent->child(RIGHT))
    //        {
    //            priorityPointer=me->child(RIGHT);
    //        }
    //        else if (myParent->child(LEFT))
    //        {
    //            priorityPointer=me->child(LEFT);
    //        }


    //        if (mySide==RIGHT)
    //        {
    //            myParent->child(RIGHT)=priorityPointer;
    //        }
    //        else
    //        {
    //            myParent->child(LEFT)=priorityPointer;
    //        }

    //        node<T>* leftMost=findLeftMostChild(me);
    //        leftMost = priorityPointer->child(LEFT);

    //--------------------------------------------------









}

template<typename T>
bool bst<T>::balanced()
{

}

template<typename T>
void bst<T>::rebalance()
{

}

template<typename T>
unsigned int bst<T>::totalDataItems()
{

}


template<typename T>
void bst<T>::clear()
{
    nukem(root);
}
template<typename T>
node<T>* bst<T>::findParent(node<T>* start, const T &data, CHILD &which) const
{
    node<T> *top = start;
    bool cont = true;

    while(top && cont)
        if(top->child(LEFT)&&top->child(LEFT)->readData() == data)
        {
            which = LEFT;
            cont = false;
        }
        else
            if(top->child(RIGHT)&&top->child(RIGHT)->readData() == data)
            {
                which = RIGHT;
                cont = false;
            }
            else
                if(data < top->child(LEFT)->getData())
                    top = top->child(LEFT);
                else
                    top = top->child(RIGHT);
    return top;
}

template<typename T>
node<T>* bst<T>::findRightMostChild(node<T>* &currentNode) const
{
    node<T>* top = currentNode;
    while(top->child(RIGHT))
        top = top->child(RIGHT);
    return top;
}

template<typename T>
node<T>* bst<T>::findLeftMostChild(node<T>* &currentNode) const
{
    node<T>* top = currentNode;
    while(top->child(LEFT) && (top = top->child(LEFT)));
    return top;
}
#endif // BST_H
