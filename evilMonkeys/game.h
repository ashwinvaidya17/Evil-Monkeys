#ifndef GAME_H
#define GAME_H

#include "drawEngine.h"
#include "character.h"
#include "level.h"
#include "mage.h"

class Game
{
public :
	bool run(void);

protected:
	bool getInput(char *c);
	void timerUpdate(void);

private:
	Level *level;
	Mage *player;
	float frameCount;
	double startTime;
	double lastTime;

	DrawEngine drawArea;
};

#endif