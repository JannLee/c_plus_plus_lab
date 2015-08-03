#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#include <afx.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace std;

struct Maze {
	int width;
	int height;
	int **map;
};

struct Point {
	int x;
	int y;
};

void makePath(Maze& maze, Point point);
Point getNext(Maze& maze, Point point);

int main() {
	srand((unsigned int)time(NULL));

	Maze maze;
	cout << "가로 : ";
	//cin >> maze.width;
	cout << "세로 : ";
	//cin >> maze.height;
	maze.width = 60;
	maze.height = 60;

	maze.map = new int*[maze.width];
	for (int i = 0; i < maze.width; ++i)
	{
		maze.map[i] = new int[maze.height];
	}

	for (int j = 0; j < maze.height; ++j) {
		for (int i = 0; i < maze.width; ++i) {
			maze.map[i][j] = 0;
		}
	}

	Point p;
	p.x = 1;
	p.y = 1;
	maze.map[0][1] = 1;
	maze.map[maze.width - 1][maze.height - 2] = 1;
	makePath(maze, p);

	for (int j = 2; j < maze.height - 1; ++j) {
		for (int i = 2; i < maze.width - 1; ++i) {
			if (
				maze.map[i - 1][j - 1] == 1 && maze.map[i][j - 1] == 1 && maze.map[i + 1][j - 1] == 1
				&& maze.map[i - 1][j] == 1 && maze.map[i][j] == 1 && maze.map[i + 1][j] == 1
				&& maze.map[i - 1][j + 1] == 1 && maze.map[i][j + 1] == 1 && maze.map[i + 1][j + 1] == 1){
				maze.map[i][j] = 0;
			}
		}
	}

	for (int j = 0; j < maze.height; ++j) {
		for (int i = 0; i < maze.width; ++i) {
			cout << maze.map[i][j];
		}
		cout << endl;
	}

	for (int i = 0; i < maze.width; ++i)
	{
		delete[] maze.map[i];
	}
	delete[] maze.map;
	//cin.get();
	return 0;
}

void makePath(Maze& maze, Point point) {
	maze.map[point.x][point.y] = 1;

	if (point.x == maze.width - 2 && point.y == maze.height - 2) {
		return;
	}
	else {
		Point nextPoint = getNext(maze, point);
		while ((nextPoint.x < 1 || nextPoint.y < 1 || nextPoint.x >= maze.width - 1 || nextPoint.y >= maze.height - 1)) {
			nextPoint = getNext(maze, point);
		}
		makePath(maze, nextPoint);
	}
}

Point getNext(Maze& maze, Point oriPoint) {
	int direction = (rand() % 10) + 1;
	Point point = oriPoint;
	if (direction % 2 == 0) {
		if (direction > 6) {
			point.x--;
		}
		else {
			point.x++;
		}
	}
	else {
		if (direction > 6) {
			point.y--;
		}
		else {
			point.y++;
		}
	}
	return point;
}
