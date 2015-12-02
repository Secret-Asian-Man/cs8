#ifndef STOKEN_H
#define STOKEN_H
#include <iostream>

using namespace std;

class sToken
{
public:
  sToken();
  sToken(string src);

  void operator =(string src);
  void identify();
  void Zorg();
  void reset();

  void showStatus();
  void initializeBlanks();

  bool progress();

  string alphabet = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
  string digits = "1234567890";
  string spaces=" \n\t";
  string specials = "!@#$%^&*()_-~`+=/;:'[]{}\<>.,?\"|";

private:
  string STOKEN;
  string SOURCE;
  string SET;
  bool done;
  int anchor;
  int tokenType;

};

#endif // STOKEN_H
