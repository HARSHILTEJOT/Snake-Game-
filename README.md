# Snake Game

A simple Snake Game implemented in C++ for the Windows terminal.

## How to Run

1. Compile the code using a C++ compiler (like MinGW for Windows):
   ```bash
   g++ -o SnakeGame SnakeGame.cpp -std=c++11
   ```
2. Run the executable:
   ```bash
   SnakeGame.exe
   ```

## Controls

- `W` - Move Up
- `S` - Move Down
- `A` - Move Left
- `D` - Move Right
- `X` - Exit Game

## How the Game Works

- The player controls the snake to eat the fruit ('F').
- Every time the snake eats a fruit, it grows in length and the score increases.
- The game ends if the snake hits the wall or itself.
- There is a **difficulty selection** at the start of the game:
  - Easy
  - Medium
  - Hard
  - Each difficulty level affects the snake's speed.

## Data Structures Used

- **Arrays**:
  - `tailX[100]`, `tailY[100]` store the snake’s body.
  - `fruitX[4]`, `fruitY[4]` store multiple fruit positions.
- **Enum**:
  - `eDirection` to store movement direction.
- **Variables**:
  - `x, y` for snake’s head position.
  - `score` for tracking points.
  - `nTail` for snake length.
  - `speed` to control game difficulty.
- **Class-Based Structure**:
  - The game is implemented as a class `SnakeGame`.
  - Functions like `draw()`, `input()`, and `logic()` are encapsulated within the class.
  - The constructor initializes game settings.
  - The `run()` function manages the game loop.
 
### Contributors
-HARSHILTEJOT-(https://github.com/HARSHILTEJOT)

## Notes

This is a basic terminal-based Snake Game with enhanced features like **multiple fruits & difficulty selection.**.
