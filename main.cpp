#include <fstream>
#include "pager.h"
#include "indexpager.h"

using namespace std;


int main(int argc, char* argv[])
{
  Pager pager, *ptr;
  IndexPager indexer;
  char c;

  ifstream inf(argv[1]);
  if(argv[2][0] == '1')
    ptr = &pager;
  else
    ptr = (Pager*) &indexer;

  ptr->read(inf);
  inf.close();

  ptr->ProcessKey('b');  // Causes initial write
  do{
    cin >> c;
    ptr->ProcessKey(c);
  } while (c != 'q');

  return 0;
}
//---------------------------------------------------------------------------
