//
//  TicTacToe.hpp
//  Tic_Tac_Toe
//
//  Created by Dorjee Gyaltsen on 9/20/19.
//  Copyright © 2019 Dorjee Gyaltsen. All rights reserved.
//

#ifndef TicTacToe_hpp
#define TicTacToe_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

class Game
{
public:
    Game(); // default constructor
    
    void displayBoard();
    void player_turn();
    bool game_Over();
    void check();
    
private:
    
    int choice; // user input
    char board [3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}}; //2d array for the display board
    int row, column; // for the board
    bool draw = false; //checks to see if we need to keep playing the game by the gameOver function
    char turn = 'X'; // the characters of the first and second player


    
};

#endif /* TicTacToe_hpp */
