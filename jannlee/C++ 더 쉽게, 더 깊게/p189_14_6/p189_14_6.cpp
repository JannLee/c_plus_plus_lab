#include <cstdlib>
#include <ctime>
#include <iostream>


using namespace std;

enum Direction
{
    kUp = 0,
    kDown,
    kLeft,
    kRight,
    kMaxDirection
};

struct Maze
{
    char* buffer;
    int width;
    int height;
};

void InitializeMaze(Maze& maze);
void FinalizeMaze(Maze& maze);

void GetEntry(Maze& maze, int& x, int& y, Direction& direction);

void SetTile(Maze& maze, const int x, const int y, const char tile);
char GetTile(const Maze& maze, const int x, const int y);

bool IsDirectionEnable(const  Maze& maze, const int x, const int y, const Direction& direction, bool& isExitCreated);
void PrintMaze(Maze& maze);


Direction startDirection;

int main(void)
{
    Maze maze;

    srand(time(NULL));

    cout << "너비: ";
    cin >> maze.width;
    cout << "높이: ";
    cin >> maze.height;

    if (maze.width >= 3 && maze.height >= 3)
    {
        int entryX = 0;
        int entryY = 0;
        int currentX = 0;
        int currentY = 0;
        Direction direction;
        bool isExitCreated = false;

        InitializeMaze(maze);
        GetEntry(maze, entryX, entryY, direction);

        currentX = entryX;
        currentY = entryY;

        // 길 만들기
        while (isExitCreated == false || currentX != entryX && currentY != entryY)
        {
            switch (direction)
            {
            case kUp:
                if (rand() % 2 && IsDirectionEnable(maze, currentX, currentY, kLeft, isExitCreated))
                {
                    --currentX;
                    direction = kLeft;
                }
                else if (rand() % 2 && IsDirectionEnable(maze, currentX, currentY, kUp, isExitCreated))
                {
                    --currentY;
                    direction = kUp;
                }
                else if (rand() % 2 && IsDirectionEnable(maze, currentX, currentY, kRight, isExitCreated))
                {
                    ++currentX;
                    direction = kRight;
                }
                else
                {
                    ++currentY;
                    direction = kDown;
                }
                SetTile(maze, currentX, currentY, ' ');
                break;
            case kDown:
                if (rand() % 2 && IsDirectionEnable(maze, currentX, currentY, kRight, isExitCreated))
                {
                    ++currentX;
                    direction = kRight;
                }
                else if (rand() % 2 && IsDirectionEnable(maze, currentX, currentY, kDown, isExitCreated))
                {
                    ++currentY;
                    direction = kDown;
                }
                else if (rand() % 2 && IsDirectionEnable(maze, currentX, currentY, kLeft, isExitCreated))
                {
                    --currentX;
                    direction = kLeft;
                }
                else
                {
                    --currentY;
                    direction = kUp;
                }
                SetTile(maze, currentX, currentY, ' ');
                break;
            case kLeft:
                if (rand() % 2 && IsDirectionEnable(maze, currentX, currentY, kDown, isExitCreated))
                {
                    ++currentY;
                    direction = kDown;
                }
                else if (rand() % 2 && IsDirectionEnable(maze, currentX, currentY, kLeft, isExitCreated))
                {
                    --currentX;
                    direction = kLeft;
                }
                else if (rand() % 2 && IsDirectionEnable(maze, currentX, currentY, kUp, isExitCreated))
                {
                    --currentY;
                    direction = kUp;
                }
                else
                {
                    ++currentX;
                    direction = kRight;
                }
                SetTile(maze, currentX, currentY, ' ');
                break;
            case kRight:
                if (rand() % 2 && IsDirectionEnable(maze, currentX, currentY, kUp, isExitCreated))
                {
                    --currentY;
                    direction = kUp;
                }
                else if (rand() % 2 && IsDirectionEnable(maze, currentX, currentY, kRight, isExitCreated))
                {
                    ++currentX;
                    direction = kRight;
                }
                else if (rand() % 2 && IsDirectionEnable(maze, currentX, currentY, kDown, isExitCreated))
                {
                    ++currentY;
                    direction = kDown;
                }
                else
                {
                    --currentX;
                    direction = kLeft;
                }
                SetTile(maze, currentX, currentY, ' ');
                break;
            default:
                break;
            }
        }

        PrintMaze(maze);
        FinalizeMaze(maze);
    }

	return 0;
}

void InitializeMaze(Maze& maze)
{
    maze.buffer = new char[maze.width * maze.height];

    for (int iY = 0; iY < maze.height; ++iY)
    {
        for (int iX = 0; iX < maze.width; ++iX)
        {
            *(maze.buffer + iX + iY * maze.width) = '#';
        }
    }
}

void FinalizeMaze(Maze& maze)
{
    delete[] maze.buffer;
    maze.buffer = nullptr;
}

