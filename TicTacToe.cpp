#include "TicTacToe.h"

#include <iostream>

/*
 * Constructor - builds the board with empty (-) characters
 */
TicTacToe::TicTacToe() { clearBoard(); }

/*
 * printBoard():
 *
 * Prints the current board with characters of both players, (x, o) and empty slots (-).
 *
 */
void TicTacToe::printBoard() {
    for (size_t i = 0; i < BOARD_SIZE; ++i) {
        for (size_t j = 0; j < BOARD_SIZE; ++j) {
            std::cout << board[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

/*
 * makeMove(char element, size_t x, size_t y):
 *
 * Given element of current player and x, y coordinates, places the char on those coordinates.
 *
 */
void TicTacToe::makeMove(char element, size_t x, size_t y) {
    board[x][y] = element;
    printBoard();
}

/*
 * clearBoard():
 *
 * Removes all x and o elements and makes all slots empty (-).
 *
 */
void TicTacToe::clearBoard() {
    for (size_t i = 0; i < BOARD_SIZE; ++i) {
        for (size_t j = 0; j < BOARD_SIZE; ++j) {
            board[i][j] = '-';
        }
    }
}

/*
 * gameResult():
 *
 * Returns a size_t indicating if the current game is won, tied or continuing.
 * A game is won when a player successfully places 3 characters horizontally, vertically or
 * diagonally on the board. If the last player to place a char has won, returns 2.
 * If the game is tied, returns 1. If the game is ongoing, returns 0.
 *
 */
size_t TicTacToe::gameResult() {

    for (size_t i = 0; i < BOARD_SIZE; ++i) {
        if (board[i][0] != '-' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 2;
        }
    }

    for (size_t i = 0; i < BOARD_SIZE; ++i) {
        if (board[0][i] != '-' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return 2;
        }
    }

    if (board[0][0] != '-' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 2;
    }

    if (board[0][2] != '-' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 2;
    }

    if (isFull()) {
        return 1;
    }

    return 0;
}

/*
 * chooseChar():
 *
 * Asks a player to choose a character of either x or o. Asks until a user inputs a suitable char
 * and returns the value.
 *
 */
char TicTacToe::chooseChar() {
    std::string input;
    std::cout << "X or O?" << std::endl;
    std::cin >> input;

    while ((input[0] != 'x') && (input[0] != 'X') && (input[0] != 'o') && (input[0] != 'O')) {
        std::cout << "Invalid character. Choose again." << std::endl;
        std::cin >> input;
    }

    return input[0];
}

/*
 * isFull():
 *
 * Returns boolean value of if the board is filled with players' chars and no empty slot is left.
 *
 */
bool TicTacToe::isFull() {
    size_t boardFull = 0;
    for (size_t i = 0; i < BOARD_SIZE; ++i) {
        for (size_t j = 0; j < BOARD_SIZE; ++j) {
            if (board[i][j] != '-') {
                ++boardFull;
            }
        }
    }

    return (boardFull == 9);
}

/*
 * isOccupied():
 *
 * Returns boolean value of it the current point at x and y parameters is occupied by player's char
 *
 */
bool TicTacToe::isOccupied(size_t x, size_t y) {
    return (board[x][y] != '-');
}


void TicTacToe::placeChars(Player &playerOne, Player &playerTwo) {
    size_t turn = 0;
    while (!isFull()) {
        size_t x, y;

        if (turn % 2 == 0) {
            std::cout << "Player 1 choose x and y: " << std::endl;

            std::cin >> x;
            while (x > 2 || x < 0) {
                std::cout << "Please enter x coordinate between 0-2" << std::endl;
                std::cin >> x;
            }

            std::cin >> y;
            while (y > 2 || y < 0) {
                std::cout << "Please enter y coordinate between 0-2" << std::endl;
                std::cin >> y;
            }

            while (isOccupied(x, y)) {
                std::cout << "Coordinate is already occupied\n" << std::endl;
                placeChars(playerOne, playerTwo);
            }

            makeMove(playerOne.getChar(), x, y);

            if (gameResult() == 2) {
                std::cout << "\nPlayer 1 won!" << std::endl;
                exit(1);
            }

        } else {
            std::cout << "Player 2 choose x and y: " << std::endl;
            std::cin >> x;
            while (x > 2 || x < 0) {
                std::cout << "Please enter x coordinate between 0-2" << std::endl;
                std::cin >> x;
            }

            std::cin >> y;
            while (y > 2 || y < 0) {
                std::cout << "Please enter y coordinate between 0-2" << std::endl;
                std::cin >> y;
            }

            while (isOccupied(x, y)) {
                std::cout << "Coordinate is already occupied\nChoose another coordinate\n";
                std::cin >> x;
                std::cin >> y;
            }

            makeMove(playerTwo.getChar(), x, y);

            if (gameResult() == 2) {
                std::cout << "\nPlayer 2 won!" << std::endl;
                exit(1);
            }
        }

        if (gameResult() == 1) {
            std::cout << "It's a tie!" << std::endl;
            exit(1);
        }

        std::cout << std::endl;

        ++turn;
    }
}

/*
 * assignChars(Player &playerOne, Player &playerTwo):
 *
 * Assigns characters of two players by asking player 1 which char to choose and assigns the
 * remaining one to player two.
 *
 */
void TicTacToe::assignChars(Player &playerOne, Player &playerTwo) {

    playerOne.setChar(chooseChar());
    (playerOne.getChar() == 'x') ? playerTwo.setChar('o') : playerTwo.setChar('x');

}



void TicTacToe::playGame(Player &playerOne, Player &playerTwo) {

    std::cout << "Welcome to Tic-Tac-Toe!\n" << std::endl;

    assignChars(playerOne, playerTwo);
    placeChars(playerOne, playerTwo);

}