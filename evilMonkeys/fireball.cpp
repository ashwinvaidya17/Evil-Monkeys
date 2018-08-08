#include "fireball.h"

Fireball::Fireball(Level *lev, DrawEngine *de, int s_index, float x, float y, float xDir, float yDir, int i_lives)
	: Sprite(lev, de, s_index, x, y, i_lives)
{
	facingDirection.x = xDir;
	facingDirection.y = yDir;

	classID = FIREBALL_CLASSID;
}

void Fireball::idleUpdate(void)
{
	if(Sprite::move(facingDirection.x, facingDirection.y))
	{
		list <Sprite *>::iterator Iter;
		for(Iter = level->npc.begin(); Iter != level->npc.end(); Iter++)
		{
			if((*Iter)->classID != classID && (int)(*Iter)->getX() == (int)pos.x && (int)(*Iter)->getY() == (int)pos.x)
			{
				(*Iter)->addLives(-1);
				addLives(-1);
			}
		}
	}
	else
		addLives(-1);
}