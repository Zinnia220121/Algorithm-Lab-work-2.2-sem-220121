#include<bits/stdc++.h>
using namespace std ;

bool isSafe(vector<vector<int>> &board, int row, int col, int n){
    for(int i = 0 ; i < row ; i++)
        if(board[i][col] == 1) return false ;
    for(int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if(board[i][j] == 1) return false ;
    for(int i = row, j = col; i >= 0 && j < n; i--, j++)
        if(board[i][j] == 1) return false ;

    return true ;
}

void printBoard(vector<vector<int>> &board, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << (board[i][j] ? "Q " : "- ");
        }
        cout << endl ;
    }
    cout << endl; // Separate solutions by a blank line
}

void solveNqueen(vector<vector<int>> &board, int row, int n){
    if(row == n) {
        printBoard(board, n);
        return; // Print the current solution and backtrack
    }

    for(int col = 0; col < n; ++col){
        if(isSafe(board, row, col, n)){
            board[row][col] = 1 ;
            solveNqueen(board, row + 1, n);
            board[row][col] = 0 ; // Backtrack
        }
    }
}

int main(){
    int n ; cin >> n ;
    vector<vector<int>> board(n, vector<int>(n, 0)) ;
    solveNqueen(board, 0, n) ;
    return 0;
}
