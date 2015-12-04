#include "orchard.h"
#include <fstream>

orchard::orchard(std::string fileName)
{
    sentenceCount=lineCount=paragraphCount=totalWordCount=blockPosition=0;
    block="";

    file.open(fileName.c_str());
    if (file.fail())
        throw fileNotFound;

    plantOrchard();
}

orchard::orchard(const orchard &other)
{
    copy(other);
}

orchard::~orchard()
{
    sentenceCount=lineCount=paragraphCount=totalWordCount=blockPosition=0;
    block="";

    file.close();

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
vectorHeap<word*>& orchard::getHeap(char key)
{
    return alphabetOrchard[getHeapPosition(key)];
}

void orchard::displayOrchard()
{
    //save to file then display the file on console

    out.open("../resources/output.txt");

    for (unsigned int i=0;i<ALPHABET_SIZE;++i)
    {
        alphabetOrchard[i].saveAll(out);
    }
    out.close();


    std::ifstream console;
    string outputString;
    console.open("../resources/output.txt");
    if (console.fail())
    throw fileNotFound;
    while(!console.eof())
    {
        std::getline(console,outputString);
        std::cout<<outputString<<std::endl;

    }


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
void orchard::plantOrchard()
{

    //gets one line at a time from the file,converts it to a word class, and pushes it to the heap

    while(!file.eof())
    {
        std::getline(file,block,'\n'); //gets one line

        word* temp=new word;

        while(getNextWord(temp)) //tokenizes the string and inserts it to the heap
        {

            if(!temp->getWord().empty())
            {
                alphabetOrchard[getHeapPosition(temp->getFirstLetter())].insert(temp);
            }


            temp=new word;
        }
        blockPosition=0;
        ++lineCount;
    }

}

bool orchard::firstOf(std::string set, char key)
{
    for (unsigned int i=0;i<set.size();++i)
        if (set[i]==key)
            return true;

    return false;
}

bool orchard::firstNotOf(std::string set, char key)
{
    bool temp=true;

    for (unsigned int i=0;i<set.size();++i) //has to compare to everything before making a decision
    {
        if (set[i]==key)
            temp= false;
    }

    return temp;
}

bool orchard::getNextWord(word *myWord)
{
    while(firstNotOf(SET,block[blockPosition]) && blockPosition < block.size()) //ignores unwanted characters
    {
        if (firstOf(PUNC,block[blockPosition]))
        {
            ++sentenceCount;
        }

        ++blockPosition;
    }

    string temp="";

    while(firstOf(SET,block[blockPosition]) && blockPosition < block.size()) //gets word
    {
        temp+=block[blockPosition];
        ++blockPosition;
    }


    //removes weird words that don't start with a letter.
    int tempPos=temp.find_first_of(ALPHA);
    if (tempPos>=0)
        temp=temp.substr(tempPos);


    if (tempPos>=0)//if the string isn't empty
    {
        myWord->setWord(temp);
        myWord->incrementFrequencyCount();
        myWord->pushToVector(paragraphCount,lineCount);
        ++totalWordCount;
        return true;
    }

    return false; //returns false if it runs out of words. Shouldve returned true at this point.
}

void orchard::printOneTree(unsigned int position)
{
    alphabetOrchard[position].printAll(); //need printall for lower levels
}

void orchard::copy(const orchard &other)
{

    block=other.block;
    blockPosition=other.blockPosition;
    lineCount=other.lineCount;
    paragraphCount=other.paragraphCount;
    totalWordCount=other.totalWordCount;
    sentenceCount=other.sentenceCount;

    for(unsigned int i=0; i<ALPHABET_SIZE; ++i)
        alphabetOrchard[i]=other.alphabetOrchard[i];

}


