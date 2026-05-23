# Snake Game

Terminal Snake game written in C++ for macOS. This project keeps the original gameplay intact: the snake moves on a text-based board, eats food to grow, and ends when it collides with the wall or itself.

## Features

- Classic snake gameplay in the terminal.
- Score tracking while the snake grows.
- Countdown intro before each round.
- ASCII art board and game-over presentation.
- macOS-friendly terminal input handling.

## Requirements

- macOS
- C++17-compatible compiler
- Terminal access

## Build

From the project root, compile with:

```bash
g++ -std=c++17 main.cpp game_board.cpp food_item.cpp console_printer.cpp snake_entity.cpp keyboard_input.cpp -o snake_game
```

## Run

```bash
./snake_game
```

## Controls

- `W` to move up
- `A` to move left
- `S` to move down
- `D` to move right

## Notes

- This project uses terminal-specific input handling, so it is intended for Unix-like terminal environments.
- The gameplay logic has been preserved; only presentation and readability were cleaned up.

