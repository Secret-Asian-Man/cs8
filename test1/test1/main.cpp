#include <iostream>
//#include <cmath>
//#include <string>
#include <fstream>
#include <vector>


using namespace std;

//double Y(double x);
//double YPrime(double x);
//double newtonsMethod(double x);
//double pointSlope(double x1,double y1,double x2,double y2);
//double average(double x, double y);


//typedef double (*funcPtr)(int, int*);
//enum MY_ENUM {ONE,TWO,THREE};

//int greatestCommonFactor(int num1, int num2);
//void largest2Smallest(int &num1, int &num2);

//int smallestOf2numbers(int num1, int num2);
//int biggestOf2Numbers(int num1, int num2);

//template<typename T>
//void swap(T &x, T &y);


Dijkstra(map<>graph,int source)
{
   //set cost of initial edge is 0



    for (unsigned int i=0;i<graph.size();++i)
    {
        if (i!=source)
        {

            //set the cost at postion i to infinity (INT_MAX)
            //set cost of i-1 to undefined (use -1)
        }

        priorityQ.add(airport, infinity);

    }

    while(!priorityQ.empty())
    {
        double shortestDistance=priorityQ.remove();

       for (auto neighbor:airport)
       {
           int alt = shortestDistance+
       }
    }
}


enum ERRORS{fileFailedToOpen};

int main()
{







    //    //===================================================================
    //    //OUTPUT TO FILE

    //    try
    //    {
    //        ofstream out;

    //        out<<"test test"<<"\n\n\n\n\n"<<"@#@#$$$$$";


    ////        out.open("../resources/myOutput.txt");

    ////        if (!out.is_open())
    ////            throw fileFailedToOpen;

    ////        out<<"Thou bootless full-gorged strumpet. \n";
    ////        out<<"Thou vain pox-marked hedge-pig. \n";
    ////        out<<"Thou puny full-gorged joithead. \n";
    ////        out<<"thou delicate best-tempered wafer-cake. \n";
    ////        out<<"thou delicate tiger-booted cukoo-bud. \n";
    ////        out<<"thou fruitful tender-hearted true-penny. \n";
    ////        out<<"Thou bootless tickle-brained flax-wench. \n";

    ////        out.close();

    //    }
    //    catch(ERRORS error)
    //    {
    //        switch (error)
    //        {

    //        case fileFailedToOpen:
    //            std::cout<<"ERROR fileFailedToOpen "<<std::endl;
    //            break;

    //        default:
    //            std::cout<<"Unknown Error... "<<std::endl;
    //            break;
    //        }
    //    }
    //    //===================================================================


    //===================================================================
    //READ FILE
    //    try
    //    {
    //        string inputString;

    //        ifstream inputFile;
    //        inputFile.open("../resources/readMe.txt");

    //        if (!inputFile.is_open())
    //            throw fileFailedToOpen;

    //        while(!inputFile.eof())
    //        {
    //            char temp;
    //            inputFile.get(temp);
    //            inputString += temp;
    //        }
    //        inputFile.close();

    //        std::cout<<"DEBUG inputString: "<<inputString<<std::endl;

    //    }
    //    catch(ERRORS error)
    //    {
    //        switch (error)
    //        {

    //        case fileFailedToOpen:
    //            std::cout<<"ERROR File Failed To Open "<<std::endl;
    //            break;

    //        default:
    //            std::cout<<"Unknown Error... "<<std::endl;
    //            break;
    //        }
    //    }

    //===================================================================




    //funcPtr test[3];
    //test[ONE]=&dummy1;
    //test[TWO]=&dummy2;
    //test[THREE]=&dummy3;

    //int tempInt=3;
    //int* tempIntPtr=&tempInt;



    //for (int i=0;i<3;i++)
    //{

    //    cout<<testMe(9,tempIntPtr,test[i])<<endl;

    //}


    //    int userNumberBaseTen = 0;
    //       char someChar;
    //       int baseTenReversed;
    //       int newBinary = 0;

    //       cout << "enter a binary number one bit (0 or 1) at a time-->any other character to quit\n";
    //       cin >> someChar;
    //       while (someChar == '1' || someChar == '0')
    //       {
    //           if(someChar % 2 == 1)
    //           {
    //               userNumberBaseTen = userNumberBaseTen * 2 + 1;
    //           }
    //           else
    //           {
    //               userNumberBaseTen = userNumberBaseTen * 2 + 0;
    //           }
    //           //cout << userNumberBaseTen << endl;
    //           cin >> someChar;

    //       }

    //           cout << "your base 10 number is " << userNumberBaseTen << endl;






    //           system("pause");
    //           //system("pause");
    //       cout << "enter a base 10 number" << endl;
    //       cin >> userNumberBaseTen;//19
    //           while(userNumberBaseTen != 0)
    //           {
    //               if(userNumberBaseTen % 2 == 1)
    //               {
    //                   newBinary = newBinary * 10 + 1;
    //               }
    //               else
    //               {
    //                   newBinary = newBinary * 10 + 0;
    //               }
    //               //cout << "new binary " << newBinary << endl;
    //               userNumberBaseTen = userNumberBaseTen / 2;
    //           }
    //           //cout << "new binary reversed is " << newBinary << endl;
    //           //system("pause");

    //           cout << "new binary ";
    //           while(newBinary != 0)
    //           {
    //               cout << newBinary % 10;
    //               newBinary = newBinary /10;
    //           }

    //           //cout << "new binary is " << newBinary << endl;
    //           cout << endl;
    //       system("pause");


    //    double x=0;

    //    std::cout<<"X: ";
    //    cin>>x;

    //    for (int i=0;i<50;i++)
    //    {

    //        x=newtonsMethod(x);
    //        std::cout<<"DEBUG x: "<<x<<std::endl;

    //    }


    return 0;
}


