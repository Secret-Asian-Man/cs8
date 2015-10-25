#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>

using namespace std;

typedef int (*fptr)(int x, int y);

int sum(int x, int y);
int mult(int x, int y);
int divide(int x, int y);
int sub(int x, int y);
void perform(int x, char op, int y, fptr f);
bool again();

int main()
{
    int x, y;
    char op;
    do
    {
        cout<<"Please enter your first integer: ";
        cin>>x;
        cout<<"Please enter the operation to perform: ";
        cin>>op;
        cout<<"Please enter your second integer: ";
        cin>>y;
        switch(op)
        {
          case '+': perform(x,op,y,sum);
                    break;
          case '-': perform(x,op,y,sub);
                    break;
          case '*': perform(x,op,y,mult);
                    break;
          case '/': perform(x,op,y,divide);
                    break;
          default : cout<<"Unknown operator. Please try again"<<endl;
        }
    }while(again());
    return 0;
}


int sum(int x, int y)
{
    return x + y;
}

int mult(int x, int y)
{
    return x * y;
}

int divide(int x, int y)
{
    return x/y;
}

int sub(int x, int y)
{
    return x - y;
}

void perform(int x, char op, int y, fptr f)
{
    printf("function exected at %p gives us",f);
    cout<<x<<' '<<op<<' '<<y<<" = "<<f(x,y)<<endl;
}

bool again()
{
    string ans;
    cin.ignore();
    cout<<"Do you want to do this again? ";
    getline(cin, ans);
    cout<<"ans = "<<ans<<endl;
    return toupper(ans[0]) == 'Y';
}


