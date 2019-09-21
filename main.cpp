//
//  main.cpp
//  Tic_Tac_Toe
//
//  Created by Dorjee Gyaltsen on 9/20/19.
//  Copyright © 2019 Dorjee Gyaltsen. All rights reserved.
//

#include <iostream>
#include "TicTacToe.hpp"

using namespace std;

//Global variables
bool draw = false; //checks to see if we need to keep playing the game by the gameOver function
char turn = 'X'; // the characters of the first and second player



int main()
{
    
    Game tictactoe;
    
    tictactoe.displayBoard(); //calls the function to display the board
    tictactoe.player_turn(); //function calls the turn
    
    while (tictactoe.game_Over()) //while being true it will keep displaying the board since the game is still goin on, when it turns false it will stop and display a message on the console either you won or drew.
    {
        tictactoe.displayBoard();
        tictactoe.player_turn();
        
        
        tictactoe.check();
        
       /* if (turn == 'X' && draw == false)
            cout << "Player1 [O] Wins" << endl;
        else if (turn == 'O' && draw == false)
            cout << "Player2 [X] Wins" << endl;
        else
            cout << "DRAW GAME" << endl;
        */
        
        
    }
}
