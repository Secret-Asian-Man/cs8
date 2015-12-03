#include "word.h"
#include <iostream>

word::word()
{

    theWord="";
    frequencyCount= syllableCount=0;

}

word::word(const std::string &aWord, unsigned int myParagraphNumber, unsigned int myLinenumber, unsigned int myfrequencyCount, unsigned int mySyllableCount)
{
    theWord=aWord;
    pushToVector(myParagraphNumber,myLinenumber);
    syllableCount=mySyllableCount;
    frequencyCount=myfrequencyCount;
}

word::word(const std::string &aWord, const pair<unsigned int, unsigned int> &myParagraphAndLineNumbers, unsigned int myfrequencyCount, unsigned int mySyllableCount)
{
    theWord=aWord;
    pushToVector(myParagraphAndLineNumbers);
    syllableCount=mySyllableCount;
    frequencyCount=myfrequencyCount;
}

word::word(const word &other)
{
    paragraphAndLine.clear();

    theWord=other.theWord;
    paragraphAndLine=other.paragraphAndLine;
    syllableCount=other.syllableCount;
    frequencyCount=other.frequencyCount;
}

word::~word()
{
    frequencyCount=0;
    syllableCount=0;
    theWord="";
    paragraphAndLine.clear();
}

std::string word::getWord()
{
    return theWord;
}

unsigned int word::getFrequencyCount()
{
    return frequencyCount;
}

unsigned int word::getSyllableCount()
{
    return syllableCount;
}

char word::getFirstLetter()
{
    return theWord[0];
}

std::string word::getWord() const
{
    return theWord;
}

unsigned int word::getFrequencyCount() const
{
    return frequencyCount;
}

unsigned int word::getSyllableCount() const
{
    return syllableCount;
}

char word::getFirstLetter() const
{
    return theWord[0];
}

std::vector<pair<unsigned int, unsigned int> > word::getParagraphAndLine()
{
    return paragraphAndLine;
}

void word::setWord(const std::string &myWord)
{
    theWord=myWord;
}

void word::setFrequencyCount(unsigned int myfrequencyCount)
{
    frequencyCount=myfrequencyCount;
}

void word::setSyllableCount(unsigned int mySyllableCount)
{
    syllableCount=mySyllableCount;
}

void word::incrementFrequencyCount(unsigned int count)
{
    frequencyCount=frequencyCount+count;
}

void word::incrementSyllableCount(unsigned int count)
{
    syllableCount=syllableCount+count;
}

void word::clear()
{
    frequencyCount=syllableCount=0;
    theWord="";
    paragraphAndLine.clear();

}

word &word::operator=(const word &other)
{
    if(this != &other)
    {
        paragraphAndLine.clear();

        theWord=other.theWord;
        paragraphAndLine=other.paragraphAndLine;
        syllableCount=other.syllableCount;
        frequencyCount=other.frequencyCount;
    }
    return *this;
}

bool word::operator >(const word &other) const
{
    return theWord.compare(other.theWord) >= 0;
}

bool word::operator <(const word &other) const
{
    return theWord.compare(other.theWord) <= 0;
}

//std::ofstream &word::operator <<(std::ofstream &out, const word &other)
//{
////    std::vector< pair<unsigned int, unsigned int> > paragraphAndLine;

////    out<<"The word \""<<theWord<<"\" has "<<syllableCount<<"syllables, and appears "<<frequencyCount<<" times at: ";

////    for (unsigned int i=0;i<paragraphAndLine.size();++i)
////    {
////        out<<
////    }

////    return out;
//}

void word::capitalizeFirstLetter()
{
    theWord[0] = toupper(theWord[0]);
}

void word::pushToVector(unsigned int paragraphNumber, unsigned int lineNumber)
{
    pair<unsigned int, unsigned int> temp(paragraphNumber, lineNumber);
    pushToVector(temp);
}

void word::pushToVector(pair<unsigned int, unsigned int> myPair)
{
    paragraphAndLine.push_back(myPair);
}

