#pragma once

enum class GameState {Playing, Win, Lose, Exit};

struct Position
{
	int x;
	int y;

	Position operator+(const Position& other) { return { x + other.x, y + other.y }; }
	void operator+=(const Position& other) { x += other.x; y += other.y; }
};