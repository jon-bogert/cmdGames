#pragma once
#include<stdint.h>
#include<vector>

struct Position;
class Board
{
	uint32_t _width = 10;
	uint32_t _height = 10;
	char _emptySymbol = '.';
	char _fruitSymbol = '#';
	uint32_t _fruitX;
	uint32_t _fruitY;

	std::vector<char> _contents;

	size_t ToIndex(uint32_t x, uint32_t y);
public:
	Board();

	void Draw();
	void SetCell(uint32_t x, uint32_t y, char symbol);
	void ResetCell(uint32_t x, uint32_t y);
	void ResetAll();

	void NewFruit(std::vector<Position>& positions);
	bool CheckFruit(const Position& pos);

	uint32_t GetWidth() const { return _width; }
	uint32_t GetHeight() const { return _height; }
};