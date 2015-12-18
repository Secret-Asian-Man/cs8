#include "shortestdistance.h"

using std::cin;

int main()
{
    ShortestDistance s("FinalData.xml");
    string airport1, airport2;
    cout << "What is your starting airport: ";
    cin >> airport1;
    cout << "What is your destination airport: ";
    cin >> airport2;
    vector<Vertex*> vec = s.shortestDistance(airport1,airport2);
    cout << vec.size() << endl;
    for(int i = 0; i < vec.size(); ++i)
        cout << *vec[i] << endl;
    return 0;
}
