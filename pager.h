#ifndef PAGER_H
  #define PAGER_H

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Pager {
  int TopLine;
  void WritePage();
protected:
  vector <string> Text;
  const string& IntToString(int num);
public:
  Pager():TopLine(0){}
  virtual ~Pager(){}
  void ProcessKey(int key);  // f = forward, b = back
  virtual void read(istream &in);
};

#endif

