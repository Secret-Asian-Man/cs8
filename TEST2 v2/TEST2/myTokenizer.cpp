#include "myTokenizer.h"


myTokenizer::myTokenizer()
{
    lineCount=paragraphCount=totalWordCount=blockPosition=0;
    block="";
}

myTokenizer::myTokenizer(const std::string &fileName)
{
    lineCount=paragraphCount=totalWordCount=blockPosition=0;
    block="";

    file.open(fileName.c_str());

    if (file.fail())
        throw fileNotFound;

    getNextBlock();

}

myTokenizer::myTokenizer(const myTokenizer &other)
{
    file.close();

    lineCount=other.lineCount;
    paragraphCount=other.paragraphCount;
    totalWordCount=other.totalWordCount;
    blockPosition=other.blockPosition;
    block=other.block;
}

myTokenizer::~myTokenizer()
{
    blockPosition=lineCount=paragraphCount=totalWordCount=0;
    block="";

    file.close();
}

unsigned int myTokenizer::getLineCount()
{
    return lineCount;
}

unsigned int myTokenizer::getParagraphCount()
{
    return paragraphCount;
}

unsigned int myTokenizer::getTotalWordCount()
{
    return totalWordCount;
}

unsigned int myTokenizer::getLineCount()const
{
    return lineCount;
}

unsigned int myTokenizer::getParagraphCount()const
{
    return paragraphCount;
}

unsigned int myTokenizer::getTotalWordCount()const
{
    return totalWordCount;
}

void myTokenizer::setParagraphCount(unsigned int number)
{
    paragraphCount=number;
}

void myTokenizer::setTotalWordCount(unsigned int number)
{
    totalWordCount=number;
}

void myTokenizer::setLineCount(unsigned int number)
{
    lineCount=number;

}

myTokenizer &myTokenizer::operator=(const myTokenizer &other)
{
    if (this != &other)
    {
        file.close();

        lineCount=other.lineCount;
        paragraphCount=other.paragraphCount;
        totalWordCount=other.totalWordCount;
        block=other.block;
    }

    return *this;
}

bool myTokenizer::getNextWord(word *myWord)
{
    if (isBlockDone()) //if the block is "empty"
        if(!getNextBlock()) //get the next block, and if you can't return false
            return false;

    unsigned int lastElement=block.size()-1;

    while(firstNotOf(SET,block[blockPosition]) && blockPosition<=lastElement) //gets skipped if block is "empty"
    {
        std::cout<<"DEBUG blockPosition: "<<blockPosition<<std::endl;
        std::cout<<"DEBUG block[blockPosition]: "<<block[blockPosition]<<std::endl;
        system ("pause");

        bool xnorGate=true; //if this ever becomes false it stays false
        bool isParagraph=false;

        while(block[blockPosition]=='\n' && blockPosition<=lastElement)
        {
            ++lineCount;
            ++blockPosition;

            if (!xnorGate) //gets ignored the first loop
                isParagraph=true; //gets set to true a bunch of times, but will only count as 1 paragraph later.

            xnorGate=false; //xnorGate will now always stay false
        }

        if (isParagraph)//gets reset every loop
            ++paragraphCount; //at this point blockPosition is on something that isn't an end line
        else
            ++blockPosition; //works when no end lines are detected, proceeds as normal.

    }

    string temp=""; //the guy who calls this function will check if the string is empty, and ignore the word class if it is.

    while(firstOf(SET,block[blockPosition])&& blockPosition<=lastElement)//gets skipped if block is "empty"
    {
        temp+=block[blockPosition];
        ++blockPosition;
    }

    if (!temp.empty())
    {
        myWord->setWord(temp);
        myWord->incrementFrequencyCount();
        myWord->pushToVector(paragraphCount,lineCount);
        ++totalWordCount;
    }


    return true;
}


void myTokenizer::loadNewFile(std::string fileName)
{
    file.open(fileName.c_str());

    if (file.fail())
        throw fileNotFound;

    getNextBlock();

}

void myTokenizer::incrementLineCount(unsigned int number)
{
    lineCount+=number;
}

void myTokenizer::incrementParagraphCount(unsigned int number)
{
    paragraphCount+=number;

}

void myTokenizer::incrementTotalWordCount(unsigned int number)
{
    totalWordCount+=number;
}

bool myTokenizer::firstOf(string set, char key)
{
    for (unsigned int i=0;i<set.size();++i)
        if (set[i]==key)
            return true;

    return false;
}

bool myTokenizer::firstNotOf(std::string set, char key)
{
    for (unsigned int i=0;i<set.size();++i)
        if (set[i]!=key)
            return true;

    return false;
}

bool myTokenizer::isBlockDone()
{
  // return
}

bool myTokenizer::getNextBlock()
{

    std::getline(file,block);




















//    blockPosition=0; //getting new block so reset my progress in my old block
//    std::cout<<"DEBUG ################## "<<std::endl;

//    char tempCString[MAX];
//    std::cout<<"DEBUG #####################@@@ "<<std::endl;

//    file.read(tempCString, MAX); //.read reads a custom amount from the file, but only takes c-strings

//    if (file.fail())
//        return false;

//    block.assign(tempCString);//converts cstring back to a normal string

//    return true;
}
















