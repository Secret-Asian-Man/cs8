#ifndef MYTOKENIZER_H
#define MYTOKENIZER_H
#include <string>
#include "word.h"
#include <fstream>

using std::string;
using std::ifstream;

class myTokenizer
{
public:
    //Constructors
    myTokenizer();
    myTokenizer(const std::string &fileName="");
    myTokenizer(const myTokenizer &other);


    //Destructor
    ~myTokenizer();

    //Accessors
    unsigned int getLineCount();
    unsigned int getParagraphCount();
    unsigned int getTotalWordCount();

    //Mutators
    void setParagraphCount(unsigned int number);
    void setTotalWordCount(unsigned int number);
    void setLineCount(unsigned int number);

    //Operators
    myTokenizer& operator=(const myTokenizer &other);

    //Functions
    word getNextWord(); //Makes a word class and sends it out. Will detect that block is now empty and gets a new block
    void loadNewFile(std::string fileName);
    void incrementLineCount(unsigned int number=1);
    void incrementParagraphCount(unsigned int number=1);
    void incrementTotalWordCount(unsigned int number=1);

private:

    //Private Member Variables
    string block;

    ifstream file; //using g_count to keep track of where we are in file.

    unsigned int lineCount;
    unsigned int paragraphCount;
    unsigned int totalWordCount;

    //Private Functions
    bool firstOf();
    bool firstNotOf();
    bool isBlockDone();
    void getNextBlock(); //gets the next block from the file and returns






};

#endif // MYTOKENIZER_H