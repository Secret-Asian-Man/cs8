#include "shortestdistance.h"



ShortestDistance::ShortestDistance(char *filenam):filename(filenam)
{
    airports.open("airports.xml");
    routes.open("routes.xml");
    airlines.open("airlines.xml");
    parseAirports(dataMap);
    parseRoutes(dataMap);
    parseAirline(carrierNames);
    ifstream in(filenam);
    getline(in,line);
    if(line.compare("<?xml version=\"1.0\" encoding=\"UTF-8\"?>") != 0)
    {
        in.close();
        std::clock_t start= std::clock();
        out.open(filenam);
        writeXML(dataMap, carrierNames);
        cout << "Parsing: " << (std::clock() - start)/(double)CLOCKS_PER_SEC << " seconds." << endl;
    }
    in.close();
    createTable();
}



void ShortestDistance::parseAirports(map<int,Data*> &dataMap)
{
    string airport_data[AIRPORT_LINE_SIZE];

    getline(airports, line);
    while(getline(airports, line))
    {
        for(int j = 0; j < AIRPORT_LINE_SIZE; ++j)
        {
            getline(airports, line);
            airport_data[j] = extract(line);
        }
        int airportID = stoi(airport_data[AIRPORT_ID]);
        dataMap[airportID] = new Data();
        dataMap[airportID]->airport_id = airportID;
        dataMap[airportID]->iata = airport_data[IATA];
        dataMap[airportID]->icao = airport_data[ICAO];
        dataMap[airportID]->city = airport_data[AIRPORT_CITY];
        dataMap[airportID]->longitude = airport_data[LONGITUDE];
        dataMap[airportID]->latitude = airport_data[LATITUDE];
        dataMap[airportID]->country = airport_data[COUNTRY];
        dataMap[airportID]->airport_name = airport_data[AIRPORT_NAME];

        while(line.compare("</airport>"))
        {
            getline(airports, line);
        }
    }
    airports.close();
}



void ShortestDistance::parseRoutes(map<int,Data*> &dataMap)
{
    string routes_data[ROUTES_LINE_SIZE];

    getline(routes, line);
    while(getline(routes, line))
    {
        for(int j = 0; j < ROUTES_LINE_SIZE; ++j)
        {
            getline(routes, line);
            routes_data[j] = extract(line);
        }
        if(routes_data[SOURCE_AIRPORT_ID].compare("0") && routes_data[DESTINATION_AIRPORT_ID].compare("0") && routes_data[DESTINATION_AIRPORT_ID].compare("\\N") && routes_data[SOURCE_AIRPORT_ID].compare("\\N") && routes_data[AIRLINE_ID].compare("\\N"))
        {
            int airportID = stoi(routes_data[SOURCE_AIRPORT_ID]);
            long double sourceLat = stod(dataMap[airportID]->latitude);
            long double sourceLong = stod(dataMap[airportID]->longitude);
            int destAirportID = stoi(routes_data[DESTINATION_AIRPORT_ID]);
            long double destinationLat = stod(dataMap[destAirportID]->latitude);
            long double destinationLong = stod(dataMap[destAirportID]->longitude);
            long double deltaFI = fabs(sourceLat - destinationLat);
            long double deltaLambda = fabs(sourceLong - destinationLong);
            long double deltaWhatever = 2 * asin(sqrt(pow(sin(deltaFI/2),2) + cos(sourceLat) * cos(destinationLat) * pow(sin(deltaLambda/2),2)));
            long double distance = RADIUS_OF_EARTH * deltaWhatever;
            dataMap[airportID]->vec.push_back(new Edge (routes_data[DESTINATION_AIRPORT_CODE], routes_data[AIRLINE_CODE], routes_data[AIRLINE_ID], distance, dataMap[destAirportID]->airport_name, dataMap[destAirportID]->country, dataMap[destAirportID]->city, destAirportID));
        }
        while(line.compare("</Routes>"))
        {
            getline(routes, line);
        }
    }
    routes.close();
}



