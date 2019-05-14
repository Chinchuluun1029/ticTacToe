#include <iostream>


/*
 * Player Class
 *
 * Class definition of a player in a tic-tac-toe game. Holds the chosen variable of player,
 * gets and sets that character to play
 *
 */
class Player {
    private:
        char chosenChar;
    public:
        void setChar(char input);
        char getChar();
};

/*
 * TicTacToe Class
 *
 * Class definition of tic tac toe game.
 */
class TicTacToe {
    public:

        //Constructor - builds the board with empty (-) characters
        TicTacToe() { clearBoard(); }

        void printBoard();
        void makeMove(char element, size_t x, size_t y);
        void clearBoard();
        size_t gameResult();
        char chooseChar();
        void assignChars(Player &playerOne, Player &playerTwo);
        bool isFull();
        bool isOccupied(size_t x, size_t y);
        void placeChars(Player &playerOne, Player &playerTwo);

    private:
        const static size_t BOARD_SIZE = 3;
        char board[BOARD_SIZE][BOARD_SIZE];

};


int main() {
    std::cout << "Welcome to Tic-Tac-Toe!\n" << std::endl;

    TicTacToe game1; //Init game 1
    Player playerOne, playerTwo;

    game1.assignChars(playerOne, playerTwo);
    game1.placeChars(playerOne, playerTwo);

    return 0;
}

void TicTacToe::assignChars(Player &playerOne, Player &playerTwo) {
    playerOne.setChar(chooseChar());

    if (playerOne.getChar() == 'x') {
        playerTwo.setChar('o');
    } else {
        playerTwo.setChar('x');
    }
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
                std::cout << "Coordinate is already occupied" << std::endl;
                placeChars(playerOne, playerTwo);
            }

            makeMove(playerOne.getChar(), x, y);

            if (gameResult() == 2) {
                std::cout << "Player 1 won!" << std::endl;
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
                std::cout << "Coordinate is already occupied" << std::endl;
                placeChars(playerOne, playerTwo);
                std::cin >> x;
                std::cin >> y;
                //todo: fix logic here
            }

            makeMove(playerTwo.getChar(), x, y);

            if (gameResult() == 2) {
                std::cout << "Player 2 won!" << std::endl;
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

//Player methods:

void Player::setChar(char input) { this->chosenChar = input; }
char Player::getChar() { return chosenChar; }

//TicTacToe methods:

void TicTacToe::printBoard() {
    for (size_t i = 0; i < BOARD_SIZE; ++i) {
        for (size_t j = 0; j < BOARD_SIZE; ++j) {
            std::cout << board[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}


void TicTacToe::makeMove(char element, size_t x, size_t y) {
    board[x][y] = element;
    printBoard();
}

void TicTacToe::clearBoard() {
    for (size_t i = 0; i < BOARD_SIZE; ++i) {
        for (size_t j = 0; j < BOARD_SIZE; ++j) {
            board[i][j] = '-';
        }
    }
}

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

char TicTacToe::chooseChar() {
    std::string input;
    std::cout << "X or O?" << std::endl;
    std::cin >> input;

    while ((input[0] != 'x') && (input[0] != 'X') && (input[0] != 'o') && (input[0] != 'O')) {
        std::cout << "Invalid character." << std::endl;
        std::cin >> input;
    }

    return input[0];
}

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

bool TicTacToe::isOccupied(size_t x, size_t y) {
    return (board[x][y] != '-');
}