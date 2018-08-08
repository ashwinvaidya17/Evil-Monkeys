#ifndef SPRITE_H
#define SPRITE_H

#include "drawEngine.h"
#include "level.h"

enum
{
	SPRITE_CLASSID,
	CHARACTER_CLASSID,
	ENEMY_CLASSID,
	FIREBALL_CLASSID,
	MAGE_CLASSID
};

struct vector
{
	float x;
	float y;
};

class Sprite
{
public:
	Sprite(Level *l, DrawEngine *de, int s_index, float x = 1.0, float y = 1.0, int i_lives = 1 );
	~Sprite();
	vector getPosition(void);
	float getX(void);
	float getY(void);

	virtual void addLives(int numLives = 1);
	int getLives(void);
	bool isAlive(void);

	virtual void idleUpdate();

	virtual bool move(float x, float y);

	int classID;
protected:
	Level *level;

	DrawEngine *drawArea;
	vector pos;
	int spriteIndex;
	int numLives;

	
	vector facingDirection;

	void draw(float x, float y);
	void erase(float x, float y);

	bool isValidLevelMove(int xpos, int ypos);
};
#endif