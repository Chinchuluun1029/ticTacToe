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
    void setChar(char input) { this->chosenChar = input;}
    char getChar() { return chosenChar; }
};
