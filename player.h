/*************************************************************************//**
 * @file 
 *
 *****************************************************************************/

#ifndef __PLAYER_H
#define __PLAYER_H
#include <stdlib.h>
#include "site.h"
#include "playfield.h"

//A class for the player to use
class Player 
{
   Playfield* playfield;
   int N;

   public:
      Player(Playfield* p);
      Site* move();
};
#endif
