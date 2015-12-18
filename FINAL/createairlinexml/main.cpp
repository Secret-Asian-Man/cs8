#include <iostream>
#include <string>
#include <fstream>
#include <sstream>



using namespace std;

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
    string line, airlineInfo[8];
    xmlInfo xml[8];

    ofstream out("airlines.xml");
    ifstream in("airlines.dat");
    loadXML(xml);
    out<<"<?xml version=\"1.0\" encoding=\"UTF-8\"?>"<<endl;
    while(getline(in, line))
    {
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
    xml[0].opening = "<Airline_ID>";
    xml[0].closing = "</Airline_ID>";
    xml[1].opening = "<Name>";
    xml[1].closing = "</Name>";
    xml[2].opening = "<Alias>";
    xml[2].closing = "</Alias>";
    xml[3].opening = "<IATA>";
    xml[3].closing = "</IATA>";
    xml[4].opening = "<ICAO>";
    xml[4].closing = "</ICAO>";
    xml[5].opening = "<Callsign>";
    xml[5].closing = "</Callsign>";
    xml[6].opening = "<Country>";
    xml[6].closing = "</Country>";
    xml[7].opening = "<Active>";
    xml[7].closing = "</Active>";
}


void writeAirlineXML(ostream &out, xmlInfo xml[], string airlineInfo[])
{
    out<<"<Airlines>"<<endl;
    for(int i = 0; i < 8; ++i)
        out<<"   "<<xml[i].opening<<airlineInfo[i]<<xml[i].closing<<endl;
    out<<"</Airlines>"<<endl;
}