void ShortestDistance::parseAirline(map<int,string> &carrierNames)
{
    string airline_data[AIRLINES_LINE_SIZE];

    getline(airlines, line);
    while(getline(airlines, line))
    {
        int j = 0;
        for(; j < 2; ++j)
        {
            getline(airlines, line);
            airline_data[j] = extract(line);
        }
        getline(airlines, line);
        for(; j < 5; ++j)
        {
            getline(airlines, line);
            airline_data[j] = extract(line);
        }
        getline(airlines, line);
        for(; j < 6; ++j)
        {
            getline(airlines, line);
            airline_data[j] = extract(line);
        }
        carrierNames[stoi(airline_data[AIRLINES_ID])] = airline_data[AIRLINE_NAME];
        while(line.compare("</Airlines>"))
        {
            getline(airlines, line);
        }
    }
    airlines.close();
}



void ShortestDistance::writeXML(map<int,Data*> &dataMap, map<int, std::string> &carrierNames)
{
    out << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl;

    map<int,Data*>::iterator mt = dataMap.begin();
    for(; mt != dataMap.end(); ++mt)
    {
        if(!mt->second->vec.empty())
        {
            out << "<vertex>" << endl;
            out << "\t<id>" << mt->second->airport_id << "</id>" << endl;
            out << "\t<name>" << mt->second->airport_name << "</name>" << endl;
            out << "\t<airport>" << mt->second->iata << "</airport>" << endl;
            out << "\t<city>" << mt->second->city << "</city>" << endl;
            out << "\t<country>" << mt->second->country << "</country>" << endl;
            out << "\t<latitude>" << mt->second->latitude << "</latitude>" << endl;
            out << "\t<longitude>" << mt->second->longitude << "</longitude>" << endl;
            out << "\t<edges>" << endl;
            sort(mt->second->vec.begin(),mt->second->vec.end(), sort_pred());
            vector<Edge*>::const_iterator it = mt->second->vec.begin();
            for(; it != mt->second->vec.end(); ++it)
            {
                out << "\t\t<edge>" << endl;
                out << "\t\t\t<id>" << (*it)->destination_airport_id << "</id>" << endl;
                out << "\t\t\t<name>" << (*it)->destination_airport_name << "</name>" << endl;
                out << "\t\t\t<airport>" << (*it)->destination_airport_code << "</airport>" << endl;
                out << "\t\t\t<city>" << (*it)->destination_airport_city << "</city>" << endl;
                out << "\t\t\t<country>" << (*it)->destination_airport_country << "</country>" << endl;
                out << "\t\t\t<carrier>" << (*it)->airline_iata << "</carrier>" << endl;
                out << "\t\t\t<carrierName>" << carrierNames[stoi((*it)->airline_id)] << "</carrierName>" << endl;
                out << "\t\t\t<distance>" << (*it)->distance << "</distance>" << endl;
                out << "\t\t\t<id>" << (*it)->airline_id << "</id>" << endl;
                out << "\t\t</edge>" << endl;
            }
            out << "\t</edges>" << endl;
            out << "</vertex>" << endl;
        }
    }
    out.close();
}



string ShortestDistance::extract(std::string line)
{
    // asdawd<blah>
    //.......^          firstOf
    //............^     lastOf
    //firstPos=6
    //lastPos=11

    //(firstPos+1)=7, (lastPos-1)=(11-1)=10
    //create a subtring from 7-10, which is "blah"


    //WARNING: Did you mean
    //    int firstPos = line.find_first_of('<');
    //    int lastPos = line.find_first_of('>' , firstPos+1);
    //    return line.substr(firstPos+1, lastPos-1);


    int firstPos = line.find_first_of('>');
    int lastPos = line.find_first_of('<' , firstPos+1);
    return line.substr(firstPos+1, lastPos-firstPos-1);
}



