#include <iostream>
#include <string>
#include <fstream>
#include <sstream>



using namespace std;

#define DEBUG
struct xmlInfo
{
    string opening;
    string closing;
};


void loadXML(xmlInfo xml[]);
void removeCharacter(string &line, char item = ',', bool removeReplace = true);
void readLineIntoArray(const string &line,string airlineInfo[]);
void writeAirlineXML(ostream &out, xmlInfo xml[], string airlineInfo[]);

int main()
{
    string line, airlineInfo[9];
    xmlInfo xml[9];

    ofstream out("routes.xml");
    ifstream in("routes.dat");
    loadXML(xml);
    out<<"<?xml version=\"1.0\" encoding=\"UTF-8\"?>"<<endl;
    while(getline(in, line))
    {
#ifdef DEBUG
        cout<<line<<endl;
#endif
        readLineIntoArray(line, airlineInfo);
        writeAirlineXML(out, xml, airlineInfo);
    }
    in.close();
    out.close();
    return 0;
}


void readLineIntoArray(const string &line,string airlineInfo[])
{
    stringstream ss;
    ss << line;
    for(int i = 0; i < 8; i++)
    {
        getline(ss, airlineInfo[i], ',');
        removeCharacter(airlineInfo[i],'\"');
    }
    getline(ss, airlineInfo[8]);
}

void removeCharacter(string &line, char item, bool removeReplace)
{
    unsigned int pos = 0;
    while((pos = line.find(item)) < line.size())
        if(removeReplace)
            line.erase(pos,1);
        else
            line[pos] = ' ';
}


void loadXML(xmlInfo xml[])
{
    xml[0].opening = "<Airline>";
    xml[0].closing = "</Airline>";
    xml[1].opening = "<Airline_ID>";
    xml[1].closing = "</Airline_ID>";
    xml[2].opening = "<Source Airport>";
    xml[2].closing = "</Source Airport>";
    xml[3].opening = "<Source Airport ID>";
    xml[3].closing = "</Source Airport ID>";
    xml[4].opening = "<Destination Airport>";
    xml[4].closing = "</Destination Airport>";
    xml[5].opening = "<Destination Airport ID>";
    xml[5].closing = "</Destination Airport ID>";
    xml[6].opening = "<Code Share>";
    xml[6].closing = "</Code Share>";
    xml[7].opening = "<Stops>";
    xml[7].closing = "</Stops>";
    xml[8].opening = "<Equipment>";
    xml[8].closing = "</Equipment>";
}


void writeAirlineXML(ostream &out, xmlInfo xml[], string airlineInfo[])
{
    out<<"<Routes>"<<endl;
    for(int i = 0; i < 9; ++i)
        out<<"   "<<xml[i].opening<<airlineInfo[i]<<xml[i].closing<<endl;
    out<<"</Routes>"<<endl;
}
