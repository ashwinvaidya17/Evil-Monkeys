#include "game.h"

#include<windows.h>
#include <iostream>
#include <conio.h>

using namespace std;

//this is going to give us 30 fps
#define GAME_SPEED 33.3333

bool Game::run(void)
{
	level = new Level(&drawArea, 30, 20);

	drawArea.createBackgroundTile(TILE_EMPTY, ' ');
	drawArea.createBackgroundTile(TILE_WALL, 219);

	drawArea.createSprite(SPRITE_PLAYER, 2);
	drawArea.createSprite(SPRITE_ENEMY, '$');
	drawArea.createSprite(SPRITE_FIREBALL, '*');

	player = new Mage(level, &drawArea, 0);

	level->draw();
	level->addPlayer(player);
	level->addEnemies(3);

	char key =  ' ';
	startTime = timeGetTime();
	frameCount = 0;
	lastTime = 0;

	player->move(0, 0);

	while (key != 'q')
	{
		while(!getInput(&key))
		{
			timerUpdate();
		}
		level->keyPress(key);
	}

	delete player;

	return true;
}

bool Game::getInput(char *c)
{
	if(kbhit())
	{
		*c = getch();
		return true;
	}
	return false;
}

void Game::timerUpdate(void)
{
	double currentTime = timeGetTime() - lastTime;
	if(currentTime < GAME_SPEED)
		return;

	level->update();
	frameCount++;
	lastTime = timeGetTime();
}