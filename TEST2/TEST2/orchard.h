#ifndef ORCHARD_H
#define ORCHARD_H
#include "vectorHeap.h"
#include <vector>
#include "word.h"
//#include "tokenizer.h"

const unsigned int ALPHABET_SIZE = 26;

using std::vector;

class orchard
{
public:

    //Constructors
    orchard();
    orchard(const orchard &other);

    //Destructor
    ~orchard();

    //Accessors


    //Mutators


    //Operators
    orchard& operator =(const orchard &other);

    friend
    std::ostream& operator<<(ostream &out, const orchard &q);


    //Functions
    long int alphaFrequency(char key);//the number of words which begin with each letter of the alphabet. Got to tree 'D' and display the count
    vectorHeap<word>& getHeap(char key); //gets certain heap


    // A summary page that gives the word count, paragraph count, reading level, the 10 most frequently used words, the number of words which begin with each letter of the alphabet, and the total time to process the document.
    //The above is to be followed by each word, in alphabetical order, with the first letter capitalized, with its frequency of occurrence, the lines and paragraphs in which it occurred
    void displayOrchard();

private:

    //Private Member Variables
    vectorHeap<word> alphabetOrchard[ALPHABET_SIZE];
    tokenizer tokens;

    //Private Functions
    unsigned int getHeapPosition(char key); //returns the position number in the alphabetOrchard array a associated to the letter
    void insert(); //takes words from tokenizer and sorts and adds them to the orchard
    void saveToFile(); //saves output to a file
    void print(char key);






};

#endif // ORCHARD_H
