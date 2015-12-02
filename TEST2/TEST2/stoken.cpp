#include "stoken.h"
#include <iostream>

using namespace std;

sToken::sToken()
{
}

sToken::sToken(string src)
{
  SOURCE=src;
  anchor = 0;
  done = false;

}

void sToken::operator =(string src)
{
  SOURCE = src;
  anchor = 0;
  done = false;
}

void sToken::identify()
{
  char first;
  first = SOURCE.at(anchor);

  if(alphabet.find(first)>=0)
    {
      tokenType = 1;
      SET = alphabet;
    }
  else if(digits.find(first)>=0)
    {
      tokenType = 2;
      SET = digits;
    }
  else if(spaces.find(first)>=0)
    {
      tokenType = 3;
      SET = spaces;
    }
  else if(specials.find(first)>=0)
    {
      tokenType = 4;
      SET = specials;
    }
  else
    {
      tokenType = 5;
      specials+=first;
      SET = specials;
    }
}

void sToken::showStatus()
{
  cout <<"\""<<STOKEN<<"\""<<endl;
}

void sToken::Zorg()
{
  using namespace std;

  int pos;

  if(done == true)
    {
      cout << "..." << endl;
      return;
    }
  else
    {
      pos=SOURCE.find_first_not_of(SET,anchor);

      if(pos==-1)
         {
              STOKEN = SOURCE.substr(anchor, SOURCE.length()-anchor);
              done = true;
         }
      else
         {
              done = false;
              STOKEN = SOURCE.substr(anchor, pos-anchor);
              anchor = pos;
         }

    }


}

void sToken::reset()
{
  anchor = 0;
}

void sToken::initializeBlanks()
{
  char* blanks;
  blanks = new char[5];
  blanks[0]=' ';
  blanks[1]='\n';
  blanks[2]='t';
  blanks[3]='\0';

  spaces = blanks;
}

bool sToken::progress()
{
  return done;
}

