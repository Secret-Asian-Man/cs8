#ifndef WORD_H
#define WORD_H
#include <string>
#include <vector>
#include "pair.h"


class word
{
public:

    //constructors
    word();
    word(const std::string &aWord, unsigned int myParagraphNumber, unsigned int myLinenumber,unsigned int myfrequencyCount=1);
    word(const std::string &aWord, const pair<unsigned int, unsigned int>  &myParagraphAndLineNumbers,unsigned int myfrequencyCount=1);
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
    std::vector<pair<unsigned int, unsigned int>> getParagraphAndLine();

    //mutators
    void setWord(const std::string &myWord);
    void setFrequencyCount(unsigned int myfrequencyCount);
    void setSyllableCount(unsigned int mySyllableCount);
    void pushToVector(unsigned int paragraphNumber, unsigned int lineNumber);
    void pushToVector(pair<unsigned int, unsigned int> myPair);


    //functions
    void incrementFrequencyCount(unsigned int count=1);
    void clear();
    void print();
    void save(std::ostream& out);

    //operators
    word& operator =(const word &other);
    bool operator >(const word &other) const;
    bool operator <(const word &other) const;

    friend
    std::ofstream& operator <<(std::ofstream &out, const word &other);

private:

    //private functions
    void capitalizeFirstLetter();
    unsigned int countSyllables(std::string myWord);
    void incrementSyllableCount(unsigned int count=1);

    //private variables
    unsigned int frequencyCount;
    unsigned int syllableCount;
    std::string theWord;

    std::vector< pair<unsigned int, unsigned int> > paragraphAndLine;




};

#endif // WORD_H
