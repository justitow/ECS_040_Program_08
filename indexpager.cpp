//
// Created by Justin Weich on 3/6/16.
//

#include <sstream>
#include <vector>
#include <iostream>

#include "indexpager.h"

IndexPager::IndexPager() : Pager()
{

} // IndexPager()

IndexPager::~IndexPager()
{

} // ~IndexPager()

string IndexPager::createString(const vector<int> &nums,
                                ostringstream &os) const
{
  int temp;

  for (unsigned int i = 0; i < nums.size(); i++) // for each line number
    {
      os << nums.at(i);

      if (i == nums.size() - 1)
        os << '.';
      else // not last number
        if ((i + 1 < nums.size())
            && ((nums.at(i) == nums.at(i + 1) - 1)
            || (nums.at(i) == nums.at(i + 1))))
        {
          temp = nums.at(i);

          while ((i + 1 < nums.size())
                 && ((nums.at(i) == nums.at(i + 1) - 1)
                 || (nums.at(i) == nums.at(i + 1))))
            i++;

          if (nums.at(i) > temp)
            os << '-' << nums.at(i);

          if (i == nums.size() - 1)
            os << '.';
          else // not yet end
            os << ", ";
        } // consecutive or same line numbers
      else // not consecutive or same line numbers
        os << ", ";
    } // for each line number

  return os.str();  
} // createString()

void IndexPager::read(istream &in)
{
  string str;
  int line = 0, wordCount = 0;

  while (getline(in, str))
  {
    string word = "";

    for (string::iterator it = str.begin(); it <= str.end(); it++)
    {
      if (toupper(*it) >= 'A' && toupper(*it) <= 'Z')
        word.append(1, *it);
      else // not a letter
      {
        if (word.length() > 0)
        {
          if (WordKey.find(word) == WordKey.end())
          {
            WordKey.insert(pair<string, int>(word, wordCount));
            wordCount++;
          } // if word already in map

          mmap.insert(pair<int, int>(WordKey.find(word)->second, line));
          word = "";
        } // word length > 0

      } // not a letter

    } // while

    line++;
  } // while

  createPage();
} // read()

void IndexPager::processKey(int key)
{

  if(key == 'f')
  {
    TopLine += 20;

    if(TopLine > (int) Text.size())
      TopLine = Text.size();
    writeIndex();
  } // if key is 'f'
  else // go back
  if(key == 'b')
  {
    TopLine -= 20;

    if(TopLine < 0)
      TopLine = 0;
    writeIndex();

  } // if key is 'b'
} // ProcessKey() should never be called

void IndexPager::writeIndex()
{
  int end = TopLine + 23;

  if(end > (int) Text.size())
    end = Text.size();

  for(int i = TopLine; i < end; i++)
    cout << Text.at(i) << endl;
} // WriteIndex()

void IndexPager::createPage()
{
  vector<int> lineNums;
  ostringstream out;
  
  for (map<string, int>::iterator it = WordKey.begin();
       it != WordKey.end(); it++) // each word
  {
    //int temp;
    multimap<int, int>::iterator line;
    pair<multimap<int, int>::iterator, multimap<int, int>::iterator>
      range = mmap.equal_range((*it).second);

    for (line = range.first; line != range.second; ++line)
      lineNums.push_back((*line).second);
    
    out << (*it).first << ' ';
    
    text.push_back(createString(lineNums, out));
    lineNums.clear();
    out.str("");
  } // for each word
} // CreatePage()
