#include "Board.h"
#include <iostream>

size_t Board::ToIndex(uint32_t x, uint32_t y)
{
	return y * _width + x;
}

Board::Board()
{
	_contents.resize(_width * _height, _emptySymbol);
}

void Board::Draw()
{
	system("cls");
	for (uint32_t y = 0; y < _height; ++y)
	{
		for (uint32_t x = 0; x < _width; ++x)
		{
			std::cout << _contents[y * _width + x] << ' ';
		}
		std::cout << std::endl;
	}
}

void Board::SetCell(uint32_t x, uint32_t y, char symbol)
{
	_contents[ToIndex(x, y)] = symbol;
}

void Board::ResetCell(uint32_t x, uint32_t y)
{
	_contents[ToIndex(x, y)] = _emptySymbol;
}
