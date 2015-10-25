
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

enum PARSER_ERRORS {LPARENS_AT_END,RPARENS_WITHOUT_LPARENS, SYNTAX_ERROR, MATH_ERROR};


template<typename T>
class parser
{
public:
    //constructors
    parser(); //unused because of GUI
    parser(queue<char> input);
    parser(string input);

    //destructor
    ~parser();

    //accessors
    double getAnswer();
    queue<T> getPostfix();

    //functions
    void calculate(queue<char> input);
    void calculate(string input);

    //public variables
    mixedNumbersV2 finalAnswer;


private:

    //private variables
    queue<char> userInput;
    stack<char> s;
    queue<char> q;
    queue<char> postFix;

    double answer;

    //private functions
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
    //unused, because of GUI

}

template<typename T>
parser<T> ::parser(queue<char> input)
{
    calculate(input);
}

template<typename T>
parser<T>::parser(std::string input)
{
    calculate(input);
}

template<typename T>
parser<T>::~parser()
{
    q.clear();
    s.clear();
    userInput.clear();
    answer=0;
}

template<typename T>
double parser<T>::getAnswer()
{
    return answer;
}

template<typename T>
queue<T> parser<T>::getPostfix()
{
    return postFix;
}

template<typename T>
void parser<T>::calculate(queue<char> input)
{
    q = shuntMyYard(input);//rearranges prefix and stores postfix into q
    cout<<q<<endl;

    answer=evaluate(q); //finds stores the answer
    std::cout<<"Preliminary answer: "<<answer<<std::endl;


    finalAnswer.setBoth(answer);
    std::cout<<"Final Answer : "<<finalAnswer<<std::endl;

    q.clear();
}

template<typename T>
void parser<T>::calculate(std::string input) //takes a string, tokenizes it, and makes a input queue
{
    queue<char> userInputQueue;

    for (unsigned int i=0;i<input.size();i++)
        userInputQueue.push((char)input[i]);



    q = shuntMyYard(userInputQueue);//rearranges prefix and stores postfix into q
    cout<<q<<endl;

    postFix=q;

    answer=evaluate(q); //finds stores the answer
    std::cout<<"Preliminary answer: "<<answer<<std::endl;


    finalAnswer.setBoth(answer);
    std::cout<<"Final Answer : "<<finalAnswer<<std::endl;

    q.clear();
}

template<typename T>
void parser<T>::getInput()
{
    char temp=' ';

    std::cout<<"Enter Equation: ";

    while(temp!=10)//10 is ascii for new line aka enter button
    {
        temp=cin.get();

        if (temp!=10)//10 is ascii for new line aka enter button
            userInput.push(temp);
    }
}


template<typename T>
bool parser<T>::PutToStack(stack<T> s, T op) //Puts an item into the operator stack.
{
    if(s.empty())//if the stack isn't empty
        return true;

    else
        if(s.peek() == op) //checks if the types are the same
            return true;

    return false;
}

template<typename T>
int parser<T>::getPrec(char op)
{
    switch (op)
    {
    case '+':
    case '-': return 1;

    case '*':
    case '/': return 2;

    case '^': return 3;

    default: return -1;
    }
}

template<typename T>
bool parser<T>::isdot(T in)
{
    if(in == '.')
        return true;

    return false;
}

template<typename T>
bool parser<T>::issymbol(T in)
{
    char symbols[5] = {'+','-','/','*','^'};

    for(int i = 0; i < 5; i++)
        if(in == symbols[i])
            return true;

    return false;
}

template<typename T>
bool parser<T>::isLparen(T in)
{
    if(in == '(')
        return true;

    return false;
}


template<typename T>
bool parser<T>::isRparen(T in)
{
    if(in == ')')
        return true;

    return false;
}

template<typename T>
bool parser<T>::isSpace(T in)
{
    if(in == ' ')
        return true;

    return false;
}


