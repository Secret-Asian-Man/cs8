
//Parser, a class that "figures out" what the user entered and prepares three things: an operand stack, an operator stack,
//and a queue which holds the expression that needs to be translated from algebraic to RPN.
//(NOTE: This implies that the queue must hold different data types -- operands, parens, and operators)

#ifndef PARSER_H
#define PARSER_H
#include "queue.h"
#include "stack.h"
#include <cmath>
#include "mixednumbersv2.h"
#include <string>
#include <iostream>

enum PARSER_ERRORS {LPARENS_AT_END,RPARENS_WITHOUT_LPARENS, SYNTAX_ERROR};


template<typename T>
class parser
{
public:
    parser();
    ~parser();

private:
    queue<char> userInput;
    stack<char> s;
    queue<char> q;

    void getInput();
    bool PutToStack(stack<T> s, T op);
    int getPrec(char op);
    bool isdot(T in);
    bool issymbol(T in);
    bool isLparen(T in);
    bool isRparen(T in);
    bool isSpace(T in);
    queue<T> shuntMyYard(queue<T> input);
    double evaluate(queue<T> input);



};

template<typename T>
parser<T>::parser()
{
    getInput();

    q = shuntMyYard(userInput);
    cout<<q<<endl;

    double answer=evaluate(q);

    std::cout<<"DEBUG preliminary answer: "<< answer<<std::endl;


    mixedNumbersV2 finalAnswer(answer); //can't take 0's, negatives, 0.#(soft, something wrong with cout maybe)
    std::cout<<"FINAL ANSWER : "<<finalAnswer<<std::endl;


    q.clear();


}

template<typename T>
parser<T>::~parser()
{
    q.clear();
    s.clear();
    userInput.clear();
}

template<typename T>
void parser<T>::getInput()
{

    char temp=' ';

    std::cout<<"Enter Equation: ";

    while(temp!=10)//10 is ascii for new line aka enter button
    {
        temp=cin.get();

        if (temp!=10)
        {
            userInput.push(temp);
        }
    }

}


template<typename T> //** MIGHT NEED TO BE *S
bool parser<T>::PutToStack(stack<T> s, T op) //PUTS AN ITEM INTO THE OPERATOR STACK
{

    if(s.empty())
    {
        return true;
    }
    if(!s.empty())
    {
        char compareOp = s.peek();
        if(compareOp == op) //types are different
        {
            return true;
        }
    }
    return false;
}

template<typename T>
int parser<T>::getPrec(char op)
{
    if(op == '+' || op == '-')
    {
        return 1;
    }
    else if(op == '*' || op == '/')
    {
        return 2;
    }
    else if(op == '^')
    {
        return 3;
    }
    else
        return -1;

}

template<typename T>
bool parser<T>::isdot(T in)
{
    char dot = '.';
    if(in == dot)
    {
        return true;
    }

    return false;
}

template<typename T>
bool parser<T>::issymbol(T in)
{
    char symbols[5] = {'+','-','/','*','^'};
    for(int i = 0; i < 5; i++)
    {
        if(in == symbols[i])
        {
            return true;
        }
    }

    return false;
}

template<typename T>
bool parser<T>::isLparen(T in)
{
    char paren = '(';
    if(in == paren)
    {
        return true;
    }

    return false;
}


template<typename T>
bool parser<T>::isRparen(T in)
{
    char paren = ')';

    if(in == paren)
    {

        return true;
    }


    return false;
}

template<typename T>
bool parser<T>::isSpace(T in)
{
    char space = ' ';
    if(in == space)
    {
        return true;
    }

    return false;
}


