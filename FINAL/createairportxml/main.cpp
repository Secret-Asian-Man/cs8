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
void readLineIntoArray(const string &line,string airportInfo[]);
void writeAirportXML(ostream &out, xmlInfo xml[], string airportInfo[]);

int main()
{
    string line, airportInfo[12];
    xmlInfo xml[12];
    /*
          0 airportID,
          1 name,
          2 city,
          3 country,
          4 iata,
          5 icao,
          6 lat,
          7 longitude,
          8 alt,
          9 timezone,
          10 dst,
          11 tz;
    */
    ofstream out("airports.xml");
    ifstream in("airports.dat");
    loadXML(xml);
    out<<"<?xml version=\"1.0\" encoding=\"UTF-8\"?>"<<endl;
    while(getline(in, line))
    {
#ifdef DEBUG
        cout<<line<<endl;
#endif
        readLineIntoArray(line, airportInfo);
        writeAirportXML(out, xml, airportInfo);
    }
    in.close();
    out.close();
    return 0;
}


void readLineIntoArray(const string &line,string airportInfo[])
{
    stringstream ss;
    ss << line;
    for(int i = 0; i < 12; i++)
    {
        getline(ss, airportInfo[i], ',');
        removeCharacter(airportInfo[i],'\"');
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
    xml[0].opening = "<id>";
    xml[0].closing = "</id>";
    xml[1].opening = "<name>";
    xml[1].closing = "</name>";
    xml[2].opening = "<city>";
    xml[2].closing = "</city>";
    xml[3].opening = "<country>";
    xml[3].closing = "</country>";
    xml[4].opening = "<iata>";
    xml[4].closing = "</iata>";
    xml[5].opening = "<icao>";
    xml[5].closing = "</icao>";
    xml[6].opening = "<latitude>";
    xml[6].closing = "</latitude>";
    xml[7].opening = "<longitude>";
    xml[7].closing = "</longitude>";
    xml[8].opening = "<altitude>";
    xml[8].closing = "</altitude>";
    xml[9].opening = "<timezone>";
    xml[9].closing = "</timezone>";
    xml[10].opening = "<dst>";
    xml[10].closing = "</dst>";
    xml[11].opening = "<tz>";
    xml[11].closing = "</tz>";
}


void writeAirportXML(ostream &out, xmlInfo xml[], string airportInfo[])
{
    out<<"<airport>"<<endl;
    for(int i = 0; i < 12; ++i)
        out<<"   "<<xml[i].opening<<airportInfo[i]<<xml[i].closing<<endl;
    out<<"</airport>"<<endl;
}
