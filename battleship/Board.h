#pragma once
#include <vector>
#include "structs.h"

struct Ships
{
	Position carrier[5];
	Position battleship[4];
	Position submarine[3];
	Position destroyer[3];
	Position cruiser[2];
};

class Board
{
	int _boardGap = 3;
	int _width = 10;
	int _height = 10;
	std::vector<char> _playerVisual;
	std::vector<char> _cpuVisual;
	Ships _playerShips;
	Ships _cpuShips;
	bool _isInSetup = true;

public:
	Board();

	void Init();
	void Draw();

	void SetPositionCPU(Position pos, char c);
	void SetPositionPlayer(Position pos, char c);
	char GetPositionCPU(Position pos) const;
	char GetPositionPlayer(Position pos) const;

private:
	size_t ToIndex(Position pos) const;

};