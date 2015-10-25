#ifndef DRIVER_H
#define DRIVER_H

#include <cstdlib>
#include <iostream>
#include "doubleLinkedList.h"
#include <string>
#include <fstream>
#include <cstring>


using namespace std;

char menu(string title[]);

template<typename T>
void switchPrint(doubleLinkedList<T> &one);

template<typename T>
void perform(char ans, int &list, doubleLinkedList<T> &one, doubleLinkedList<T> &two);

template<typename T>
void loadfile(doubleLinkedList<T> &one,char *filename);

void help();

template<typename T>
void checkArgs(int argc, char *argv[], doubleLinkedList<T> &one, doubleLinkedList<T> &two, int &list);


char menu(string title[])
{
    char ans;
    for(int i=0; i<12; i++)
        cout<<title[i]<<endl;
    cin>>ans;
    cin.ignore(100, '\n');
    return ans;
}

template<typename T>
void switchPrint(doubleLinkedList<T> &one)
{
    if(one.printDirection() == ASCENDING)
    {
        cout<<"Print Direction was forward, now it is reverse"<<endl;
        one.printDirection() = DESCENDING;
    }
    else
    {
        cout<<"Print Direction was reverse, now it is forward"<<endl;
        one.printDirection()=ASCENDING;
    }
}

template<typename T>
void perform(char ans, int &list, doubleLinkedList<T> &one, doubleLinkedList<T> &two)
{
    int qty;
    T item;
    bool repeat;
    char filename[80];
    ifstream in;
    ofstream out;
    switch(toupper(ans))
    {
    case 'S' : cout<<"Which list do you wish to use (1 or 2)? ";
        cin>>list;
        if(list > 2 || list < 1) list = 1;
        break;
    case 'D' : if(list == 1)
            switchPrint(one);
        else
            switchPrint(two);
        break;

    case 'R' :do
        {
            repeat = false;
            cout<<"Please enter a file name: ";
            cin>>filename;
            try
            {
                if(list == 1)
                    loadfile(one,filename);
                else
                    loadfile(two,filename);
            }
            catch(int e)
            {
                cout<<"File not found. Please re-enter"<<endl;
                repeat = true;
            }
        }while(repeat);
        break;

    case 'W' : cout<<"Please enter a filename: ";
        cin>>filename;
        in.open(filename);
        if(in.fail())
        {
            in.close();
            out.open(filename);
        }
        else
        {
            in.close();
            cout<<"This file exists. Do you want to (O)verwrite or (A)ppend, or (E)xit: ";
            cin>>ans;
            switch(toupper(ans))
            {
            case 'O' : out.open(filename);
                break;
            case 'A' : out.open(filename,ios::app);
                break;
            default  : return;
            }
        }
        if(list == 1)
            out<<one;
        else
            out<<two;
        break;

    case 'P' : if(list == 1)
            cout<<"The contents of list one are: "<<endl<<one<<endl<<endl;
        else
            cout<<"The contents of list two are: "<<endl<<two<<endl<<endl;
        break;

    case '+' : cout<<"What is the item that you want to add? ";
        cin>>item;
        cout<<"Quantity of ["<<item<<"]: ";
        cin>>qty;
        if(list == 1) one.insert(item, qty);
        else two.insert(item, qty);
        break;

    case '-' : cout<<"What is the item that you want to delete? ";
        cin>>item;
        cout<<"Quantity of ["<<item<<"]: ";
        cin>>qty;
        if(list == 1) one.remove(item, qty);
        else two.remove(item, qty);
        break;

    case 'F' : cout<<"What is the item that you want to find? ";
        cin>>item;
        int count;
        if(list == 1)
            if((count=one.count(item))) cout<<item<<" is in list one "<<count<<" times "<<endl;
            else cout<<item<<" is not in list one"<<endl;
        else
            if((count=two.count(item))) cout<<item<<" is in list two "<<count<<" times "<<endl;
            else cout<<item<<" is not in list two"<<endl;
        break;

    case 'M' : cout<<"Attempting to Merge..."<<endl;
        one.merge(two);
        break;

    case 'Q' : cout<<"Good bye!!!"<<endl;

    }
    system("pause");
    system("cls");
}

template<typename T>
void loadfile(doubleLinkedList<T> &one,char *filename)
{
    ifstream in;
    in.open(filename);
    if(in.fail())
    {
        in.close();
        throw 404;
    }
    while(in>>one);
}

void help()
{
    cout<<"/h or /H -- This message"<<endl
       <<"/sn or /Sn -- switch to list n"<<endl
      <<"n=filename -- load list n with data from file named filename"<<endl;
    exit(0);
}

template<typename T>
void checkArgs(int argc, char *argv[],doubleLinkedList<T> &one,doubleLinkedList<T> &two, int &list)
{
    char *filename, *listNum; //makes 2 char pointers
    if(argc < 2) return; //no idea what argc is
    for(int i = 1; i < argc; i++)
    {
        if(argv[i][0] == '/')
            switch(toupper(argv[i][1]))
            {
            case 'H': help();
                break;
            case 'S' : char num[30];
                strcpy(num,argv[i]);
                list = atoi(num);
                break;
            }
        if(strpbrk (argv[i], "="))
        {
            char temp[80];
            strcpy(temp, argv[i]);
            listNum = strtok(temp,"=");
            filename = strtok(NULL,"=");
            if(atoi(listNum)==1)
                loadfile(one, filename);
            else
                loadfile(two, filename);
        }
    }
}




#endif // DRIVER_H
