#include "orchard.h"
#include <fstream>

orchard::orchard()
{

}

orchard::orchard(const orchard &other)
{

}

orchard::~orchard()
{
    for (unsigned int i=0;i<ALPHABET_SIZE;++i)
        alphabetOrchard[i].clear();
}

orchard &orchard::operator =(const orchard &other)
{
    if (this != &other)
        copy(other);

    return *this;
}

std::ostream& operator<<(std::ostream &out, const orchard &q)
{
    //    if (out==std::cout)
    //        q.displayOrchard();
    //    else
    //        q.saveToFile();
}


/**
    The number of words which begin with each letter of the alphabet. Got to tree 'D' and display the count

    @param key: for selecting which tree
    @return number of words in that tree
*/
long int orchard::alphaFrequency(char key)
{
    alphabetOrchard[getHeapPosition(key)].getCount();
}

/**
    Gets certain heap

    @param key: for selecting which tree
    @return returns a reference to the original vectorHeap object
*/
vectorHeap<word>& orchard::getHeap(char key)
{
    return alphabetOrchard[getHeapPosition(key)];
}

void orchard::displayOrchard()
{

}

/**
    returns the position number in the alphabetOrchard array a associated to the letter

    @param char to convert to an unsigned int position in an array
    @return returns the position in the array associated with that char
*/
unsigned int orchard::getHeapPosition(char key)
{
    //the key should be uppercase due to the words class capitalizing the first letter of everyword
    // 'A'=65,    'Z'=90

    //'A'-65 = 0

    return key-65;
}

/**
    Takes words from tokenizer and sorts and adds them to the orchard

    @param
    @return
*/
void orchard::insert()
{
    word* temp=new word;

    while(tokens.getNextWord(temp))
    {
        if(!temp->getWord().empty())
        alphabetOrchard[getHeapPosition(temp->getFirstLetter())].insert(temp); //goes to the correct tree in the orchard and inserts a word into that tree

        temp=new word;
    }


}




void orchard::saveToFile()
{
//    std::ofstream out;
//    out.open("../resources/output.txt");
//    out<<

//          out.close();
}

void orchard::print(char key)
{
    //alphabetOrchard[getHeapPosition(key)].printAll();
}

void orchard::copy(const orchard &other)
{
    for(unsigned int i=0; i<ALPHABET_SIZE; ++i)
        alphabetOrchard[i]=other.alphabetOrchard[i];

    tokens=other.tokens;
}

