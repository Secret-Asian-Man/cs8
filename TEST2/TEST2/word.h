#ifndef WORD_H
#define WORD_H
#include <string>
#include <vector>
#include "pair.h"


class word
{
public:

    //constructors
    //    word();
    word(const std::string &aWord, unsigned int myParagraphNumber, unsigned int myLinenumber,unsigned int myfrequencyCount=1, unsigned int mySyllableCount=1);
    word(const std::string &aWord, const pair<unsigned int, unsigned int>  &myParagraphAndLineNumbers,unsigned int myfrequencyCount=1, unsigned int mySyllableCount=1);
    word(const word &other);


    //destructors
    ~word();


    //accessors
    std::string getWord();
    unsigned int getFrequencyCount();
    unsigned int getSyllableCount();
    char getFirstLetter();

    std::string getWord()const;
    unsigned int getFrequencyCount()const;
    unsigned int getSyllableCount()const;
    char getFirstLetter()const;

    //mutators
    void setWord(const std::string &myWord);
    void setFrequencyCount(unsigned int myfrequencyCount);
    void setSyllableCount(unsigned int mySyllableCount);


    //functions
    void incrementFrequencyCount(unsigned int count=1);
    void incrementSyllableCount(unsigned int count=1);


    //operators
    word& operator =(const word &other);
    bool operator >(const word &other) const;//might have to make this a friend, refer to pair.h
    bool operator <(const word &other) const;//might have to make this a friend, refer to pair.h

private:

    //private functions
    void capitalizeFirstLetter();
    void pushToVector(unsigned int paragraphNumber, unsigned int lineNumber);
    void pushToVector(pair<unsigned int, unsigned int> myPair);


    //private variables
    unsigned int frequencyCount;
    unsigned int syllableCount;
    std::string theWord;

    std::vector< pair<unsigned int, unsigned int> > paragraphAndLine;




};

#endif // WORD_H
