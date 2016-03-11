//
// Created by Justin Weich on 3/6/16.
//

#ifndef ECS_040_PROGRAM_08_INDEXPAGER_H_H
#define ECS_040_PROGRAM_08_INDEXPAGER_H_H

#include <map>
#include "pager.h"

using namespace std;

class IndexPager : public Pager
{
private:
  int TopLine;
  string str;
protected:
  vector<string> Text;
  map<string, int> WordKey;
  multimap<int, int> mmap;
public:
  IndexPager();
  ~IndexPager();
  void CreatePage();
  void read(istream &in);
  void ProcessKey(int key);
  void WriteIndex();

};


#endif //ECS_040_PROGRAM_08_INDEXPAGER_H_H
