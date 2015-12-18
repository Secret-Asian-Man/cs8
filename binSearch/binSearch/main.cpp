#include <iostream>
#include <vector>

using namespace std;

int binSearch(vector<int> aVector, int key, int min, int max);

int main()
{

    vector<int> aVector;

    for (unsigned int i=0;i<100;++i)
    {
        aVector.push_back(i*2);
    }

    for (unsigned int i=0;i<aVector.size();++i)
    {
        cout<<aVector[i]<<" ";
    }

    std::cout<<endl<<"DEBUG 12 is found at position: "<<binSearch(aVector,12,0,100)<<std::endl;



    return 0;
}

int binSearch(vector<int> aVector, int key, int min, int max)
{
    while(min<=max)
    {

        int middle = min+((max-min)/2);

        if (aVector[middle]==key)
            return middle;
        else if(aVector[middle]<key)
            min=middle+1;
        else
            max=middle-1;
    }

    return -1; //return -1 if not found
}
