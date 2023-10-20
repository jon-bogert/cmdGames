#pragma once
#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable : 4996)

void PrintFrame(int frameNum)
{
	switch (frameNum)
	{
	case 0:
		printf("|----------\n");
		printf("|         |\n|\n|\n|\n|\n");
		printf("|___________\n");
		break;
	case 1:
		printf("|----------\n");
		printf("|         |\n");
		printf("|         O\n");
		printf("|\n");
		printf("|\n");
		printf("|\n");
		printf("|___________\n");
		break;
	case 2:
		printf("|----------\n");
		printf("|         |\n");
		printf("|         O\n");
		printf("|         |\n");
		printf("|\n");
		printf("|\n");
		printf("|___________\n");
		break;
	case 3:
		printf("|----------\n");
		printf("|         |\n");
		printf("|         O\n");
		printf("|       --|\n");
		printf("|\n");
		printf("|\n");
		printf("|___________\n");
		break;
	case 4:
		printf("|----------\n");
		printf("|         |\n");
		printf("|         O\n");
		printf("|       --|--\n");
		printf("|\n");
		printf("|\n");
		printf("|___________\n");
		break;
	case 5:
		printf("|----------\n");
		printf("|         |\n");
		printf("|         O\n");
		printf("|       --|--\n");
		printf("|        /\n");
		printf("|\n");
		printf("|___________\n");
		break;
	case 6:
		printf("|----------\n");
		printf("|         |\n");
		printf("|         O\n");
		printf("|       --|--\n");
		printf("|        / \\\n");
		printf("|\n");
		printf("|___________\n");
		break;
	}
};