template<typename T>
queue<T> parser<T>::shuntMyYard(queue<T> input)
{
    char myPreviousNumber='b'; //holds the most previous NUMBER that was popped
    char myPreviousAbsolute='b'; //holds the most previous ITEM that was popped
    bool nAfter = false;
    bool rPMultiply=false;


    while(!input.empty()) //there's something in the input queue
    {
        char front = input.peek();
        T dummy; // I have this variable because pop needs a parameter

        if(isdigit(front)) //meaning digit
        {
            while(((isdigit(front)) || isdot(front)) && !(input.empty())) //while the next one is a number abd input is not empty, keep pusing
            {
                q.push(front);

                //increments and if number save a history of that number to use as a signature
                if (isdigit(front))
                {
                    input.pop(myPreviousNumber); //if digit save the number
                    myPreviousAbsolute=myPreviousNumber;
                }
                else
                    input.pop(myPreviousAbsolute); //if dot, continue without saving

                if (!input.empty())
                    front = input.peek();
            }

            q.push('_'); //insert a _ after every varible

            if (rPMultiply)
            {
                q.push('*');
                rPMultiply=false;
            }
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

            if (isdigit(input.peek()) && isdigit(myPreviousNumber))//if I have a number on my left and right
            {
                //treat space as a + operator

                if(PutToStack(s, '+'))
                    s.push('+');
                else //meaning stack is not empty or operator comparison
                {
                    if(!s.empty())
                    {
                        char compareOp = s.peek();
                        if (getPrec(compareOp) >= getPrec('+'))
                        {
                            q.push(compareOp);
                            s.pop(dummy);
                            s.push('+');
                        }
                        else
                            s.push('+');
                    }
                }
            }
            //else, its an operator. Ignore Space_


        }

        else if(issymbol(front))
        {
            //if this case is true then we have a negative number
            if(front == '-' && !isdigit(myPreviousAbsolute) )//might need to include && q.empty()
            {
                //INSERT A ADDITIONAL IF STATMENT HERE:
                //if next pos is not an LParen, do this:

                char next='b';

                if (input.getSize()>=2)//gets the next inside a queue by making a copy and popping twice
                {
                    queue<T> temp(input); //makes a copy

                    temp.pop(dummy); //increments the copy
                    next=temp.peek(); //saves the next value
                    temp.clear(); //destroys the copy
                }

                if((input.getSize()>=2) && (!isLparen(next))) // have to write a next. Must have at least 2 in array to get a next
                    q.push('n');
                else if (input.getSize()>=2 && isLparen(next))
                    nAfter = true;

                input.pop(myPreviousAbsolute); //MEJAN: TO POP THE N REGARDLESS
            }

            else if(PutToStack(s, front)) //if PutToStack is true, then the operators are different, so we need to check the precedence
            {
                s.push(front);
                input.pop(myPreviousNumber);
                myPreviousAbsolute=myPreviousNumber;
            }

            else if(!s.empty()) //meaning stack is not empty or operator comparison
            {
                char compareOp = s.peek();

                if (getPrec(compareOp) == 3 && front=='/')
                {
                    input.pop(myPreviousAbsolute); //the Divide symbol

                    while(!input.empty() && isdigit(input.peek()))
                    {
                        input.pop(front);//pops the 2
                        myPreviousAbsolute=front;
                        q.push(front);
                    }

                    q.push('_');
                    q.push('/');
                    q.push('^');

                    s.pop(dummy);
                }

                else if (getPrec(compareOp) >= getPrec(front))
                {
                    q.push(compareOp);
                    s.pop(dummy);
                    s.push(front);

                    input.pop(myPreviousNumber); //this might cause a problem
                    myPreviousAbsolute=myPreviousNumber;
                }
                else
                {
                    s.push(front);
                    input.pop(myPreviousAbsolute);
                }
            }
        }

        else if(isLparen(front)) //opening parenthesis L
        {
            if (isdigit(myPreviousAbsolute))
                s.push('*');

            s.push(front);
            input.pop(myPreviousAbsolute);
        }

        else if(isRparen(front)) //closing parenthesis R
        {
            char next='b';
            char dummy='b';

            if (input.getSize()>=2)//gets the next inside a queue by making a copy and popping twice
            {
                queue<T> temp(input); //makes a copy

                temp.pop(dummy); //increments the copy
                next=temp.peek(); //saves the next value
                temp.clear(); //destroys the copy
            }

            char compareOp = s.peek();

            while(!(s.empty()) && !(isLparen(compareOp))) // keep comparing the next thing while it's not empty
            {
                q.push(compareOp);
                s.pop(dummy);

                if(!s.empty())
                    compareOp = s.peek();
            }

            //If the stack runs out without finding a left parenthesis, then there are mismatched parentheses.
            if (isdigit(next) && (input.getSize()>=2))
            {

                rPMultiply=true;
                //q.push('*'); //need to push in the next number
            }

            if (nAfter)
            {
                q.push('n');
                nAfter=false; //resets the nAfter
            }
            if(isLparen(compareOp)) //if you find the LPAREN, cool! pop it and move on
            {
                input.pop(myPreviousAbsolute);
                s.pop(dummy);
            }
            else//EXCEPTION HANDELING FOR RPARENS WITHOUT OPENING LPARENS
                throw RPARENS_WITHOUT_LPARENS;
        }
        else
            cout << "Shuntingyard: switch case failed"<<endl;
    } //end of while loop, meaning input queue is now empty


    while(!s.empty()) //now taking everything out of the operator stack into the output stack
    {
        char compareOp = s.peek();

        if(!(isLparen(compareOp)) && !(isRparen(compareOp))) //meaning put everything BUT parenthesis into the output queue
        {
            T dummy=T();
            q.push(compareOp);
            s.pop(dummy);
        }
        else //if my input queue is empty after insert a Lparen -- there are mismatched parens
            throw LPARENS_AT_END;
    }

    return q; //returns the final postfix
}

template<typename T>
double parser<T>::evaluate(queue<T> input)
{
    stack<double> output;
    double ans=0;
    char myPreviousAbsolute='b';

    while(!input.empty())//while the postfix, output stack is not empty
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
            //------------------------------------------------------------------------------------

            if(myPreviousAbsolute == 'n')  //THE PROBLEM IS WITH THE LOGIC HERE?

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

        else if(stash=='_')
        {
            input.pop(myPreviousAbsolute);
        }

        else if(stash=='n')
        {
            input.pop(myPreviousAbsolute); //pops out the negative

            if (issymbol(input.peek()))
            {
                double temp;

                output.pop(temp);
                temp=temp*(-1);
                output.push(temp);
            }
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
                if(stash == ops[i])
                {
                    operation = i;
                    found = true;
                }

            if(!found) //IF OP NOT FOUND
                throw SYNTAX_ERROR;

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
                if (Dright==0)
                    throw MATH_ERROR;
                ans = (Dleft)/(Dright);
                break;
            case 4:
                ans=pow(Dleft,Dright);

                if (ans!=ans) //if nan
                    throw MATH_ERROR;
                break;

            default:
                cout << "Invalid  operator" <<endl;
                break;
            }

            output.push(ans);//push my answer into the stack
            input.pop(myPreviousAbsolute);
        }
    }

    output.pop(ans);

    return ans;
}
#endif // PARSER_H
