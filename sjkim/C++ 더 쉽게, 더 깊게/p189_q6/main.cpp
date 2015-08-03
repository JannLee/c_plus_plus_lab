#include <iostream>
#include <ctime>
#include <cstdlib>
#include <clocale>

using namespace std;

#define MAX_WIDTH 60
#define MAX_HEIGHT 60
#define BRANCH_RATE 5

#define EMPTY_CELL '\0'
#define CELL_1 L'─'
#define CELL_2 L'│'
#define CELL_3 L'┌'
#define CELL_4 L'┐'
#define CELL_5 L'└'
#define CELL_6 L'┘'
#define CELL_7 L'├'
#define CELL_8 L'┤'
#define CELL_9 L'┬'
#define CELL_10 L'┴'
#define CELL_11 L'┼'

#define ROUTE_RIGHT L'0'
#define ROUTE_DOWN L'1'
#define ROUTE_LEFT L'2'
#define ROUTE_UP L'3'

wchar_t GetRouteNode(int direction, int lastDirection);
bool MakeRoute(wchar_t board[MAX_WIDTH + 1][MAX_HEIGHT + 1], int width, int height);
void DecideRoutes(wchar_t board[MAX_WIDTH + 1][MAX_HEIGHT + 1], int width, int height);
void MakeBranch(wchar_t board[MAX_WIDTH + 1][MAX_HEIGHT + 1], int width, int height, int startRow, int startColumn);
wchar_t GetRandCell();
void PrintMaze(wchar_t board[MAX_WIDTH + 1][MAX_HEIGHT + 1], int width, int height);

int main(int argc, char* argv[])
{
	wchar_t board[MAX_WIDTH + 1][MAX_HEIGHT + 1];
	int width = 0;
	int height = 0;

	if (argc != 3)
	{
		cout << "Usage : " << argv[0] << " width height" << endl;
		return -1;
	}

	setlocale(LC_ALL, "");
	srand(time(NULL));

	width = atoi(argv[1]);
	height = atoi(argv[2]);

	while (!MakeRoute(board, width, height))
	{
	}

	DecideRoutes(board, width, height);
	PrintMaze(board, width, height);

	return 0;
}

wchar_t GetRouteNode(int direction, int lastDirection)
{
	switch (direction)
	{
	case ROUTE_RIGHT:
		switch (lastDirection)
		{
		case ROUTE_RIGHT:
			return CELL_1;
		case ROUTE_DOWN:
			return CELL_5;
		case ROUTE_UP:
			return CELL_3;
		}
	case ROUTE_DOWN:
		switch (lastDirection)
		{
		case ROUTE_RIGHT:
			return CELL_4;
		case ROUTE_DOWN:
			return CELL_2;
		case ROUTE_LEFT:
			return CELL_3;
		}
	case ROUTE_LEFT:
		switch (lastDirection)
		{
		case ROUTE_DOWN:
			return CELL_6;
		case ROUTE_LEFT:
			return CELL_1;
		case ROUTE_UP:
			return CELL_4;
		}
	case ROUTE_UP:
		switch (lastDirection)
		{
		case ROUTE_RIGHT:
			return CELL_6;
		case ROUTE_LEFT:
			return CELL_5;
		case ROUTE_UP:
			return CELL_2;
		}
	}
}

bool MakeRoute(wchar_t board[MAX_WIDTH + 1][MAX_HEIGHT + 1], int width, int height)
{
	int row = 0;
	int column = 0;
	int direction = 0;

	for (row = 0; row < MAX_HEIGHT + 1; ++row)
	{
		for (column = 0; column < MAX_WIDTH + 1; ++column)
		{
			board[row][column] = EMPTY_CELL;
		}
	}

	row = 0;
	column = 0;

	while (row != height - 1 || column != width - 1)
	{
		int directionLoop = 0;
		bool directionLoopResult = false;
		direction = rand() % 4;
		directionLoop = direction;
		do
		{
			switch (directionLoop)
			{
			case 0:
				if (column < width - 1)
				{
					if (board[row][column + 1] == EMPTY_CELL)
					{
						board[row][column] = ROUTE_RIGHT;
						++column;
						directionLoopResult = true;
					}
				}
				break;
			case 1:
				if (row < height - 1)
				{
					if (board[row + 1][column] == EMPTY_CELL)
					{
						board[row][column] = ROUTE_DOWN;
						++row;
						directionLoopResult = true;
					}
				}
				break;
			case 2:
				if (column > 0)
				{
					if (board[row][column - 1] == EMPTY_CELL)
					{
						board[row][column] = ROUTE_LEFT;
						--column;
						directionLoopResult = true;
					}
				}
				break;
			case 3:
				if (row > 0)
				{
					if (board[row - 1][column] == EMPTY_CELL)
					{
						board[row][column] = ROUTE_UP;
						--row;
						directionLoopResult = true;
					}
				}
				break;
			default:
				return false;
			}
			directionLoop = ++directionLoop % 4;
		} while (directionLoop != direction && !directionLoopResult);

		if (!directionLoopResult)
		{
			return false;
		}
	}

	board[height - 1][width - 1] = CELL_10;

	return true;
}

