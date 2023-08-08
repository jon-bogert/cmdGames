#include "Board.h"
#include <iostream>
#include "Player.h"
#include <ctime>

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

void Board::ResetAll()
{
	for (char& c : _contents)
		c = _emptySymbol;
}

void Board::NewFruit(std::vector<Position>& positions)
{
	Position newFruit;
	bool isValid = false;
	while (!isValid)
	{
		newFruit.x = rand() % _width;
		newFruit.y = rand() % _height;
		isValid = true;
		for (Position& p : positions)
		{
			if (newFruit.x == _fruitX && newFruit.y == _fruitY) // same as last fruit
				isValid = false;
			if (p == newFruit) // is on a player position
				isValid = false;
		}
	}
	_fruitX = newFruit.x;
	_fruitY = newFruit.y;

	_contents[ToIndex(_fruitX, _fruitY)] = _fruitSymbol;
}

bool Board::CheckFruit(const Position& pos)
{
	return (pos.x == _fruitX && pos.y == _fruitY);
}
