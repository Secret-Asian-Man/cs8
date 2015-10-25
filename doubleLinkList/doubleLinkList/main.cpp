#include <iostream>
#include <string>
#include "driver.h"
#include "doublelinkedlist.h"

using namespace std;

int main(int argc, char *argv[])
{
    //================================================
//    try
//    {
//        doubleLinkedList<int> linkListTest;
//        doubleLinkedList<int> linkListTest2;


//        linkListTest.insert(6);
//        linkListTest.insert(8);

//        linkListTest2.insert(6);
//        linkListTest2.insert(1);
//        linkListTest2.insert(2);
//        linkListTest2.insert(12);

////do driver and file output/input

//        cout<<endl;
//        cout<<"ORIGINAL: "<<linkListTest;
//        cout<<endl;

//        cout<<endl;
//        cout<<"ORIGINAL2: "<<linkListTest2;
//        cout<<endl;

//        linkListTest.merge(linkListTest2);

//        cout<<endl;
//        cout<<"MERGED: "<<linkListTest;
//        cout<<endl;

//        cout<<endl;
//        cout<<"MERGED2: "<<linkListTest2;
//        cout<<endl;



//        //        linkListTest.remove(8,1);

//        //        cout<<"REMOVED: "<<linkListTest;
//        //        cout<<endl;

//    }catch(DLL_ERRORS)
//    {
//        cout<<"PROGRAM FAILED!!"<<endl;
//    }
//=============================================================












    //------------------------------Driver-----------------------------------
      doubleLinkedList<char> one, two; //makes 2 doubleLinkedLists for merging later
      char ans; //user input, WARNING: can only take one character
      int list = 1; //for selecting which list to use
      string title[13] = {
          " Please make a selection: ",
          "  S : Select a list",
          "  D : Change print direction",
          "  R : Read from a file",
          "  W : Write to a file",
          "  P : Print the list",
          "  + : Add an item",
          "  - : Delete an item",
          "  F : Find an item",
          "  M : Merge List 2 into List 1",
          "  Q : Quit",
          "Your selection: "}; //print out this chunk, with a endl after each entry

      system("cls"); //clears the screen
      try
      {
        checkArgs(argc, argv, one, two, list); //no idea what argc and argv is
      }
      catch(int e)
      {
         cout<<"Error "<<e<<". Program terminating"<<endl;
         exit(e);
      }

        while(toupper(ans = menu(title)) != 'Q')
           perform(ans, list,  one, two);
    //---------------------------------------------------------------------------

    return 0;
}
