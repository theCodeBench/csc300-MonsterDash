/*************************************************************************//**
 * @file 
 *
 *****************************************************************************/

#ifndef __MONSTER_H
#define __MONSTER_H
#include <stdlib.h>
#include <vector>
#include <climits>
#include "site.h"
#include "playfield.h"


///  A class for the monster to use when moving
class Monster 
{
    Playfield* playfield;
    int N;
 
    public:
       Monster(Playfield* play);
       Site* move();
};

#endif
