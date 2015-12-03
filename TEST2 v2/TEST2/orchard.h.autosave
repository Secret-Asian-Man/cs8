#ifndef ORCHARD_H
#define ORCHARD_H
#include "vectorHeap.h"
#include <vector>
#include "word.h"
#include <string>
#include <fstream>

const unsigned int ALPHABET_SIZE = 26;
const std::string SET="qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM\'-";
enum FILE_ERROR{fileNotFound};

using std::vector;

class orchard
{

public:

    //Constructors
    orchard(string fileName="");
    orchard(const orchard &other);

    //Destructor
    ~orchard();

    //Accessors


    //Mutators


    //Operators
    orchard& operator =(const orchard &other);

    friend
    std::ostream& operator<<(std::ostream &out, const orchard &q);


    //Functions
    long int alphaFrequency(char key);//the number of words which begin with each letter of the alphabet. Got to tree 'D' and display the count
    vectorHeap<word *> &getHeap(char key); //gets certain heap


    // A summary page that gives the word count, paragraph count, reading level, the 10 most frequently used words, the number of words which begin with each letter of the alphabet, and the total time to process the document.
    //The above is to be followed by each word, in alphabetical order, with the first letter capitalized, with its frequency of occurrence, the lines and paragraphs in which it occurred
    void displayOrchard();

private:
    //Private Member Variables
    vectorHeap<word*> alphabetOrchard[ALPHABET_SIZE];

    std::ifstream file;
    string block;
    unsigned int blockPosition;
    unsigned int lineCount;
    unsigned int paragraphCount;
    unsigned int totalWordCount;

    //Private Functions
    unsigned int getHeapPosition(char key); //returns the position number in the alphabetOrchard array a associated to the letter
    void saveToFile(); //saves output to a file
    void printOneTree(unsigned int position);
    void copy(const orchard &other);
    void plantOrchard(); //populates orchard upon startup by taking words from tokenizer and sorts and adds them to the orchard
    bool firstOf(string set, char key);
    bool firstNotOf(string set, char key);
    bool getNextWord(word *myWord); //Makes a word class and sends it out. Will detect that block is now empty and gets a new block






};

#endif // ORCHARD_H
