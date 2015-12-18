#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> source,vector<int>final,unsigned int leftSide, unsigned int rightSide, unsigned int end);


int main()
{
    vector<int> source;
    vector<int> final;

    unsigned int sizeOfSubArrays=1;



    for (unsigned int i=1;i<source.size();sizeOfSubArrays*=2)
    {
        for (unsigned int j=0;j<source.size();j=j+2*sizeOfSubArrays)
        {
            merge((source,final,j,min(j+sizeOfSubArrays,source.size()),min(j+2*sizeOfSubArrays, source.size())));
        }

        final=source;
    }

    return 0;
}

void merge(vector<int> source,vector<int>final,unsigned int leftSide, unsigned int rightSide, unsigned int end)
{



    for (unsigned int i=0;i<something;++i)
    {
        for (unsigned int j=0;j<something;++j)
        {

        }
    }
}

