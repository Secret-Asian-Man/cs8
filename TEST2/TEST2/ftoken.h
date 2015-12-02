#ifndef FTOKEN_H
#define FTOKEN_H
#include "stoken.h"

#include <fstream>

using namespace std;

class fToken
{
public:

  fToken();

  void getBlock(ifstream& ins);
  void tokenize();
  void status();


private:
  sToken sTK;
  char block[51];
  ifstream fin;

  int filePos=0;
  int bCount;

  bool more;
  bool gotBlock;


};

#endif // FTOKEN_H
