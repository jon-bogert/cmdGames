#pragma once
#include <stdint.h>
#include <vector>

class Board;
enum class Direction { Up, Right, Down, Left, Count };

struct Position
{
	uint32_t x;
	uint32_t y;
};

class Player
{
	char _headSymbol = '@';
	char _bodySymbol = 'o';
	std::vector<Position> _positions;
	Direction _direction = Direction::Right;

public:
	Player();

	void Init(Board* board);
	void Update(Board* board);
	void CheckInput();

private:
	Position Move(const Board* board);
	void UpdateBoard(Board* board, Position next);

};