#include <iostream>
#include <conio.h>
#include <windows.h>
#include <time.h>

using namespace std;

bool game_over;

const short width{20};
const short height{20};

short x, y, fruit_x, fruit_y, score;
short tail_x[100], tail_y[100];
short length_tail;

enum e_direction
{
    STOP = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN
};
e_direction direction;

void setup()
{
    srand(time(NULL));

    game_over = false;

    direction = STOP;
    x = width / 2;
    y = height / 2;

    fruit_x = rand() % width;
    fruit_y = rand() % height;

    score = 0;

    length_tail = 0;
};

void draw()
{
    system("cls");

    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << '\n';

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0)
                cout << "#";

            if (i == y && j == x)
                if (direction == LEFT)
                    cout << "<";
                else if (direction == RIGHT)
                    cout << ">";
                else if (direction == UP)
                    cout << "A";
                else if (direction == DOWN)
                    cout << "v";
                else
                    cout << "O";

            else if (i == fruit_y && j == fruit_x)
                cout << "F";
            else
            {
                bool print = false;
                for (int k = 0; k < length_tail; k++)
                {
                    if (tail_x[k] == j && tail_y[k] == i)
                    {
                        cout << "o";
                        print = true;
                    };
                };
                if (!print)
                    cout << " ";
            };

            if (j == width - 1)
                cout << "#";
        };
        cout << '\n';
    };

    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << '\n';

    cout << "Score: " << score << '\n';
};

void input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'a':
            if (direction != RIGHT)
                direction = LEFT;
            break;
        case 'd':
            if (direction != LEFT)
                direction = RIGHT;
            break;
        case 'w':
            if (direction != DOWN)
                direction = UP;
            break;
        case 's':
            if (direction != UP)
                direction = DOWN;
            break;
        case 'x':
            game_over = true;
            break;
        default:
            break;
        };
    };
};

void logic()
{
    short previous_x = tail_x[0];
    short previous_y = tail_y[0];
    short previous_x2, previous_y2;

    tail_x[0] = x;
    tail_y[0] = y;

    for (int i = 1; i < length_tail; i++)
    {
        previous_x2 = tail_x[i];
        previous_y2 = tail_y[i];

        tail_x[i] = previous_x;
        tail_y[i] = previous_y;

        previous_x = previous_x2;
        previous_y = previous_y2;
    };

    switch (direction)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    };

    if (x >= width)
        x = 0;
    else if (x < 0)
        x = width - 1;
    if (y >= height)
        y = 0;
    else if (y < 0)
        y = height - 1;

    for (int i = 0; i < length_tail; i++)
        if (tail_x[i] == x && tail_y[i] == y)
            game_over = true;

    if (x == fruit_x && y == fruit_y)
    {
        score += 10;
        fruit_x = rand() % width;
        fruit_y = rand() % height;
        length_tail++;
    };
};

int main()
{
    setup();

    while (!game_over)
    {
        draw();
        input();
        logic();
        Sleep(150);
    };

    return 0;
};