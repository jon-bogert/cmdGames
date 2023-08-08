#include <iostream>

#include "Board.h"
#include "Player.h"
#include "Timer.h"

const float frameTime = 0.5f;
bool isOpen = true;

int main()
{
	Board board;
	Player player;
	xe::Timer timer;
	
	player.Init(&board);
	while (isOpen)
	{
		player.CheckInput();
		if (timer.GetElapsed() >= frameTime)
		{
			timer.Reset();
			player.Update(&board);
			board.Draw();
		}
	}


	return 0;
}