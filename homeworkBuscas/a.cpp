#include <bits/stdc++.h> 
#define nl << '\n' 
#define ll long long 
using namespace std; 
using vi = vector<int>; 

bool check(const vector<string>& board, int row, int col, char c){
    for(int i = 0; i < 9; i++){
        if(board[row][i] == c) return false;
        if(board[i][col] == c) return false;
        if(board[3*(row/3) + i/3][3*(col/3) + i%3 ] == c) return false;
    }
    return true;
}

bool solveSudoku(vector<string>& board, int i = 0, int j = 0){
    if(i == 9) return true;
    if(j == 9) return solveSudoku(board, i+1, 0);

    if(board[i][j] != '0') return solveSudoku(board, i, j+1);

    for(char c = '1'; c <= '9'; c++){
        if(check(board, i, j, c)){
            
        }
    }
}

int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0); 
    
    
    
    return 0; 
}