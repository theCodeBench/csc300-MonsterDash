/*************************************************************************//**
 * @file 
 *
 *****************************************************************************/

#include "monster.h"




/**************************************************************************//**
 * @author Ryan Hinrichs
 *
 * @par Description:
 * Monster constructor
 *
 *****************************************************************************/

Monster::Monster(Playfield* p) 
{
   playfield = p;
   N       = playfield->size();
}

/**************************************************************************//**
 * @author Ryan Hinrichs
 *
 * @par Description:
 * Movement function for the monster.  He looks in every direction and goes
 * towards the player directly.
 *
 *****************************************************************************/

Site* Monster::move() 
{
   Site* monster   = playfield->getMonsterSite();
   int myI = monster->i();
   int myJ = monster->j();
   Site* player = playfield->getPlayerSite();

   int min = INT_MAX;
   int dist = 0;
   int opti = 0;
   int optj = 0;

   for(int i = -1; i < 2; i++)
   	for(int j = -1; j < 2; j++)
   	{
   		Site *site = new Site(myI + i, myJ + j);
   		if(playfield->isLegalMove(monster, site))
   		{
   			dist = site ->manhattanTo(player);
   			if(dist < min)
   			{
   				min = dist;
   				opti = i;
   				optj = j;
   			}
   		}
   	}

   	return (new Site(myI + opti, myJ + optj));

}
