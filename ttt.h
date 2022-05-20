#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdbool.h>


void init_board();
void draw_board(); 
void make_move(char player);
bool check(int row, int col);
bool play_turn(char player); 



char board[3][3];

#endif

