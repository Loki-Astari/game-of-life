#include "GameOfLife.hpp"
#include <iostream>
#include <random>
#include <chrono>
#include <thread>

#ifdef _WIN32
#include <windows.h>
#else
#include <cstdlib>
#endif

GameOfLife::GameOfLife(int width, int height) 
    : width(width), height(height) {
    grid.resize(height, std::vector<char>(width, '0'));
}

void GameOfLife::initialize() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 1);
    
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            grid[y][x] = dis(gen) == 1 ? '1' : '0';
        }
    }
}

void GameOfLife::update() {
    std::vector<std::vector<char>> newGrid = grid;
    
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int neighbors = countNeighbors(x, y);
            bool currentCell = (grid[y][x] == '1');
            
            if (currentCell) {
                // Any live cell with fewer than 2 or more than 3 live neighbors dies
                newGrid[y][x] = (neighbors == 2 || neighbors == 3) ? '1' : '0';
            } else {
                // Any dead cell with exactly 3 live neighbors becomes alive
                newGrid[y][x] = (neighbors == 3) ? '1' : '0';
            }
        }
    }
    
    grid = std::move(newGrid);
}

void GameOfLife::render() const {
    clearScreen();
    
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            std::cout << (grid[y][x] == '1' ? "O " : ". ");
        }
        std::cout << '\n';
    }
    std::cout << "\nPress 'q' to quit, 'r' to randomize, or space to step through generations Martin\n";
}

void GameOfLife::toggleCell(int x, int y) {
    if (isValidPosition(x, y)) {
        grid[y][x] = (grid[y][x] == '1') ? '0' : '1';
    }
}

bool GameOfLife::isAlive(int x, int y) const {
    return isValidPosition(x, y) && grid[y][x] == '1';
}

int GameOfLife::countNeighbors(int x, int y) const {
    int count = 0;
    
    for (int dy = -1; dy <= 1; ++dy) {
        for (int dx = -1; dx <= 1; ++dx) {
            if (dx == 0 && dy == 0) continue;
            
            int newX = x + dx;
            int newY = y + dy;
            
            if (isValidPosition(newX, newY) && grid[newY][newX] == '1') {
                count++;
            }
        }
    }
    
    return count;
}

bool GameOfLife::isValidPosition(int x, int y) const {
    return x >= 0 && x < width && y >= 0 && y < height;
}

void GameOfLife::clearScreen() const {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}