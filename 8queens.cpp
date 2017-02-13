#include <iostream>
using namespace std;

int board[8][8] = {{0}};
bool underattack(int r, int c);
/*
    Program implements backtracking algorithm to find all solutions
    of 8 queens problem
*/
int main(){
    // Row and Column is how we keep track of current positioning on board
    int row = 0;
    int column = 0;
    //Initial Placement of Queen of the top left corner of board
    board[0][0] = 1;
    //Solution Tracker
    int count = 0;
    column++;

    NEXTROW:
        if(row == 8)
            goto BACKTRACK;
        if(underattack(row,column)){
            row++;
            goto NEXTROW;
        }

        board[row][column] = 1;
        goto NEXTCOL;

    NEXTCOL:
        column++;
        row = 0;
        if(column == 8)
            goto PRINT;
        goto NEXTROW;

//Goes to previous column and moves the queen down until a spot is found
//If spot cannot be found then BACKTRACK is called again.
    BACKTRACK:
        column--;
        if(column == -1)
            return 0;
        for(int i = 0; i < 8 ; i++){
            if(board[i][column] == 1){
                board[i][column] = 0;
                row = ++i;
                break;
            }
        }
        goto NEXTROW;

//Solution Output
    PRINT:
        cout << "Solution #" << ++count << endl;
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                cout <<"[" <<board[i][j] <<"]";
            }
            cout << endl;
        }
        cout << endl;
        goto BACKTRACK;


return 0;
}

/*
Function to determine whether a queen is under attack
    */
bool underattack(int r, int c){
    int i, j;
    //Row Check
    for(i = 0; i < c; i++){
        if(board[r][i] == 1){
            //cout << "row" << endl;
            return true;
        }
    }
    //Upper Diagnol
    for(i = r - 1, j = c - 1; (i >=0 && j >= 0);--i,--j){
        if(board[i][j] == 1){
            //cout << "UD row:"<<i <<"column "<<j << endl;
            return true;
        }
    }
    //Lower Diagnol
    for(i = r + 1, j = c - 1; (i < 8 && j >= 0);++i,--j){
        if(board[i][j] == 1){

            //cout << "LD row:"<<i <<"column "<<j << endl;
            return true;
        }
    }

    return false;
}