template<typename T>
queue<T> parser<T>::shuntMyYard(queue<T> input)
{
    char myPrevious='b';
    char myPreviousAbsolute='b';

    while(!input.empty()) //there's something in the input queue
    {

        char front = input.peek();
        T dummy; // i have this variable because pop needs a parameter

        if(isdigit(front)) //meaning digit
        {
            while(((isdigit(front)) || isdot(front)) && !(input.empty())) //while the next one is a number abd input is not empty, keep pusing
            {
                q.push(front);



                //increments and if number save a history of that number to use as a signature
                if (isdigit(front))
                {
                    input.pop(myPrevious); //if digit save the number
                    myPreviousAbsolute=myPrevious;
                }
                else
                {
                    input.pop(myPreviousAbsolute); //if dot, continue without saving
                }





                if (!input.empty())
                    front = input.peek();
            }
            q.push('_'); //insert a _ after every varible

        }
        else if(isdot(front))
        {
            if(!isdigit(myPreviousAbsolute))
            {
                q.push('0');
                q.push(front);
                input.pop(myPreviousAbsolute);

            }
        }
        else if(isSpace(front)) //when I'm at a space
        {

            input.pop(myPreviousAbsolute);
            if (isdigit(input.peek()) && isdigit(myPrevious))//if I have a number on my left and right
            {
                //treat space as a + operator

                if(PutToStack(s, '+'))
                {

                    s.push('+');
                    //input.pop(myPreviousAbsolute);

                }
                else //meaning stack is not empty or operator comparison
                {

                    if(!s.empty())
                    {

                        char compareOp = s.peek();
                        if (getPrec(compareOp) >= getPrec('+') && compareOp!=NULL)//***** NULL MIGHT CAUSE A PROBLEM
                        {
                            q.push(compareOp);
                            s.pop(dummy);
                            s.push('+');
                        }
                        else
                            s.push('+');

                        //input.pop(myPreviousAbsolute);
                    }
                }
            }
            else
            {

            }

            //else, its an operator
            //ignore space

        }
        else if(issymbol(front))//COPY COPY COPY COPY COPY //operator case: put it into my array according to pres,
        {
            //if this case is true then we have a negative number
            if(front == '-' && !isdigit(myPreviousAbsolute) )//might need to include && q.empty()
            {

                q.push('n');
                input.pop(myPrevious);
                myPreviousAbsolute=myPrevious;

            }
            else if(PutToStack(s, front)) //if PutToStack is true, then the operators are different, so we need to check the precedence
            {

                s.push(front);
                input.pop(myPrevious);
                myPreviousAbsolute=myPrevious;

                //                break;

            }
            else //meaning stack is not empty or operator comparison
            {

                if(!s.empty())
                {

                    char compareOp = s.peek();
                    if (getPrec(compareOp) >= getPrec(front) && compareOp!=NULL)//***** NULL MIGHT CAUSE A PROBLEM
                    {
                        q.push(compareOp);
                        s.pop(dummy);
                        s.push(front);
                    }
                    else
                        s.push(front);

                    input.pop(myPrevious);
                    myPreviousAbsolute=myPrevious;
                }


            }
            //            break;


        }
        //        else if(issymbol(front)) //operator case: put it into my array according to pres,
        //        {

        //            if(PutToStack(s, front)) //if PutToStack is true, then the operators are different, so we need to check the precedence
        //            {

        //                s.push(front);
        //                input.pop(myPrevious);

        //            }
        //            else //meaning stack is not empty or operator comparison
        //            {

        //                if(!s.empty())
        //                {

        //                    char compareOp = s.peek();
        //                    if (getPrec(compareOp) >= getPrec(front) && compareOp!=NULL)//***** NULL MIGHT CAUSE A PROBLEM
        //                    {
        //                        q.push(compareOp);
        //                        s.pop(dummy);
        //                        s.push(front);
        //                    }
        //                    else
        //                        s.push(front);

        //                    input.pop(myPrevious);
        //                }


        //            }


        //        }
        else if(isLparen(front)) //opening parenthesis L
        {

            s.push(front);
            input.pop(myPreviousAbsolute);

        }
        else if(isRparen(front)) //closing parenthesis R
        {
            char compareOp = s.peek();

            while(!(s.empty()) && !(isLparen(compareOp))) // keep comparing the next thing while it's not empty
            {
                q.push(compareOp);
                s.pop(dummy);
                if(!s.empty())
                {
                    compareOp = s.peek();
                }

            }

            //If the stack runs out without finding a left parenthesis, then there are mismatched parentheses.
            if(isLparen(compareOp)) //if you find the LPAREN, cool! pop it and move on
            {

                input.pop(myPreviousAbsolute);
                s.pop(dummy);

            }
            else                            //EXCEPTION HANDELING FOR RPARENS WITHOUT OPENING LPARENS
            {
                //                int error = 2;
                //                throw error;
                throw RPARENS_WITHOUT_LPARENS;

            }

        }
        else
            cout << "Shuntingyard: switch case failed"<<endl;



    } //end of while loop, meaning input queue is now empty


    while(!s.empty()) //now taking everything out of the operator stack into the output stack
    {
        char compareOp = s.peek();
        // s.pop(dummy);//**********

        if(!(isLparen(compareOp)) && !(isRparen(compareOp))) //meaning put everything BUT parenthesis into the output queue
        {
            T dummy=T();
            q.push(compareOp);
            s.pop(dummy);
        }
        else               //if my input queue is empty after insert a Lparen -- there are mismatched parens
        {
            //            int error = 1; //EXCEPTION HANDELING FOR LPARENS AT THE END
            //            throw error;
            throw LPARENS_AT_END;

        }
    }

    return q;
}

