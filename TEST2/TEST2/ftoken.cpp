#include "ftoken.h"

using namespace std;

fToken::fToken()
{
}

void fToken::getBlock(ifstream &ins)
{
  using namespace std;

  char ch;
  bCount=0;

      while(bCount<50)
        {
          ins.get(ch);
          block[bCount]=ch;
          bCount++;
        }

  block[bCount]='\0';

  filePos+=bCount;

  if(bCount==0)
    {
      gotBlock=false;
      more=false;
    }
  else if(bCount==50)
    {
      gotBlock=true;
      more=true;
    }
  else if(bCount<50)
    {
      gotBlock=true;
      more=false;
    }

}

void fToken::status()
{
  using namespace std;
  //cout<<filePos<<" "<<bCount<<" "<<endl;
  //cout<<gotBlock<<" "<<more<<endl;
  cout<<"BLOCK:\""<<block<<"\""<<endl<<endl;

}

void fToken::tokenize()
{
  sTK = block;
  while(sTK.progress()!=true)
    {
      sTK.identify();
      sTK.Zorg();
      sTK.showStatus();
    }


}

