/*************************************************************************//**
 * @file 
 *
 *****************************************************************************/

#include <vector>
#include "player.h"

using namespace std;

/**************************************************************************//**
 * @author Ryan Hinrichs
 *
 * @par Description:
 * Player constructor
 *
 *****************************************************************************/

Player::Player(Playfield* p)
{
   playfield = p;
   N = playfield->size();
}

/**************************************************************************//**
 * @author Ryan Hinrichs
 *
 * @par Description:
 * Movement function for the player  He looks in every direction and goes
 * away from the monster in the direction that is the most applicable.
 *
 *****************************************************************************/

Site* Player::move()
{
   Site* monster   = playfield->getMonsterSite();
   Site* player = playfield->getPlayerSite();
   int myI = player->i();
   int myJ = player->j();

   int max = 0;
   int dist = 0;
   int opti = 0;
   int optj = 0;

   for(int i = -1; i < 2; i++)
   	for(int j = -1; j < 2; j++)
   	{
   		Site *site = new Site(myI + i, myJ + j);
   		if(playfield->isLegalMove(player, site))
   		{
   			dist = site ->manhattanTo(monster);
   			if(dist > max)
   			{
   				max = dist;
   				opti = i;
   				optj = j;
   			}
   		}
   	}

   	return (new Site(myI + opti, myJ + optj));
}
