#include <iostream>
#include <ctime>
#include <cstdlib>

struct Maze
{
	char **board;
	int rowSize;
	int colSize;
};

struct Point
{
	int x;
	int y;
};
enum Direction
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
};
struct Stack
{
	Point* pointArray;
	int index;
};


bool initMaze(Maze& maze);
void uninitMaze(Maze& maze);
void printMaze(Maze& maze);
void makePath(Maze& maze, const Point& p, Stack& s);
void swap(Point& a, Point& b);
bool checkPoint(Maze& maze, Point& point);
bool isValidPoint(const Maze& maze, const Point& p);
Point getNextPoint(const Point& current, Direction direction);

void push(Stack& s, Point& p)
{
	++s.index;
	s.pointArray[s.index] = p;
}

Point pop(Stack& s)
{
	Point p = s.pointArray[s.index];
	--s.index;
	return p;
}

int main()
{
	srand(time(NULL));

	Maze maze;
	maze.board = NULL;

	Stack s;
	s.pointArray = NULL;
	s.index = -1;

	if (initMaze(maze) == false)
	{
		return 0;
	}

	s.pointArray = new Point[maze.rowSize * maze.colSize];

	makePath(maze, { 0, 0 }, s);
	printMaze(maze);
	delete [] s.pointArray;
	uninitMaze(maze);
	return 0;
}

Point getNextPoint(const Point& current, Direction direction)
{
	Point next = current;
	switch (direction)
	{
	case UP:
		next.y -= 2;
		break;
	case DOWN:
		next.y += 2;
		break;
	case LEFT:
		next.x -= 2;
		break;
	case RIGHT:
		next.x += 2;
		break;
	}
	return next;
}

bool isValidPoint(const Maze& maze, const Point& p)
{
	return p.x >= 0 &&
		p.x < maze.colSize &&
		p.y >= 0 &&
		p.y < maze.rowSize;
}

void makePath(Maze& maze, const Point& p, Stack& s)
{
	Point current = p;
	bool nextPoint = true;
	do
	{
		if (nextPoint == true)
		{
			push(s, current);
		}
		maze.board[current.y][current.x] = ' ';
		Point nexts[4];
		for (int i = 0; i < 4; ++i)
		{
			nexts[i] = getNextPoint(current, (Direction)i);
		}

		//shuffle
		for (int i = 3; i > 0; --i)
		{
			int j = rand() % (i + 1);
			swap(nexts[i], nexts[j]);
		}
		
		nextPoint = false;
		for (int i = 0; i < 4; ++i)
		{
			if (isValidPoint(maze, nexts[i]) == true &&
				checkPoint(maze, nexts[i]) == true)
			{
				if (nexts[i].x > current.x)
				{
					maze.board[current.y][current.x + 1] = ' ';
				}
				else if (nexts[i].x < current.x)
				{
					maze.board[current.y][current.x - 1] = ' ';
				}
				else if (nexts[i].y > current.y)
				{
					maze.board[current.y + 1][current.x] = ' ';
				}
				else if (nexts[i].y < current.y)
				{
					maze.board[current.y - 1][current.x] = ' ';
				}
				current = nexts[i];
				nextPoint = true;
				break;
			}
		}
		if (nextPoint == true)
		{
			continue;
		}
		current = pop(s);
	} while (s.index >= 0);
}

bool initMaze(Maze& maze)
{
	std::cout << "Input row:" << std::endl;
	std::cin >> maze.rowSize;
	
	std::cout << "Input col:" << std::endl;
	std::cin >> maze.colSize;

	if (maze.rowSize <= 0 || maze.colSize <= 0 || maze.rowSize > 60 || maze.colSize > 60)
	{
		std::cout << "Out of range" << std::endl;
		return false;
	}

	maze.board = new char*[maze.rowSize];
	for (int i = 0; i < maze.rowSize; ++i)
	{
		maze.board[i] = new char[maze.colSize];
		memset(maze.board[i], '#', maze.colSize * sizeof(char));
	}

	return true;
}

void uninitMaze(Maze& maze)
{
	for (int i = 0; i < maze.rowSize; ++i)
	{
		if (maze.board[i] != NULL)
		{
			delete[] maze.board[i];
			maze.board[i] = NULL;
		}
	}
	if (maze.board != NULL)
	{
		delete[] maze.board;
		maze.board = NULL;
	}
}
void printMaze(Maze& maze)
{
	for (int i = 0; i < maze.rowSize; ++i)
	{
		for (int j = 0; j < maze.colSize; ++j)
		{
			std::cout << maze.board[i][j];
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void swap(Point& a, Point& b)
{
	Point temp = a;
	a = b;
	b = temp;
}

bool checkPoint(Maze& maze, Point& point)
{
	if (isValidPoint(maze, { point.x - 1, point.y }) == true &&
		maze.board[point.y][point.x - 1] == ' ')
	{
		return false;
	}
	if (isValidPoint(maze, { point.x + 1, point.y }) == true &&
		maze.board[point.y][point.x + 1] == ' ')
	{
		return false;
	}
	if (isValidPoint(maze, { point.x, point.y - 1 }) == true &&
		maze.board[point.y - 1][point.x] == ' ')
	{
		return false;
	}
	if (isValidPoint(maze, { point.x, point.y + 1 }) == true &&
		maze.board[point.y + 1][point.x] == ' ')
	{
		return false;
	}
	return true;
}