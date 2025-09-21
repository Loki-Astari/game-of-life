#ifndef GAME_OF_LIFE_HPP
#define GAME_OF_LIFE_HPP

#include <vector>
#include <utility>

class GameOfLife {
public:
    GameOfLife(int width, int height);
    
    void initialize();
    void update();
    void render() const;
    void toggleCell(int x, int y);
    bool isAlive(int x, int y) const;
    
private:
    int countNeighbors(int x, int y) const;
    bool isValidPosition(int x, int y) const;
    void clearScreen() const;
    
    std::vector<std::vector<char>> grid;
    int width;
    int height;
};

#endif // GAME_OF_LIFE_HPP
