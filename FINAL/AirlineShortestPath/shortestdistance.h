#ifndef SHORTESTDISTANCE_H
#define SHORTESTDISTANCE_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <map>
#include <cmath>
#include <algorithm>
#include <queue>

using std::ostream;
using std::ofstream;
using std::ifstream;
using std::string;
using std::cout;
using std::endl;
using std::getline;
using std::vector;
using std::map;
using std::stoi;
using std::stod;
using std::pair;
using std::multimap;
using std::priority_queue;

#define AIRPORT_LINE_SIZE 8
#define ROUTES_LINE_SIZE 6
#define AIRLINES_LINE_SIZE 6
#define RADIUS_OF_EARTH 3959

enum{
    AIRPORT_ID,
    AIRPORT_NAME,
    AIRPORT_CITY,
    COUNTRY,
    IATA,
    ICAO,
    LATITUDE,
    LONGITUDE
};
enum{
    AIRLINE_CODE,
    AIRLINE_ID,
    SOURCE_AIRPORT_CODE,
    SOURCE_AIRPORT_ID,
    DESTINATION_AIRPORT_CODE,
    DESTINATION_AIRPORT_ID
};
enum {
    AIRLINES_ID,
    AIRLINE_NAME,
    AIRLINE_IATA,
    AIRLINE_ICAO,
    AIRLINE_COUNTRY,
    ACTIVE,
};


struct Edge
{
    Edge(string d1, string d2, string d4, long double d, string d5, string d6, string d7, int d8):
        destination_airport_code(d1),
        airline_iata(d2),
        airline_id(d4),
        destination_airport_name(d5),
        destination_airport_country(d6),
        destination_airport_city(d7),
        distance(d),
        destination_airport_id(d8)
    {}
    string destination_airport_code, airline_iata, airline_id, destination_airport_name, destination_airport_country, destination_airport_city;
    long double distance;
    int destination_airport_id;
};

struct sort_pred
{
    bool operator()(Edge* x, Edge* y)
    {
        return x->distance < y->distance;
    }
};

struct Data
{
    Data(){}
    int airport_id;
    string iata, icao, longitude, latitude, city, country, airport_name;
    vector<Edge*> vec;
};

struct Routes
{
    Routes(string carrier, int next, double d):nextAirport(next), distance(d)
    {
        carriers.push_back(carrier);
    }
    void pushNewCarrier(string carrier)
    {
        carriers.push_back(carrier);
    }
    vector<string> carriers;
    int nextAirport;
    double distance;
};

struct Vertex
{
    Vertex(): cost(INT_MAX)
    {
    }
    void pushNewRoute(Routes* route)
    {
        routes.push_back(route);
    }
    friend ostream& operator<<(ostream& out, const Vertex& other)
    {
        out << "Cost: " << other.cost;
        for(vector<Routes*>::const_iterator it = other.routes.begin(); it != other.routes.end(); ++it)
        {
            out << " Distance: " << (*it)->distance << " nextAirport: " << (*it)->nextAirport << " Airlines: ";
            for(vector<string>::iterator mt = (*it)->carriers.begin(); mt != (*it)->carriers.end(); ++mt)
            {
                out << *mt << " ";
            }
        }
        out << endl;
        return out;
    }

    vector<Routes*> routes;
    int cost;
};

class Prioritize
{
public:
    bool operator()(Vertex*p1 ,Vertex* p2)
    {
        return p1->cost < p2->cost;
    }
};



class ShortestDistance
{
    public:
        ShortestDistance(char* filenam);
        vector<Vertex *> shortestDistance(string airport1, string airport2);


    private:
        map<int,Data*> dataMap;
        map<int,string> carrierNames;
        map<int,Vertex*> table;

        ifstream airports;
        ifstream routes;
        ifstream airlines;
        ofstream out;
        string line;
        char* filename;

        string extract(string line);
        void search(ifstream& routes, ofstream& out, string ID);
        void parseAirports(map<int,Data*> &dataMap);
        void parseRoutes(map<int,Data*> &dataMap);
        void parseAirline(map<int,string> &carrierNames);
        void writeXML(map<int,Data*> &dataMap, map<int,string> &carrierNames);
        void createTable();
};

#endif // SHORTESTDISTANCE_H
