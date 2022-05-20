#include "ttt.h"


void init_board(){
    int i, j;
    
    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            board[i][j] = '.'; 
        }
    }
}

void draw_board(){
    int i, j;
    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            printf(" %c ", board[i][j]);
        }
        printf("\n"); 
    }
}

bool check(int row, int col){
    if (board[row][col] == '.'){
        return true;
    }
    else {
        return false;
    }
}

void make_move(char player){
    int row = 0, col = 0;
    
    do {
        printf("\n %c, make a move!\n ", player);
        scanf("%d%d", &row, &col);
        
        if(!(check(row - 1, col - 1))){
            printf("Not a valid move, try again!\n ");
        }
    } while (!(check(row - 1, col - 1)));
    
    board[row - 1][col - 1] = player; //set position to either O or X
}



bool play_turn(char player){
    int i;
    
    for (i = 0; i < 3; i++){
        if ((board[i][0] == player) && //for horizontal check
            (board[i][1] == player) && 
            (board[i][2] == player)){
            
            return true;
        }
        else if ((board[0][0] == player) && //for diagonal check
                (board[1][1] == player) &&
                (board[2][2] == player)){
                    
            return true;
        }
        else if ((board[0][i] == player) && //for vertical check
                (board[1][i] == player) &&
                (board[2][i] == player)){
                    
            return true;
        }
    }
    
    return false;
}

int main(void){
    char player = 'X';
    bool running = true;
    int move = 0;
    char win = ' '; 
    
    init_board();
    draw_board();
    
    while (running){
        
        if (move % 2 == 0){
            player = 'X';
        }
        else{
            player = 'O';
        }
        
        switch(player){
            case 'X':
                make_move(player);
            break;
            case 'O':
                make_move(player);
            break;
        }
        
        if (play_turn(player)){ 
            win = player;
            running = false; 
        }
        
        move++;
        
        if (move == 9){
            running = false;
        }
        
        draw_board();
    }
    
    if (win == ' '){
        printf("It's a draw!");
    }
    else {
        printf("%c won the game!", player); 
    }
  
  return 0;
}