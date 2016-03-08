//
// Created by Justin Weich on 3/6/16.
//

#include <sstream>

#include "indexpager.h"

IndexPager::IndexPager() : Pager()
{

}

IndexPager::~IndexPager()
{

}

void IndexPager::read(istream &in)
{
  string str;
  int line = 0;
  while (getline(in, str)) {
    string::iterator it = str.begin();
    string word = "";

    while (it <= str.end())
    {

      if (toupper(*it) >= 'A' && toupper(*it) <= 'Z')
      {
        word.append(1, *it);
      }
      else
      {

        if (word.length() > 0)
        {
          mmap.insert(pair<string, int>(word, line));
          word = "";
        }
      }
      it++;
    }
    line++;
  }
  for (multimap<string,int>::iterator it=mmap.begin(); it!=mmap.end(); ++it)
    cout << (*it).first << " => " << (*it).second << '\n';
}

void IndexPager::ProcessKey(int key)
{

}