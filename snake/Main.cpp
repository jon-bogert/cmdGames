#include <iostream>
#include <memory>
#include <ctime>

#include "Board.h"
#include "Player.h"
#include "Timer.h"

const float frameTime = 0.3f;

int main()
{
	srand(time(0));
	std::unique_ptr<Board> board = std::make_unique<Board>();
	std::unique_ptr<Player> player = std::make_unique<Player>();
	xe::Timer timer;
	
	player->Init(board.get());

	while (!player->IsGameOver())
	{
		player->CheckInput();
		if (timer.GetElapsed() >= frameTime)
		{
			timer.Reset();
			player->Update(board.get());
			board->Draw();
			std::cout << "Score:      " << player->GetScore() << std::endl;
			std::cout << "High Score: " << player->GetHighScore();
		}
	}
	player->SaveHighScore();

	std::cout << std::endl << "== GAME OVER ==" << std::endl;
	return 0;
}