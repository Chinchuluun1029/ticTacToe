/*
 * TicTacToe game
 *
 * Created by Chinchuluun Munkh-Achit. May 2019.
 * Main driver of TicTacToe and Player Classes.
 */


#include "TicTacToe.h"

//TODO: headers and comments for all methods
//TODO: write down md file
//TODO: replay option?
//TODO: make play() method and call assign and place
//todo: break down placeChars

//BUG: infinite loop when user enters string on size_t x std::cin.


int main() {

    TicTacToe game1; //Init game 1
    Player playerOne, playerTwo;
    game1.playGame(playerOne, playerTwo);

    return 0;
}



