#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Visuals.h"
#include "Words.h"

#define LENGTH 5

bool isOpen = true;
bool hasWon = false;
char word[LENGTH + 1];
char used[26];
int usedIndex = 0;
char success[LENGTH + 1] = "     ";
int lives = 0;
int maxLives = 6;

void Start();
void Update();
void Draw();
void Shutdown();

int main(int argc, char* argv)
{
	Start();
	while (isOpen)
	{
		Draw();
		Update();
	}
	Shutdown();
	return 0;
}

void Start()
{
	GetRandWord(word);
}

void Update()
{
	char input = (char)getche();

	if (input < 'A' || (input > 'Z' && input < 'a') || input > 'z')
		return;

	if (input >= 'a')
		input -= 32;

	bool contains = false;
	for (int i = 0; i < LENGTH; ++i)
	{
		if (word[i] == input)
		{
			contains = true;
			success[i] = input;
		}
	}

	if (!contains)
	{
		used[usedIndex++] = input;
		++lives;
	}

	hasWon = true;
	for (int i = 0; i < LENGTH; ++i)
	{
		if (word[i] != success[i])
			hasWon = false;
	}

	if (hasWon || lives >= maxLives)
		isOpen = false;
}

void Draw()
{
	system("cls");
#ifdef _DEBUG
	printf("Word: %s\n", word);
#endif // _DEBUG
	PrintFrame(lives);
	printf("\n");
	for (int i = 0; i < LENGTH; ++i)
	{
		printf("[%c]", success[i]);
	}
	printf("\nUsed: ");
	for (int i = 0; i < usedIndex; ++i)
	{
		printf("%c ", used[i]);
	}
	printf("\n");
}

void Shutdown()
{
	Draw();
	printf("\n");
	if (hasWon)
		printf("== YOU WIN ==\n");
	else
	{
		printf("The word was: %s\n", word);
		printf("== YOU LOSE ==\n");
	}
}
