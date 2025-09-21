#include "GameOfLife.hpp"
#include <iostream>
#include <chrono>
#include <thread>
#include <cstdlib>

#ifdef _WIN32
#include <conio.h>
#else
#include <termios.h>
#include <unistd.h>

char getch() {
    char buf = 0;
    struct termios old = {0};
    if (tcgetattr(0, &old) < 0) perror("tcsetattr()");
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;
    if (tcsetattr(0, TCSANOW, &old) < 0) perror("tcsetattr ICANON");
    if (read(0, &buf, 1) < 0) perror("read()");
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if (tcsetattr(0, TCSADRAIN, &old) < 0) perror("tcsetattr ~ICANON");
    return buf;
}
#endif

int main() {
    std::cout << "Welcome to the Game of Life\n";
    std::cout << "Press any key to continue\n";
    getch();



    const int width = 80;
    const int height = 40;
    
    GameOfLife game(width, height);
    game.initialize();
    
    bool running = true;
    while (running) {
        game.render();
        
        char input = getch();
        switch (input) {
            case 'q':
                running = false;
                break;
            case 'r':
                game.initialize();
                break;
            case ' ':
                game.update();
                break;
            default:
                break;
        }
    }
    
    return 0;
}