double average(double x, double y)
{
    return (x+y)/(2);
}






//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//double Y(double x)
//{
//    std::cout<<"DEBUG xxxxxxxxxx: "<<x<<std::endl;
//    double ans=pow(20,1/5);
//    std::cout<<"DEBUG ansansans: "<<ans<<std::endl;
//    return ans;
//}

//double YPrime(double x)
//{
//    return 1/(5*(pow(20,4/5)));
//}
//double newtonsMethod(double x)
//{
//    double y=Y(x);
//    double yprime=YPrime(x);

//    std::cout<<"DEBUG y: "<<y<<std::endl;
//    std::cout<<"DEBUG yprime: "<<yprime<<std::endl;
//    return x-(y/yprime);
//}
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@










//double pointSlope(double x1, double y1, double x2, double y2)
//{
//    return (y2-y1)/(x2-x1);
//}

/***********************************
 * Function: greatestCommonFactor
 * Purpose: finds the greatest common factor between 2 numbers
 * Parameters: 2 numbers
 * Returns: the greatest common factor
 * Summary:
 * Notes:
 * ***********************************/
//int greatestCommonFactor(int num1, int num2)
//{
//    if (num1!=0 && num2!=0) //accounts for 0 exception
//    {
//        num1=abs(num1);//accounts for negative number exception
//        num2=abs(num2);//accounts for negative number exception

//        largest2Smallest(num1,num2); //reorders numbers in descending order

//        for (int i=num1;i>0;i--) //starting from the top number, checks 1 factor of num1 against all numbers of num2 for a match, then returns the match.
//        {
//            if (num1%i==0)
//            {
//                for (int j=1;j<=num2;j++)
//                {
//                    if (i== (double)num2/j)
//                        return i; //1 is always a factor
//                }
//            }
//        }
//    }
//    return 0;
//}

/***********************************
 * Function: largest2Smallest
 * Purpose: reorders 2 numbers in descending order
 * Parameters: 2 numbers
 * Returns: 2 numbers in descending order
 * Summary:
 * Notes:
 * ***********************************/
//void largest2Smallest(int &num1, int &num2)
//{
//    int big=biggestOf2Numbers(num1,num2);
//    int small=smallestOf2numbers(num1,num2);

//    num1=big;
//    num2=small;
//}

//int smallestOf2numbers(int num1, int num2)
//{
//    if (num1<num2)
//    {
//        return num1;
//    }
//    else
//        return num2;
//}

//int biggestOf2Numbers(int num1, int num2)
//{
//    if (num1>num2)
//    {
//        return num1;
//    }
//    else
//        return num2;
//}

//template<typename T>
//void swap(T &x, T &y)
//{
//    T temp = x;
//    x = y;
//    y = temp;
//}