void GetEntry(Maze& maze, int& x, int& y, Direction& direction)
{
    startDirection = static_cast<Direction>(rand() % 4);
    switch (startDirection)
    {
    case kUp:
        x = rand() % (maze.width - 2) + 1;
        y = 0;
        SetTile(maze, x, y++, ' ');
        SetTile(maze, x, y, ' ');
        direction = kDown;
        break;
    case kDown:
        x = rand() % (maze.width - 2) + 1;
        y = maze.height - 1;
        SetTile(maze, x, y--, ' ');
        SetTile(maze, x, y, ' ');
        direction = kUp;
        break;
    case kLeft:
        x = 0;
        y = rand() % (maze.height - 2) + 1;
        SetTile(maze, x++, y, ' ');
        SetTile(maze, x, y, ' ');
        direction = kRight;
        break;
    case kRight:
        x = maze.width - 1;
        y = rand() % (maze.height - 2) + 1;
        SetTile(maze, x--, y, ' ');
        SetTile(maze, x, y, ' ');
        direction = kLeft;
        break;
    default:
        break;
    }

}

void SetTile(Maze& maze, const int x, const int y, char tile)
{
    *(maze.buffer + x + y * maze.width) = tile;
}

char GetTile(const Maze& maze, const int x, const int y)
{
    return *(maze.buffer + x + y * maze.width);
}

bool IsDirectionEnable(const  Maze& maze, const int x, const int y, const Direction& direction, bool& isExitCreated)
{
    bool isEnable = false;
    int nextX = 0;
    int nextY = 0;

    switch (direction)
    {
    case kUp:
        if (x != 0 && x != maze.width - 1)
        {
            nextX = x;
            nextY = y - 1;
            if (GetTile(maze, nextX, nextY) == ' ')
            {
                isEnable = true;
            }
            else if (startDirection == kDown && nextY == 0 && isExitCreated == false && GetTile(maze, nextX, nextY) != ' ')
            {
                isExitCreated = true;
                isEnable = true;
            }
            else if (nextY > 0 &&
                GetTile(maze, nextX - 1, nextY) != ' ' &&
                GetTile(maze, nextX, nextY - 1) != ' ' &&
                GetTile(maze, nextX + 1, nextY) != ' ')
            {
                isEnable = true;
            }
        }
        break;
    case kDown:
        if (x != 0 && x != maze.width - 1)
        {
            nextX = x;
            nextY = y + 1;
            if (GetTile(maze, nextX, nextY) == ' ')
            {
                isEnable = true;
            }
            else if (startDirection == kUp && nextY == maze.height - 1 && isExitCreated == false && GetTile(maze, nextX, nextY) != ' ')
            {
                isExitCreated = true;
                isEnable = true;
            }
            else if (nextY < maze.height - 1 &&
                GetTile(maze, nextX + 1, nextY) != ' ' &&
                GetTile(maze, nextX, nextY + 1) != ' ' &&
                GetTile(maze, nextX - 1, nextY) != ' ')
            {
                isEnable = true;
            }
        }
        break;
    case kLeft:
        if (y != 0 && y != maze.height - 1)
        {
            nextX = x - 1;
            nextY = y;
            if (GetTile(maze, nextX, nextY) == ' ')
            {
                isEnable = true;
            }
            else if (startDirection == kRight && nextX == 0 && isExitCreated == false && GetTile(maze, nextX, nextY) != ' ')
            {
                isExitCreated = true;
                isEnable = true;
            }
            else if (nextX > 0 &&
                GetTile(maze, nextX, nextY + 1) != ' ' &&
                GetTile(maze, nextX - 1, nextY) != ' ' &&
                GetTile(maze, nextX, nextY - 1) != ' ')
            {
                isEnable = true;
            }
        }
        break;
    case kRight:
        if (y != 0 && y != maze.height - 1)
        {
            nextX = x + 1;
            nextY = y;
            if (GetTile(maze, nextX, nextY) == ' ')
            {
                isEnable = true;
            }
            else if (startDirection == kLeft && nextX == maze.width - 1 && isExitCreated == false && GetTile(maze, nextX, nextY) != ' ')
            {
                isExitCreated = true;
                isEnable = true;
            }
            else if (nextX < maze.width - 1 &&
                GetTile(maze, nextX, nextY - 1) != ' ' &&
                GetTile(maze, nextX + 1, nextY) != ' ' &&
                GetTile(maze, nextX, nextY + 1) != ' ')
            {
                isEnable = true;
            }
        }
        break;
    default:
        break;
    }

    return isEnable;
}

void PrintMaze(Maze& maze)
{
    for (int iY = 0; iY < maze.height; ++iY)
    {
        for (int iX = 0; iX < maze.width; ++iX)
        {
            cout << *(maze.buffer + iX + maze.width * iY);
        }
        cout << endl;
    }
}