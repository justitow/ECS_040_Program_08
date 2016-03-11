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
  int wordCount = 0;
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
          if (WordKey.find(word) == WordKey.end())
          {
            WordKey.insert(pair<string, int>(word, wordCount));
            wordCount++;
          }
          mmap.insert(pair<int, int>(WordKey[word], line));
          word = "";
        }
      }
      it++;
    }
    line++;
  }
  //for (multimap<string,int>::iterator it=mmap.begin(); it!=mmap.end(); ++it)
    //cout << (*it).first << " => " << (*it).second << '\n';
  CreatePage();
}

void IndexPager::ProcessKey(int key)
{
  if(key == 'f')
  {
    TopLine += 20;
    if(TopLine > (int) Text.size())
      TopLine = Text.size();
    WriteIndex();
  } // if key is 'f'
  else
  if(key == 'b')
  {
    TopLine -= 20;
    if(TopLine < 0)
      TopLine = 0;
    WriteIndex();
  } // if key is 'b'
}

void IndexPager::WriteIndex()
{
  int end = TopLine + 23;

  if(end > (int) Text.size())
    end = Text.size();

  for(int i = TopLine; i < end; i++)
    cout << Text.at(i) << endl;
}

void IndexPager::CreatePage()
{


  for (map<string, int>::iterator it = WordKey.begin(); it != WordKey.end(); it++)
  {
    cout << (*it).first << " ";
    multimap<int, int>::iterator line;
    pair<multimap<int, int>::iterator, multimap<int, int>::iterator> range = mmap.equal_range((*it).second);

    for (line = range.first; line != range.second; ++line)
    {
      cout << (*line).second << ", ";
    }

    cout << endl;
  }
}