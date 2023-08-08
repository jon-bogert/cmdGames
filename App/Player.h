#pragma once
#include <stdint.h>
#include <vector>

class Board;
enum class Direction { Up, Right, Down, Left, Count };

struct Position
{
	uint32_t x;
	uint32_t y;

	bool operator==(const Position& other) { return (x == other.x && y == other.y); }
};

class Player
{
	char _headSymbol = '@';
	char _bodySymbol = 'o';
	std::vector<Position> _positions;
	Direction _direction = Direction::Right;
	bool _isGameOver = false;
	size_t _score = 0;

public:
	Player();

	void Init(Board* board);
	void Update(Board* board);
	void CheckInput();

	bool IsGameOver() const { return _isGameOver; }
	size_t GetScore() const { return _score; }

private:
	Position NextPosition(const Board* board);
	bool CheckNext(Board* board, Position next);
	void Move(Board* board, Position next, bool extend);

};