#pragma once
#include "structs.h"
#include <stdint.h>

class Board;
class Player
{
	Board* _board = nullptr;
	Position _cursor = { 0, 0 };
	char _buffer = '.';
	uint16_t _keyState = 0;
public:
	void Init(Board* board);
	void Update(GameState& state, bool& updateBoard);

private:
	void CheckInput(GameState& state, bool& updateBoard);
	void MoveCursor(Position amt);
};