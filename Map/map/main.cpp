//hidden gotcha: hint: something outside the std library is used
#include <iostream>
#include "map.h"
using namespace std;
// map::begin/end
using std::cout;

int main ()
{

    //-------------------------map TEST------------------------------------

    try
    {
        map<char,int> mymap('e',500);

         mymap['b'] = 100;
//         mymap['a'] = 200;
         mymap['c'] = 300;
         mymap.insert('d',400);
         mymap.at('f') = 600;


         mymap.remove('d',999);

         std::cout<<"DEBUG count(): "<<mymap.count('a')<<std::endl;

         //mymap.clear();


         // show content:
         for (map<char,int>::iterator it=mymap.begin(); *it; ++it)
           cout << it->first << " => " << it->second << '\n';


         std::cout<<"DEBUG size(): "<<mymap.size()<<std::endl;

    }
    catch(MAP_ERRORS)
    {
        for (int i=0;i<50;i++)
        {
            std::cout<<"ERROR ERROR ERROR ERROR ERROR ERROR ERROR ERROR ERROR ERROR ERROR ERROR ERROR "<<std::endl;
        }

    }


    return 0;
}
//4 things you must always have in a class: Default constructor, Copy constructor, equal operator, destructor.
