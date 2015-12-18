//1. Correct the program written in class so that the binsort of integers works correctly for both ascending and descending sorts. No if statements or ternary operators are allowed.

//2, Modify the above to work for strings.

//3. Create a version that will work for doubles (ex: 3.14, 3.145, 3.145, etc)


#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <map>

using namespace std;

void initialize(vector<int> &list, int minVal, int maxVal, unsigned int qty);
int generateNumber(int minVal, int maxVal);
int getInput(string title, int min = -32768, int max = 32767);
void displayNumbers(char* title,vector<int> &list, int minVal, int maxVal);
void binsort(vector<int> &list, bool order);
bool getOrder();

int main()
{
    bool order=true;

    vector<int> list;
    int minVal = getInput("Minimum value desired"),
            maxVal = getInput("Maximum value desired", minVal),
            qty = getInput("Total number of random numbers", 0);


    srand(time(0));
    initialize(list, minVal, maxVal,qty);
    displayNumbers("Unsorted list",list,minVal, maxVal );
    binsort(list,getOrder());
    displayNumbers("Sorted list",list,minVal, maxVal );
    return 0;
}

int generateNumber(int minVal, int maxVal)
{
    int number;
    while( (number = minVal + rand()) > maxVal);
    return number;
}

int getInput(string title, int min, int max)
{
    bool repeat;
    int value;
    do
    {
        repeat = false;
        cout<<title<<": ";
        cin>>value;
        if(value < min || value > max)
        {
            cout<<"Input is out of range. Please re-enter."<<endl;
            repeat = true;
        }
    }while(repeat);

    return value;
}

void initialize(vector<int> &list, int minVal, int maxVal,unsigned int qty)
{
    for(unsigned int i = 0; i < qty; ++i)
        list.push_back(generateNumber(minVal, maxVal));
}

void displayNumbers(char* title,vector<int> &list, int minVal, int maxVal)
{
    int negSign = minVal < 0 || maxVal < 0,
            biggestAbs = abs(minVal) > abs(maxVal) ? abs(minVal) : abs(maxVal),
            digits = log10(1.*biggestAbs)+1,
            colWidth = digits+negSign+2,
            numCols = 60 / colWidth;
    unsigned int qty = list.size();
    cout<<title<<": "<<endl;
    for(unsigned int i = 0; i < qty; ++i)
    {
        if(i%numCols == 0)
            cout<<endl;
        cout<<setw(colWidth)<<list[i];
    }
    cout<<endl<<endl;
}

void binsort(vector<int> &list, bool order)
{
    map<int, vector<int> > bin;
    unsigned int currDigit = 1;
    while(bin[0].size() != list.size())
    {
        for(int i = -9; i < 10; ++i)
            bin[i].clear();
        for(unsigned int i = 0; i < list.size(); i++)
            if(order)
                bin[(list[i] >= 0 ? 1 : -1)*(((int)abs(1.*list[i]/currDigit))%10)].push_back(list[i]);
            else
                bin[(list[i] >= 0 ? -1 : 1)*(((int)abs(1.*list[i]/currDigit))%10)].push_back(list[i]);

        list.clear();
        for(int i = -9; i < 10; ++i)
            //      list.insert(list.cend(), bin[i]);
            for(unsigned int j = 0; j < bin[i].size(); ++j)
                list.push_back(bin[i][j]);
        currDigit *= 10;
    }
}
bool getOrder()
{
    char userOrderSelection;
    bool order;

    do
    {
        cout<<"Enter A for ascending or D for descending order: ";
        cin>>userOrderSelection;
        userOrderSelection=toupper(userOrderSelection);

    } while(userOrderSelection!='A' && userOrderSelection!='D');

    userOrderSelection=='A' ? order=true : order=false;

    return order;
}
