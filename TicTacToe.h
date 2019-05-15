//
// Created by Marla Munkh-Achit on 2019-05-15.
//

#ifndef TICTACTOE_TICTACTOE_H
#define TICTACTOE_TICTACTOE_H

#include "Player.h"
#include <stddef.h>

/*
 * TicTacToe Class
 *
 * Class definition of tic tac toe game. Has private fields of BOARD_SIZE,
 * and a two-dimensional array of board size. Currently only playable on 3 by 3 board.
 *
 */
class TicTacToe {

private:

    const static size_t BOARD_SIZE = 3; //Const variable of one length/size
    char board[BOARD_SIZE][BOARD_SIZE];

public:

    //Constructor - builds the board with empty (-) characters
    TicTacToe();

    /*
    * printBoard():
    *
    * Prints the current board with characters of both players, (x, o) and empty slots (-).
    *
    */
    void printBoard();

    /*
    * makeMove(char element, size_t x, size_t y):
    *
    * Given char of current player and x, y coordinates, places char on those coordinates.
    *
    */
    void makeMove(char element, size_t x, size_t y);

    /*
    * clearBoard():
    *
    * Removes all x and o elements and makes all slots empty (-).
    *
    */
    void clearBoard();

    /*
    * gameResult():
    *
    * Returns a size_t indicating if the current game is won, tied or continuing.
    * A game is won when a player successfully places 3 characters horizontally, vertically or
    * diagonally on the board. If the last player to place a char has won, returns 2.
    * If the game is tied, returns 1. If the game is ongoing, returns 0.
    *
    */
    size_t gameResult();

    /*
    * chooseChar():
    *
    * Asks a player to choose a character of either x or o. Asks until a user inputs a suitable char
    * and returns the value.
    *
    */
    char chooseChar();

    /*
    * isFull():
    *
    * Returns boolean value of if the board is filled with players' chars and no empty slot is left.
    *
    */
    bool isFull();

    /*
    * isOccupied():
    *
    * Returns boolean value of it the current point at x and y parameters is occupied by player's char
    *
    */
    bool isOccupied(size_t x, size_t y);


    void placeChars(Player &playerOne, Player &playerTwo);


    void assignChars(Player &playerOne, Player &playerTwo);



};


#endif //TICTACTOE_TICTACTOE_H