void ShortestDistance::createTable()
{
    ifstream in(filename); //"FinalData.xml"
    getline(in,line); //skips <?xml version="1.0" encoding="UTF-8"?>
    string airport_data[7]; //initializes a string array of size 7 //for holding everything between <vertex> and <edges>
    string edge_data[9];//initializes a string array of size 7 //for holding everything between <edge> and </edge>
    while(getline(in,line)) //gets <vertex>
    {
        //for loop gets these
        //0        <id>1</id>
        //1        <name>Goroka</name>
        //2        <airport>GKA</airport>
        //3        <city>Goroka</city>
        //4        <country>Papua New Guinea</country>
        //5        <latitude>-6.081689</latitude>
        //6        <longitude>145.391881</longitude>
        //and stores them into airport_data[]
        for(int i = 0; i < 7; ++i)
        {
            getline(in,line);
            airport_data[i] = extract(line);
        }




        int airport_id = stoi(airport_data[0]); //converts <id>1</id>, into an int and stores it

        getline(in,line); //removes <edges>

        table[airport_id] = new Vertex(); //map<int,Vertex*> table

        while(getline(in,line)/* gets 		<edge> */&& (line.compare("\t</edges>") != 0 || line.compare("\t\t<edge>") == 0))
        {
            //for loop gets everything inside the <edge></edge> tag
            //0            <id>2</id>
            //1			<name>Madang</name>
            //2			<airport>MAG</airport>
            //3			<city>Madang</city>
            //4			<country>Papua New Guinea</country>
            //5			<carrier>CG</carrier>
            //6			<carrierName>Airlines PNG</carrierName>
            //7			<distance>3645.59</distance>
            //8			<id>1308</id>
            //and stores it inside edge_data[]
            for(int i = 0; i < 9; ++i)
            {
                getline(in,line);
                edge_data[i] = extract(line);
            }

            getline(in,line); //removes 		</edge>

            std::cout<<"DEBUG OMGOMGOMGOMG: "<<stoi(edge_data[0])<<std::endl;
            //WARNING: doesn't push in the next set of data because, of table[airport_id]->routes.empty() isn't empty after the first call. so nextAirport is uninitialized when called;
            if(table[airport_id]->routes.empty())//<<<<------- PROBLEM?
            {

                table[airport_id]->pushNewRoute(new Routes(edge_data[5]/*		<carrier>CG</carrier>*/

                                                , stoi(edge_data[0])/* 			<id>2</id>*/

                        , stod(edge_data[7])));/*		<distance>3645.59</distance>*/
            }

            std::cout<<"DEBUG airport_data: "<<std::endl;
            for (unsigned int i=0;i<7;++i)
            {
                cout<<i<<":"<<airport_data[i]<<" ";
            }
            std::cout<<std::endl;std::cout<<std::endl;std::cout<<std::endl;std::cout<<std::endl;

            std::cout<<"DEBUG edge_data: "<<std::endl;

            for (unsigned int i=0;i<9;++i)
            {
                cout<<i<<":"<<edge_data[i]<<" ";
            }
            std::cout<<std::endl;std::cout<<std::endl;std::cout<<std::endl;

            std::cout<<"DEBUG STARTSTARTSTARTSTARTSTARTSTARTSTARTSTARTSTART "<<std::endl;

            vector<Routes*>::iterator it = table[airport_id]->routes.begin();
            for(; it != table[airport_id]->routes.end(); ++it)
            {
                if((*it)->nextAirport == stoi(edge_data[0]))//WARNING: need to make condition more specific. What if the Vertex or something doesn't exist //if one of the current vector's routes' nextAirport ID matches the ID of the edge
                {
                    //WARNING: might need to increment to the next airport before processing
                    cout << (*it)->nextAirport<< " " << edge_data[0] << endl;
                    (*it)->pushNewCarrier(edge_data[5]); //pushes 		<carrier>CG</carrier>

                }
                else
                {
                    std::cout<<"DEBUG 1111111111111111111111111111 "<<std::endl;
                    std::cout<<"DEBUG edge_data[5]: "<<edge_data[5]<<std::endl;
                    std::cout<<"DEBUG (*it)->nextAirport: "<<(*it)->nextAirport<<std::endl;
                    std::cout<<"DEBUG stod(edge_data[7]): "<<stod(edge_data[7])<<std::endl;
                    table[airport_id]->pushNewRoute(new Routes(edge_data[5], (*it)->nextAirport, stod(edge_data[7]))); //WARNING: This line makes everything crash. Something wrong with (*it)->nextAirport
                    std::cout<<"DEBUG 2222222222222222222222222222 "<<std::endl;

                    // (*it)->nextAirport values keep changing. This means the program is trying to read an uninitialized value
                    //32184268
                    //5891564
                    //5378284
                    //32535708

                    //Struct route is when a value is passed in to initialize nextAirport, so find who gives the struct that value
                    //it its creating a new route in the crashing line, but the new route is being given a unintialized value. Need to find out who is creating that uninitialized value.
                    //(*it) comes from a Vertex inside one of the slots in the table. Vertex->routes[x]->nextAirport
                    //  something is wrong with initilizing the Vertex's route's nextAirport
                    // where are routes being initialized?
                    //pushNewRoute is so simple, so it should work, the problem is how and when we call it.
                    //when initializing the table with Vertex; the Vertex is only being initialzed with 1 route because pushNewRoute is only called once
                }
            }
            std::cout<<"DEBUG ENDENDENDENDENDENDENDENDENDENDENDENDEND "<<std::endl;
        }
        getline(in, line); //removes </edge>
    }
    //    system("pause");
    //    map<int,Vertex*>::iterator it = table.begin();
    //    for(; it != table.end(); ++it)
    //        cout << *(*it).second << endl;
    // cout << *table[3848] << endl;
}



