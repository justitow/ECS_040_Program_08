//
// Created by Justin Weich on 3/6/16.
//

#ifndef ECS_040_PROGRAM_08_INDEXPAGER_H_H
#define ECS_040_PROGRAM_08_INDEXPAGER_H_H

#include "pager.h"

class IndexPager : public Pager
{
private:

public:
  void read(istream &in);
  void ProcessKey(int key);
  IndexPager();
  ~IndexPager();

};


#endif //ECS_040_PROGRAM_08_INDEXPAGER_H_H
