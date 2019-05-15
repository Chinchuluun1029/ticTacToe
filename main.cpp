#include <iostream>
#include "TicTacToe.h"

//TODO: headers and comments for all methods
//TODO: replay option?


int main() {
    std::cout << "Welcome to Tic-Tac-Toe!\n" << std::endl;

    TicTacToe game1; //Init game 1
    Player playerOne, playerTwo;

    game1.assignChars(playerOne, playerTwo);
    game1.placeChars(playerOne, playerTwo);


    return 0;
}



