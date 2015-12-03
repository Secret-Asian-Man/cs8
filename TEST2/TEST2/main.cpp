#include <iostream>
#include "orchard.h"

using namespace std;

int main()
{

    try
    {
        //orchard editorsDream("Project Gutenberg EBook of War and Peace, by Leo Tolstoy.txt");
        orchard editorsDream("../resources/testInputFile.txt");


    }
    catch(FILE_ERROR error)
    {
        switch (error)
        {

        case fileNotFound:
            std::cout<<"ERROR fileNotFound "<<std::endl;
            break;

        default:
            std::cout<<"Unknown FILE_ERROR Error... "<<std::endl;
            break;
        }
    }
    catch(HEAP_ERRORS error)
    {
        switch (error)
        {

        case EMPTY:
            std::cout<<"ERROR Heap Empty "<<std::endl;
            break;

        default:
            std::cout<<"Unknown Heap Error... "<<std::endl;
            break;
        }
    }






    return 0;
}

