#pragma once
#include <vector>
#include "instance.h"

bool gameLogic(std::vector<bodyPiece>& snake, direction dir) {
	bodyPiece stored;
	switch (dir)
	{
	case STOP:
		break;
	case UP:
		if (snake[0].
		stored = snake[0];
		snake[0].posY += 1;
		break;
	case LEFT:
		stored = snake[0];
		snake[0].posX -= 1;
		break;
	case DOWN:
		stored = snake[0];
		snake[0].posY -= 1;
		break;
	case RIGHT:
		stored = snake[0];
		snake[0].posX += 1;
		break;
	default:
		break;
	}
	if ()
}