vector<Vertex*> ShortestDistance::shortestDistance(string airport1, string airport2)
{
    int starting_airport = -1, destination_airport = -1;
    map<int,Data*>::iterator mt = dataMap.begin();
    for(; mt != dataMap.end(); ++mt)
    {
        if(!mt->second->iata.empty())
        {
            if(mt->second->iata.compare(airport1) == 0)
                starting_airport = mt->second->airport_id;
            else if(mt->second->iata.compare(airport2) == 0)
                destination_airport = mt->second->airport_id;
        }
        else
        {
            if(mt->second->icao.compare(airport1) == 0)
                starting_airport = mt->second->airport_id;
            else if(mt->second->icao.compare(airport2) == 0)
                destination_airport = mt->second->airport_id;
        }
    }
    if(destination_airport == -1)
    {
        cout << "Starting airport not found." << endl;
        exit(0);
    }
    else if(starting_airport == -1)
    {
        cout << "Destination airport not found." << endl;
        exit(0);
    }
    //    map<int,Vertex*> table;

    vector<Vertex*> path;

    priority_queue<Vertex*, vector<Vertex*>, Prioritize> Q;

    int where = starting_airport;

    table[where]->cost = 0;

    Q.push(table[where]);
    while(!Q.empty())
    {
        vector<Vertex*> neighbors;
        Vertex* u = Q.top();
        Q.pop();
        vector<Routes*>::iterator it = u->routes.begin();
        for(; it != u->routes.end(); ++it)
        {
            neighbors.push_back(table[(*it)->nextAirport]);
            where = (*it)->nextAirport;
            if(destination_airport == where)
                return path;
        }
        vector<Vertex*>::iterator ourNeighbors = neighbors.begin();
        for(; ourNeighbors != neighbors.end(); ++ourNeighbors)
        {
            double alt = u->cost + (*(*ourNeighbors)->routes.begin())->distance;
            if(alt < (*ourNeighbors)->cost)
            {
                (*ourNeighbors)->cost = alt;
                path.push_back(u);
                Q.push(*ourNeighbors);
            }
        }
    }
    return path;
}


















