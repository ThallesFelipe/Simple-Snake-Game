# Snake Game in C++

## Overview
This project is a simple implementation of the classic Snake game in C++. The objective of the game is to collect as many fruits as possible without colliding with the walls or the snake's own tail. The snake grows in length each time it consumes a fruit, and the score increases accordingly.

## Brief Description
This is a console-based Snake game implemented in C++. The player controls the snake to collect fruits and grow in size while avoiding collisions with its own body. The game ends if the snake collides with itself.

## Features
- Move the snake in four directions (left, right, up, down) to collect fruits.
- Avoid collisions with the snake's own body to keep playing.
- The game takes place within a bordered grid.

## Controls
- Use the following keys to control the snake:
  - `W` - Move up
  - `A` - Move left
  - `S` - Move down
  - `D` - Move right
  - `X` - Exit the game

## How to Run
To compile and run the game, follow these steps:
1. Make sure you have a C++ compiler installed, such as GCC.
2. Compile the code using the following command:
   ```
   g++ snake_game.c++ -o snake_game
   ```
3. Run the game:
   ```
   ./snake_game
   ```

## Game Logic
- The game starts with the snake in the middle of the grid.
- A fruit appears randomly on the grid, and the snake must collect it to grow in length.
- The game ends if the snake collides with its own body.
- The score increases by 10 points for each fruit collected.

## Dependencies
- `<iostream>`: For input/output stream operations.
- `<conio.h>`: Used for detecting keyboard input.
- `<windows.h>`: Used for controlling the game speed (using `Sleep()`).
- `<time.h>`: Used for generating random positions for the fruit.

## Notes
- This game uses the Windows-specific library `<conio.h>` and `<windows.h>`, so it may not be compatible with non-Windows systems without modification.
- The game board is 20x20 in size, and the snake wraps around the edges of the board if it reaches the boundary.
