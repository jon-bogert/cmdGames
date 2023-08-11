#include "Board.h"
#include <iostream>

Board::Board()
{
	_playerVisual.resize(_width * _height, '.');
	_cpuVisual.resize(_width * _height, '.');
}

void Board::Init()
{
}

void Board::Draw()
{
	system("cls");
	if (_isInSetup)
	{

	}
	else
	{
		std::cout << "   == BATTLEFIELD ==          == YOUR SHIPS ==" << std::endl;
		std::cout << "  1 2 3 4 5 6 7 8 9 10      1 2 3 4 5 6 7 8 9 10" << std::endl;
		for (int y = 0; y < _height; ++y)
		{
			std::cout << static_cast<char>(y + 65) << ' ';
			//enemy
			for (int x = 0; x < _width; ++x)
			{
				std::cout << _cpuVisual[ToIndex({x, y})] << ' ';
			}
			std::cout << "      ";
			//player
			for (int x = 0; x < _width; ++x)
			{
				std::cout << _playerVisual[ToIndex({ x, y })] << ' ';
			}
			std::cout << static_cast<char>(y + 65) << ' ';
			std::cout << std::endl;
		}
	}
}

void Board::SetPositionCPU(Position pos, char c)
{
	_cpuVisual[ToIndex(pos)] = c;
}

void Board::SetPositionPlayer(Position pos, char c)
{
	_playerVisual[ToIndex(pos)] = c;
}

char Board::GetPositionCPU(Position pos) const
{
	return _cpuVisual[ToIndex(pos)];
}

char Board::GetPositionPlayer(Position pos) const
{
	return _playerVisual[ToIndex(pos)];
}

size_t Board::ToIndex(Position pos) const
{
	return pos.y * _width + pos.x;
}

