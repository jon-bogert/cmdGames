#include "Player.h"

#include "Board.h"

#include<Windows.h>
#include <iostream>

Player::Player()
{
	_positions.push_back({ 5, 0 });
	_positions.push_back({ 4, 0 });
	_positions.push_back({ 3, 0 });
	_positions.push_back({ 2, 0 });
	_positions.push_back({ 1, 0 });
	_positions.push_back({ 0, 0 });
}

void Player::Init(Board* board)
{
	board->SetCell(_positions[0].x, _positions[0].y, _headSymbol);
	for (size_t i = 1; i < _positions.size(); ++i)
	{
		board->SetCell(_positions[i].x, _positions[i].y, _bodySymbol);
	}

	board->NewFruit(_positions);
}

void Player::Update(Board* board)
{
	Position next = NextPosition(board);
	bool extend = CheckNext(board, next);
	Move(board, next, extend);
}

void Player::CheckInput()
{
	if (GetAsyncKeyState(VK_UP) & 0x8000)
		_direction = Direction::Up;
	else if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		_direction = Direction::Down;
	else if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		_direction = Direction::Left;
	else if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		_direction = Direction::Right;
}

void Player::Move(Board* board, Position next, bool extend)
{
	if (_isGameOver)
		return;

	Position tmp;
	if (extend)
		tmp = _positions.back();
	else
		board->ResetCell(_positions.back().x, _positions.back().y);

	for (size_t i = _positions.size() - 2; i > 0; --i)
	{
		_positions[i + 1] = _positions[i];
	}
	_positions[1] = _positions[0];
	_positions[0] = next;
	board->SetCell(_positions[1].x, _positions[1].y, _bodySymbol);
	board->SetCell(_positions[0].x, _positions[0].y, _headSymbol);

	if (extend)
		_positions.push_back(tmp);
}

bool Player::CheckNext(Board* board, Position next)
{
	//Check collision with self
	for (size_t i = 0; i < _positions.size() - 1; ++i) // last is discarded
	{
		if (_positions[i] == next)
		{
			_isGameOver = true;
			return false;
		}
	}

	//check collision with fruit
	if (board->CheckFruit(next))
	{
		board->NewFruit(_positions);
		++_score;
		return true;
	}
	return false;
}

Position Player::NextPosition(const Board* board)
{
	Position next = _positions[0];
	switch (_direction)
	{
	case Direction::Up:
		if (next.y <= 0)
		{
			_isGameOver = true;
			return next;
		}
		next.y -= 1;
		break;
	case Direction::Right:
		if (next.x >= board->GetWidth() - 1)
		{
			_isGameOver = true;
			return next;
		}
		next.x += 1;
		break;
	case Direction::Down:
		if (next.y >= board->GetHeight() - 1)
		{
			_isGameOver = true;
			return next;
		}
		next.y += 1;
		break;
	case Direction::Left:
		if (next.x <= 0)
		{
			_isGameOver = true;
			return next;
		}
		next.x -= 1;
		break;
	default:
		std::cout << "[ERROR] direction enum not supported" << std::endl;
		break;
	}

	return next;
}
