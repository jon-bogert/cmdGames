#include "Player.h"

#include "Board.h"

#include<Windows.h>

Player::Player()
{
	_positions.push_back({ 5, 0 });
	_positions.push_back({ 4, 0 });
	_positions.push_back({ 3, 0 });
}

void Player::Init(Board* board)
{
	board->SetCell(_positions[0].x, _positions[0].y, _headSymbol);
	for (size_t i = 1; i < _positions.size(); ++i)
	{
		board->SetCell(_positions[i].x, _positions[i].y, _bodySymbol);
	}
}

void Player::Update(Board* board)
{
	Position next = Move(board);
	UpdateBoard(board, next);
}

void Player::CheckInput()
{
	if (GetAsyncKeyState(VK_UP) & 0x8000)
		_direction = Direction::Up;
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		_direction = Direction::Down;
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		_direction = Direction::Left;
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		_direction = Direction::Right;
}

void Player::UpdateBoard(Board* board, Position next)
{
	board->ResetCell(_positions.back().x, _positions.back().y);
	for (size_t i = _positions.size() - 2; i <= 0; --i)
	{
		_positions[i + 1] = _positions[i];
	}
	_positions[0] = next;
	board->SetCell(_positions[1].x, _positions[1].y, _bodySymbol);
	board->SetCell(_positions[0].x, _positions[0].y, _headSymbol);
}

Position Player::Move(const Board* board)
{
	Position next = _positions[0];
	switch (_direction)
	{
	case Direction::Up:
		next.y = (next.y > 0) ? next.y - 1 : 0;
		break;
	case Direction::Right:
		next.x = (next.x + 1 < board->GetWidth()) ? next.x + 1 : board->GetWidth() - 1;
		break;
	case Direction::Down:
		next.y = (next.y + 1 < board->GetHeight()) ? next.y + 1 : board->GetHeight() - 1;
		break;
	case Direction::Left:
		next.x = (next.x > 0) ? next.x - 1 : 0;
		break;
	}

	return next;
}
