#include <iostream>
#include <memory>

#include "Board.h"
#include "Player.h"

int main()
{
	std::unique_ptr<Board> board = std::make_unique<Board>();
	std::unique_ptr<Player> player = std::make_unique<Player>();

	GameState state = GameState::Playing;
	bool updateBoard = true;

	player->Init(board.get());

	while (state == GameState::Playing)
	{
		player->Update(state, updateBoard);
		if (updateBoard)
		{
			board->Draw();
			updateBoard = false;
		}
	}

}