//template<typename T>
//double parser<T>::evaluate(queue<T> input)
//{
//    stack<double> output;
//    double ans;

//    while(!input.empty())          //while the postfix, output stack is not empty
//    {
//        char stash = input.peek(); //getting the first value of the output queue
//        T dummy = T();

//            if(isdigit(stash)) //meaning digit
//            {
//                output.push(stash);
//                char num = input.peek(); //IWT

//                double madeNum = (num - '0'); //this changes it to a digit
//                ans = madeNum;

//            }
//            else if(issymbol(stash)) //operator case: put it into my array according to pres,
//            {
//              double Dright = 0;
//              double Dleft = 0;

//              output.pop(Dright);
//              output.pop(Dleft);


//              char ops[5] ={'+','-','*','/', '^'};
//              int operation;
//              bool found = false;

//              for(int i = 0; i < 5; i++)
//              {
//                  if(stash == ops[i])
//                  {
//                  operation = i;
//                  found = true;
//                  }
//              }

//              //std::cout<<"DEBUG operation: "<<operation<<std::endl;

//              if(!found) //IF OP NOT FOUND
//              {
//                  throw SYNTAX_ERROR;
//              }


//                switch(operation)
//                {
//                    case 0:
//                        ans = Dright + Dleft;
//                        std::cout<<"DEBUG ans: "<<ans<<std::endl;
//                        std::cout<<"DEBUG '5'-'0': "<<'5'-'0'<<std::endl;
//                        std::cout<<"DEBUG Dleft: "<<Dleft<<std::endl;
//                        std::cout<<"DEBUG Dright: "<<Dright<<std::endl;
//                        break;
//                    case 1:
//                        ans = Dleft - Dright;
//                        break;
//                    case 2:
//                        ans = (Dleft)*(Dright);
//                        break;
//                    case 3:
//                        ans = (Dleft)/(Dright);
//                        break;
//                    case 4:
//                        ans = pow(Dleft,Dright);
//                        break;
//                    default:
//                        cout << "Invalid  operator" <<endl;
//                            break;
//                }

//                //delete stash;
//                //delete Nright;
////                if(operation <= 6) //CHANGE THIS
////                {
////                    output.pop(); COMMENTED THIS OUT ***************
//                    //delete Nleft;
////                }



//            }

//            input.pop(myPreviousAbsolute);
//            output.push(ans); //IWT just made it ans
//    }



//    return ans;


//}

