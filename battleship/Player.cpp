#include "Player.h"
#include <Windows.h>
#include "Board.h"

#define KEY_UP 0x0001
#define KEY_DOWN 0x0002
#define KEY_LEFT 0x0004
#define KEY_RIGHT 0x0008
#define KEY_ENTER 0x0010

void Player::Init(Board* board)
{
	_board = board;
	_board->SetPositionCPU(_cursor, '+');
}

void Player::Update(GameState& state, bool& updateBoard)
{
	CheckInput(state, updateBoard);
}

void Player::CheckInput(GameState& state, bool& updateBoard)
{
	if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
	{
		state = GameState::Exit;
	}

	//----- Down Events
	//Get Current State
	uint16_t newKeyState = 0;
	if (GetAsyncKeyState(VK_UP) & 0x8000)
		newKeyState |= KEY_UP;
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		newKeyState |= KEY_DOWN;
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		newKeyState |= KEY_LEFT;
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		newKeyState |= KEY_RIGHT;
	if (GetAsyncKeyState(VK_RETURN) & 0x8000)
		newKeyState |= KEY_ENTER;

	//Calculate Down Event mask
	uint16_t keyDownEvent = newKeyState & ~_keyState;
	_keyState = newKeyState;

	//Check inputs
	if (keyDownEvent & KEY_UP)
	{
		MoveCursor({ 0, -1 });
		updateBoard = true;
	}
	else if (keyDownEvent & KEY_DOWN)
	{
		MoveCursor({ 0, 1 });
		updateBoard = true;
	}
	else if (keyDownEvent & KEY_LEFT)
	{
		MoveCursor({ -1, 0 });
		updateBoard = true;
	}
	else if (keyDownEvent & KEY_RIGHT)
	{
		MoveCursor({ 1, 0 });
		updateBoard = true;
	}
}

void Player::MoveCursor(Position amt)
{
	_board->SetPositionCPU(_cursor, _buffer);
	_cursor += amt;
	_buffer = _board->GetPositionCPU(_cursor);
	_board->SetPositionCPU(_cursor, '+');
}