void DecideRoutes(wchar_t board[MAX_WIDTH + 1][MAX_HEIGHT + 1], int width, int height)
{
	int row = 0;
	int column = 0;
	wchar_t lastDirection = ROUTE_RIGHT;
	int direction = 0;

	while (row != height - 1 || column != width - 1)
	{
		bool isBranch = false;
		direction = board[row][column];
		if (rand() % BRANCH_RATE == 0)
		{
			isBranch = true;
			MakeBranch(board, width, height, row, column);
		}
		
		switch (direction)
		{
		case ROUTE_RIGHT:
			board[row][column] = isBranch ? CELL_11 : GetRouteNode(ROUTE_RIGHT, lastDirection);
			++column;
			break;
		case ROUTE_DOWN:
			board[row][column] = isBranch ? CELL_11 : GetRouteNode(ROUTE_DOWN, lastDirection);
			++row;
			break;
		case ROUTE_LEFT:
			board[row][column] = isBranch ? CELL_11 : GetRouteNode(ROUTE_LEFT, lastDirection);
			--column;
			break;
		case ROUTE_UP:
			board[row][column] = isBranch ? CELL_11 : GetRouteNode(ROUTE_UP, lastDirection);
			--row;
			break;
		}
		lastDirection = direction;
	}
}

void MakeBranch(wchar_t board[MAX_WIDTH + 1][MAX_HEIGHT + 1], int width, int height, int startRow, int startColumn)
{
	int row = startRow;
	int column = startColumn;
	int direction = 0;
	int lastDirection = 0;

	while (row != height - 1 || column != width - 1)
	{
		int directionLoop = 0;
		bool directionLoopResult = false;
		direction = rand() % 4;
		directionLoop = direction;
		do
		{
			switch (directionLoop)
			{
			case 0:
				if (column < width - 1)
				{
					if (board[row][column + 1] == EMPTY_CELL)
					{
						board[row][column + 1] = CELL_8;
						++column;
						directionLoopResult = true;
					}
				}
				break;
			case 1:
				if (row < height - 1)
				{
					if (board[row + 1][column] == EMPTY_CELL)
					{
						board[row + 1][column] = CELL_7;
						++row;
						directionLoopResult = true;
					}
				}
				break;
			case 2:
				if (column > 0)
				{
					if (board[row][column - 1] == EMPTY_CELL)
					{
						board[row][column - 1] = CELL_9;
						--column;
						directionLoopResult = true;
					}
				}
				break;
			case 3:
				if (row > 0)
				{
					if (board[row - 1][column] == EMPTY_CELL)
					{
						board[row - 1][column] = CELL_10;
						--row;
						directionLoopResult = true;
					}
				}
				break;
			}
			directionLoop = ++directionLoop % 4;
		} while (directionLoop != direction && !directionLoopResult);

		if (!directionLoopResult)
		{
			break;
		}
		lastDirection = directionLoop;
	}
}

wchar_t GetRandCell()
{
	wchar_t result = 0;

	switch (rand() % 5)
	{
	case 0:
		result = CELL_7;
		break;
	case 1:
		result = CELL_8;
		break;
	case 2:
		result = CELL_9;
		break;
	case 3:
		result = CELL_10;
		break;
	case 4:
		result = CELL_11;
		break;
	}

	return result;
}

void PrintMaze(wchar_t board[MAX_WIDTH + 1][MAX_HEIGHT + 1], int width, int height)
{
	int row = 0;
	int column = 0;

	for (row = 0; row < height; ++row)
	{
		for (column = 0; column < width; ++column)
		{
			if (board[row][column] == EMPTY_CELL)
			{
				board[row][column] = GetRandCell();
			}
		}
	}

	for (row = 0; row < height; ++row)
	{
		wcout << board[row] << endl;
	}
}
