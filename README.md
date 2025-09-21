# Conway's Game of Life

A console-based implementation of Conway's Game of Life written in C++.

## Building the Project

### Prerequisites
- CMake (version 3.10 or higher)
- C++ compiler with C++17 support

### Build Instructions

1. Create a build directory:
```bash
mkdir build
cd build
```

2. Generate build files:
```bash
cmake ..
```

3. Build the project:
```bash
cmake --build .
```

## Running the Game

After building, run the executable:
```bash
./game_of_life
```

## Controls
- Press `SPACE` to advance to the next generation
- Press `r` to randomize the grid
- Press `q` to quit the game

## Rules of the Game

1. Any live cell with fewer than two live neighbors dies (underpopulation)
2. Any live cell with two or three live neighbors lives on to the next generation
3. Any live cell with more than three live neighbors dies (overpopulation)
4. Any dead cell with exactly three live neighbors becomes a live cell (reproduction)

## Display
- `■` represents a live cell
- `·` represents a dead cell
