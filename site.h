#ifndef __SITE_H
#define __SITE_H
#include <algorithm>
#include <iostream>

using namespace std;

class Site 
{
      int I;
      int J;

    public:

      Site(int i, int j): I(i), J(j) {}
      int i() { return I; }
      int j() { return J; }

      int manhattanTo(Site *w) { return abs(I - w->i()) + abs(J - w->j()); }
      bool equals(Site *w) { return (manhattanTo(w) == 0); }

      friend ostream& operator<<(ostream& os, Site *site);
};

#endif
