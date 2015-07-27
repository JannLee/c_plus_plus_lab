#include <cstdlib>
#include <ctime>
#include <iostream>


using namespace std;

const int height = 30;
const int width = 30;

char map[height][width] = { 0 };

enum Direction
{
    kUp = 0,
    kDown,
    kLeft,
    kRight,
    kMaxDirection
};

struct Position
{
    int x;
    int y;
};


int main(void)
{
    srand(time(NULL));

    int width = 0;
    int height = 0;

    memset(map, '?', sizeof(map));

    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            if (i == 0 || j == 0 || i == width - 1 || j == height - 1)
            {
                map[j][i] = "#";
            }
            else
            {
                map[j][i] = "?";
            }
        }

        cout << endl;
    }

    Position start = { 0, rand() % height };
    Position goal = { width - 1, rand() % width };
    Position current = start;

    Direction direction = kRight;

    map[current.y][current.x++] = ' ';
    map[current.y][current.x] = ' ';

    // 길 만들기
    while (x != 0 && y != 1)
    {
        if (IsDirectionEnable(current, direction))
        {

        }

    }

    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            cout << map[i][j];
        }

        cout << endl;
    }

	return 0;
}


bool IsDirectionEnable(Direction& direction, Position& position, int )
{
    switch (direction)
    {
    case kUp:

        break;
    case kDown:
        break;
    case kLeft:
        break;
    case kRight:
        break;
    }
}