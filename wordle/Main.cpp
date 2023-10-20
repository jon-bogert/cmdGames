#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <fstream>

#include "Words.h"

struct Letter
{
	char value;
	bool isInWord = false;
	bool isInPlace = false;
	Letter() = default;
	Letter(char c) : value(c), isInWord(false), isInPlace(false) {}
};

using Guess = std::vector<Letter>;

int wordLength = 5;
int guessesAmt = 7;
int currGuess = -1;
std::string word;
std::vector<Guess> guesses;
bool hasWon = false;

void Load();
void Draw();
void GetInput();
void Analize();
void End();

int main(int argc, char* argv[])
{
	Load();
	while (currGuess < guessesAmt - 1 && !hasWon)
	{
		Draw();
		GetInput();
		Analize();
		++currGuess;
	}
	End();
	return 0;
}

void Load()
{
	srand(time(NULL));
	std::vector<std::string> words;
	PopWordList(words);
	word = words[rand() % words.size()];
}

void Draw()
{
	system("cls");
#ifdef _DEBUG
	std::cout << "[DEBUG]: Word is -> " << word << std::endl;
#endif
	if (guesses.size() == 0)
	{
		for (int i = 0; i < guessesAmt; ++i)
		{
			for (int c = 0; c < wordLength; ++c)
				printf("[ ]");
			std::cout << std::endl;
		}
		return;
	}
	for (int g = 0; g <= currGuess; ++g)
	{
		for (int c = 0; c < wordLength; ++c)
		{
			if (guesses[g][c].isInPlace)
				printf("{%c}", guesses[g][c].value);
			else if(guesses[g][c].isInWord)
				printf("(%c)", guesses[g][c].value);
			else
				printf("[%c]", guesses[g][c].value);
		}
		std::cout << std::endl;
	}
	for (int i = currGuess + 1; i < guessesAmt; ++i)
	{
		for (int c = 0; c < wordLength; ++c)
			printf("[ ]");
		std::cout << std::endl;
	}
}

void GetInput()
{
	std::string input;
	while (input.length() != wordLength)
	{
		std::cout << "Enter a " << wordLength << " Letter Word: ";
		std::getline(std::cin, input);
	}

	Guess guess;
	guess.reserve(wordLength);
	for (int i = 0; i < wordLength; ++i)
	{
		if (input[i] > 90)
			input[i] -= 32;
		guess.emplace_back(input[i]);
	}
	guesses.push_back(guess);
}

void Analize()
{
	Guess& guess = guesses.back();

	for (int l = 0; l < wordLength; ++l)
	{
		if (guess[l].value == word[l])
		{
			guess[l].isInWord = true;
			guess[l].isInPlace = true;
			continue;
		}
		for (int i = 0; i < wordLength; ++i)
		{
			if (guess[l].value == word[i])
				guess[l].isInWord = true;
		}
	}

	hasWon = true;
	for (int l = 0; l < wordLength; ++l)
	{
		if (!guess[l].isInPlace)
		{
			hasWon = false;
			return;
		}
	}
}

void End()
{
	Draw();
	std::cout << std::endl << "You " << ((hasWon) ? "WIN!" : "LOSE...") << std::endl;
	std::cout << "The word was: " << word << std::endl << std::endl;
}