template<typename T>
double parser<T>::evaluate(queue<T> input) //COPY COPY COPY COPY
{

    stack<double> output;
    double ans;
    char myPreviousAbsolute;
    while(!input.empty())          //while the postfix, output stack is not empty
    {
        char stash = input.peek(); //getting the first value of the output queue

        if(isdigit(stash)) //meaning digit
        {
            string tempString="";
            char tempChar;
            double ans=0;

            //--------------Takes out big numbers and converts it to a double-------------------
            while(input.peek()!='_' && !input.empty())
            {
                input.pop(tempChar);
                tempString=tempString+tempChar;
            }



            ans= (double)(stod(tempString));
            //---------------------------------


            if(myPreviousAbsolute == 'n')
            {
                ans= ans*(-1) ;
            }
            if(input.peek()=='_')
            {
                input.pop(tempChar); //popping the underscore
                myPreviousAbsolute=tempChar;
            }

            output.push(ans);


        }


        //        if(isdigit(stash)) //meaning digit
        //        {
        //            char temp;
        //            double ans=0;
        //            //bool decimalToggle=false;
        //            double decPlace=0.0;
        //            //when encountering a secondary number I need to multiply the previous by 10 and add it to the new number

        //            while(input.peek()!='_' && !input.empty() && !input.peek()!='.')
        //            {

        //                input.pop(temp);
        //                ans=(ans*10)+(temp-'0');
        //                std::cout<<"DEBUG ans: "<<ans<<std::endl;

        //            }
        //            if(input.peek() == '.')
        //            {

        //                while(input.peek()!='_' && !input.empty())
        //                {
        //                    input.pop(temp);

        //                    decPlace=(decPlace/10)+(temp-'0');
        //                    std::cout<<"DEBUG decPlace: "<<decPlace<<std::endl;

        //                }
        //            }
        //            std::cout<<"DEBUG ans final: "<<ans<<std::endl;
        //            ans = ans + decPlace;
        //            output.push(ans);



        //        }
        else if(stash=='_')
        {
            input.pop(myPreviousAbsolute);
        }
        else if(stash=='n')
        {
            input.pop(myPreviousAbsolute); //pops out the negative
        }
        else if(issymbol(stash)) //operator case: put it into my array according to pres,
        {
            double Dright = 0;
            double Dleft = 0;

            output.pop(Dright);
            output.pop(Dleft);


            char ops[5] ={'+','-','*','/', '^'};
            int operation;
            bool found = false;

            for(int i = 0; i < 5; i++)
            {
                if(stash == ops[i])
                {
                    operation = i;
                    found = true;
                }
            }


            if(!found) //IF OP NOT FOUND
            {
                throw SYNTAX_ERROR;
            }


            switch(operation)
            {
            case 0:
                ans = Dright + Dleft;
                break;
            case 1:
                ans = Dleft - Dright;
                break;
            case 2:
                ans = (Dleft)*(Dright);
                break;
            case 3:
                ans = (Dleft)/(Dright);
                break;
            case 4:
                ans = pow(Dleft,Dright);
                break;
            default:
                cout << "Invalid  operator" <<endl;
                break;
            }

            output.push(ans);//push my answer into the stack
            input.pop(myPreviousAbsolute);

        }

        // output.push(ans); //IWT just made it ans
    }

    output.pop(ans);

    return ans;


}



#endif // PARSER_H



















//==================================================================

//Parser, a class that "figures out" what the user entered and prepares three things: an operand stack, an operator stack,
//and a queue which holds the expression that needs to be translated from algebraic to RPN.
//(NOTE: This implies that the queue must hold different data types -- operands, parens, and operators)

//#ifndef PARSER_H
//#define PARSER_H
//#include "queue.h"
//#include "stack.h"
//#include <string>

//class parser
//{
//public:
//    parser();
//    ~parser();

//private:
//    queue<char> userInput;
//    queue<void*> voidUserInput;
//    queue<string> output;
//    stack<char> operators;


//    char numKey[10]={'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};//make the comparison when you pop;
//    char operatorKey[7]={'+', '-', '*', '/', '^', '(', ')'};




//    void getInput();

//};






//#endif // PARSER_H
//==================================================================
