#include <iostream>
#include "mixednumbersv2.h"
#include "parser.h"
int main()
{
    // -1 + 5 //DONE
    // 0.8 - 1/2 //Right answer but something wrong with fractions class //DONE
    // 1/2+1
    // 1 (enter) should throw an error
    // 1-1
    // -1+(-1)
    //-1+1

    //------------------------------------PARSER TEST---------------------------------
    try
    {
        while(true)
        {
            parser<char> math;
        }
    }
    catch(QUEUE_ERRORS error)
    {


        switch (error)
        {
        case QUEUE_EMPTY:
            std::cout<<"ERROR: QUEUE_EMPTY "<<std::endl;
            std::cout<<"ERROR: SYNTAX_ERROR "<<std::endl;

            break;

        case QUEUE_FULL:
            std::cout<<"ERROR: QUEUE_FULL "<<std::endl;
            break;

        case QUEUE_ILLEGAL_SIZE:
            std::cout<<"ERROR: QUEUE_ILLEGAL_SIZE "<<std::endl;
            break;

        default:
            cout<<"Unkown QUEUE_EMPTY"<<endl;
            break;
        }
    }
    catch(STACK_ERRORS error)
    {
        switch (error)
        {
        case STACK_EMPTY:
            std::cout<<"ERROR: STACK_EMPTY "<<std::endl;
            std::cout<<"ERROR: SYNTAX_ERROR "<<std::endl;

            break;

        case STACK_FULL:
            std::cout<<"ERROR: STACK_FULL "<<std::endl;
            break;

        case STACK_ILLEGAL_SIZE:
            std::cout<<"ERROR: STACK_ILLEGAL_SIZE "<<std::endl;
            break;



        default:
            cout<<"Unkown STACK_ERRORS"<<endl;
            break;
        }

    }
    catch(PARSER_ERRORS error)
    {
        switch (error)
        {
        case LPARENS_AT_END:
            std::cout<<"ERROR: LPARENS_AT_END "<<std::endl;
            break;

        case RPARENS_WITHOUT_LPARENS:
            std::cout<<"ERROR: RPARENS_WITHOUT_LPARENS "<<std::endl;
            break;

        case SYNTAX_ERROR:
            std::cout<<"ERROR: SYNTAX_ERROR "<<std::endl;
            break;

        default:
            cout<<"Unkown PARSER_ERRORS"<<endl;
            break;
        }
    }


    //-------------------------------------------------------------------------------------------------













    //------------------------------------MIXED NUMBERS/FRACTIONS TEST---------------------------------
//            mixedNumbersV2 test(2.5); //ROUNDING ERROR
//            mixedNumbersV2 test2(0.2); //ROUNDING ERROR
//            mixedNumbersV2 test3=test+test2; //ROUNDING ERROR



//            std::cout<<test3;




    //-------------------------------------------------------------------------------------------------
























    //---------------------------GUIDE----------------------------------
    //make a new class with 1 stack in it.
    //when ever an operator is called pop 2 items from the stack.
    //new class will need a constructor that takes in a string of inputs, or asks the user for a string
    //program will ask the user for the next expression after calculating.
    //if the user presses enter without entering anything, the program will end
    //program must be able to take in decimals and fractions
    //program will output, "expression = mixed number"
    //need: operations (+,-,/, *, and ^ (raise to a power)) and parentheses
    //------------------------------------------------------------------


    //---------------------------Specifications----------------------------------
    //    The calculator must read a complete algebraic expression that can consist of integers, decimals, fractions, or mixed numbers and present the result in proper form (fractions reduced, integer results must have just the integer and no 0/1, purely fractional results must not have a leading integer 0, negative signs must be in the proper places within mixed numbers, and so forth) Any expression that contains both decimals and fractions will provide the result in fractional / mixed number form.

    //    Your program must have the following classes:
    //          Mixed, which  inherits from a class called Fraction, that allows for Mixed numbers (eg. 3 1/2)
    //          Fraction, becuase you will be reading fractions on their own.
    //          Parser, a class that "figures out" what the user entered and prepares three things: an operand stack, an operator stack, and a queue which holds the expression that needs to be translated from algebraic to RPN. (NOTE: This implies that the queue must hold different data types -- operands, parens, and operators)
    //          A queue class which accepts tokens from the parser. Tokens can be either a mixed number, a fraction, an operator, or a parenthesis.  (You cannot "cheat" by having a queue of C++ strings. The queue must "legitimately" hold tokens of different types. Hint: pointers to type void)
    //          Two instances of the stack class. One which holds operators, the other holds mixed numbers and fractions.

    //    You MAY NOT use the STL stack or queue for this, as in you are being tested on your ability to write their equivalents. You must write the appropriate stacks and queues. The stacks and queues must be as generic as possible; meaning that I should be able to use  any other students stack or queue in your program and have it work correctly.

    //    The stack and queue classes must implement their processes using dynamic arrays. Additionally, the stack and queue must not be adjusted between each user input line. This means that your parser class must check for exceptions and handle them accordingly.

    //    The calculator should provide error messages for "algebriacally incorrect" entries (such as a missing closing parentheses, fractions that have a negative sign in the denominator, and so forth)

    //    For ease of parsing, the following rules must be followed:
    //          Mixed numbers can have only one space between the integer and the fraction
    //          Unitary minus signs must appear directly beside the value that they are making negative
    //          Visual display of the calculator should be aesthetically pleasing.

    //    You may use any resource you wish, as long as it can be FULLY DOCUMENTED within your code.

    //    You must be prepared to answer any question about your program when you demonstrate its functionality during lab.
    //------------------------------------------------------------------



    //---------------------------EXAMPLE--------------------------------
    //    In this notation the above expression would be

    //    3 5 + 7 2 - *

    //    Reading from left to right, this is interpreted as follows:

    //    Push 3 onto the stack.
    //    Push 5 onto the stack. The stack now contains (3, 5).
    //    Apply the + operation: take the top two numbers off the stack, add them together, and put the result back on the stack. The stack now contains just the number 8.
    //    Push 7 onto the stack.
    //    Push 2 onto the stack. It now contains (8, 7, and 2).
    //    Apply the - operation: take the top two numbers off the stack, subtract the top one from the one below, and put the result back on the stack. The stack now contains (8, 5).
    //    Apply the * operation: take the top two numbers off the stack, multiply them together, and put the result back on the stack. The stack now contains just the number 40
    //------------------------------------------------------------------

    return 0;
}

