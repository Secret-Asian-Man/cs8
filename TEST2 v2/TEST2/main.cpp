#include <iostream>
#include "orchard.h"
#include <cstdio>
#include <ctime>

using namespace std;

int main()
{
    try
    {
        std::clock_t start;
            double duration;

            start = std::clock();
        orchard editorsDream("../resources/Project Gutenberg EBook of War and Peace, by Leo Tolstoy.txt");
//        orchard editorsDream("../resources/testInputFile.txt");

        duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
          std::cout<<"Timer: "<< duration <<'\n';

          editorsDream.displayOrchard();
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

