#pragma once
#include<stdint.h>
#include<vector>

class Board
{
	uint32_t _width = 16;
	uint32_t _height = 16;
	char _emptySymbol = '+';

	std::vector<char> _contents;

	size_t ToIndex(uint32_t x, uint32_t y);
public:
	Board();

	void Draw();
	void SetCell(uint32_t x, uint32_t y, char symbol);
	void ResetCell(uint32_t x, uint32_t y);

	uint32_t GetWidth() const { return _width; }
	uint32_t GetHeight() const { return _height; }
};