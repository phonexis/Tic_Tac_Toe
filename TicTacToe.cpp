//
//  TicTacToe.cpp
//  Tic_Tac_Toe
//
//  Created by Dorjee Gyaltsen on 9/20/19.
//  Copyright © 2019 Dorjee Gyaltsen. All rights reserved.
//

#include "TicTacToe.hpp"
#include <iostream>

using namespace std;

Game::Game()
{}

void Game::displayBoard()
{
    system("cls");
    
    cout << " T i c  T a c  T o e  G a m e  " << endl;
    cout << "Player1 [X] " << endl;
    cout << "Player2 [O] " << endl;
    
    cout << "     |     |     \n";
    cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "  \n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "  \n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "  \n";
    cout << "     |     |     \n";
}

void Game::player_turn() // Two player X or O; player 1 or 2;
{
    if (turn == 'X')
        cout << "Player1 [X] turn: ";
    
    if (turn == 'O')
        cout << "Player1 [O] turn: ";
    
    cin >> choice;
    
    
    switch(choice) //For each cases it changes the number to the coressponding X or O
    {
        case 1:
            row = 0; column = 0; break;
        case 2:
            row = 0; column = 1; break;
        case 3:
            row = 0; column = 2; break;
        case 4:
            row = 1; column = 0; break;
        case 5:
            row = 1; column = 1; break;
        case 6:
            row = 1; column = 2; break;
        case 7:
            row = 2; column = 0; break;
        case 8:
            row = 2; column = 1; break;
        case 9:
            row = 2; column = 2; break;
            
        default:
            cout << "Invalid Choice " << endl; // Error message for choices other than numbers
            break;
    }
    
    if (turn == 'X' && board[row][column] != 'X' && board[row][column] != '0')
    {
        board[row][column] = 'X';
        turn = 'O';
    }
    else if (turn == 'O' && board[row][column] != 'X' && board[row][column] != '0')
    {
        board[row][column] = 'O';
        turn = 'X';
    }
    else
    {
        cout << "Position already taken. PLease try again" << endl;
        player_turn();
    }
    
    displayBoard();
    
}
bool Game::game_Over() // This function checks we should keep plying the game or end it by return false if the game is over or true to keep playing
{
    // Winnner
    for (int i = 0; i < 3; i++) // for matches in column and row
        if ((board [i][0] == board[i][1] && board [i][0] == board[i][2]) || (board [0][i] == board[1][i] && board [0][i] == board[2][i]))
            return false;
    
    // Diagonal
    if ((board[0][0] == board[1][1] && board[0][0] == board[2][2]) || (board[0][2] == board[1][1] && board[0][2] == board[2][0]))
        return false;
    
    
    // if there's any box not filled
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board [i][j] != 'X' && board [i][j] != 'O')
                return true;
    
    // DRAW
    draw = true;
    return false;

}

void Game::check()
{
    if (!game_Over() && turn == 'X')
        cout << "Player1 [O] Wins" << endl;
    else if (turn == 'O' && !game_Over() )
        cout << "Player2 [X] Wins" << endl;
    else 
        cout << "DRAW GAME" << endl;
    
}

