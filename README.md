# A Simple Tic-Tac-Toe Game

A simple PvP game of tic-tac-toe implemented on C++. Uses 2D array as game board and 
simple characters to represent players' elements and an empty state.

### Prequisites

- To run the game, have the g++ compiler
- To edit the game, have a suitable C++ IDE or text editor

---

### Getting Started

To start the game, clone or download the repo, change current directory to repo, and run the following command on the terminal:

```c++
    $ g++ TicTacToe.cpp main.cpp -o game
    $ ./game
```

---
### Gameplay

The user is first asked to choose the character to play with, either X or O. The opposing player is
 assigned the other character. Then the players are
asked to enter x and y coordinates on the board in turn currently displayed until the game is over by winning 
or by a tie.
<br/>
#### Coordinate system:

(x, y)|(x, y)|(x, y)
--- | --- | ---
0 0 | 0 1 | 0 2
1 0 | 1 1 | 1 2
2 0 | 2 1 | 2 2


---
### Files

- main.cpp - Driver file
- Player.h - Header file defining a player's assigned char, getter and setter methods
- TicTacToe.cpp - Source file defining game's methods
- TicTacToe.h - Header file naming game's methods


---
### Author

- Chuka Munkh-Achit

---
### License 

This project is licensed under the MIT License. See LICENSE file.