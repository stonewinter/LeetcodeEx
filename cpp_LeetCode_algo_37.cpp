#include <iostream>
#include <stdlib.h>
#include <unordered_map>
#include <list>
#include <vector>
#include <cmath>
#include <sstream>
#include <memory>

using namespace std;

inline int GetBoxKey(int r, int c);
void solveSudoku(vector<vector<char>>& board);
bool IsVaild(int digit, int r, int c, vector<vector<bool>>& rowExist, vector<vector<bool>>& colExist, vector<vector<bool>>& boxExist);
bool Fill(vector<vector<char>>& board, int row, int col,
          vector<vector<bool>>& rowExist,
          vector<vector<bool>>& colExist,
          vector<vector<bool>>& boxExist);


//bool Fill(vector<vector<char>>& board, int r, int c);

//const int BOARD_SIZE = 9;
//vector<int> number = {1,2,3,4,5,6,7,8,9};
//
//vector<vector<bool>> rowNumExist(BOARD_SIZE, vector<bool>(10, false));
//vector<vector<bool>> colNumExist(BOARD_SIZE, vector<bool>(10, false));
//vector<vector<bool>> boxNumExist(BOARD_SIZE, vector<bool>(10, false));

vector<vector<char>> board =
{{'.','.','9','7','4','8','.','.','.'},
 {'7','.','.','.','.','.','.','.','.'},
 {'.','2','.','1','.','9','.','.','.'},
 {'.','.','7','.','.','.','2','4','.'},
 {'.','6','4','.','1','.','5','9','.'},
 {'.','9','8','.','.','.','3','.','.'},
 {'.','.','.','8','.','3','.','2','.'},
 {'.','.','.','.','.','.','.','.','6'},
 {'.','.','.','2','7','5','9','.','.'}};



int main(){

    solveSudoku(board);

    for(auto eachRow : board){
        for(auto eachItem : eachRow){
            cout << eachItem << " ";
        }
        cout <<endl;
    }

    return 0;
}


// label 3*3 boxes with a index 0~8
inline int GetBoxKey(int row, int col){
    return (row/3)*3 + col/3;
}


bool IsVaild(int digit, int r, int c, vector<vector<bool>>& rowExist, vector<vector<bool>>& colExist, vector<vector<bool>>& boxExist){
    if(rowExist[r][digit] || colExist[c][digit] || boxExist[GetBoxKey(r,c)][digit])
        return false;
    else
        return true;
}



bool Fill(vector<vector<char>>& board, int row, int col,
          vector<vector<bool>>& rowExist,
          vector<vector<bool>>& colExist,
          vector<vector<bool>>& boxExist){
    if(row>=board.size()){
        return true;
    }

    int nextc = (col+1) % board[0].size();
    int nextr = row + (col+1)/board[0].size();

    if(board[row][col] == '.'){
        for(int num=1;num<=9;num++){
            if(IsVaild(num, row, col, rowExist, colExist, boxExist)){
                board[row][col] = num+'0';
                rowExist[row][num] = true;
                colExist[col][num] = true;
                boxExist[GetBoxKey(row,col)][num] = true;
                if(Fill(board, nextr, nextc, rowExist, colExist, boxExist)){
                    return true;
                }
                boxExist[GetBoxKey(row,col)][num] = false;
                colExist[col][num] = false;
                rowExist[row][num] = false;
                board[row][col] = '.';
            }
        }
        return false;
    }
    else{
        return Fill(board, nextr, nextc, rowExist, colExist, boxExist);
    }
}





void solveSudoku(vector<vector<char>>& board) {
    vector<vector<bool>> rowExist(board.size(), vector<bool>(10, false));
    vector<vector<bool>> colExist(board[0].size(), vector<bool>(10, false));
    vector<vector<bool>> boxExist(board.size(), vector<bool>(10, false));

    for(int r=0;r<(int)board.size();r++){
        for(int c=0;c<(int)board[0].size();c++){
            if(board[r][c]!='.'){
                int digit = board[r][c]-'0';
                rowExist[r][digit] = true;
                colExist[c][digit] = true;
                boxExist[GetBoxKey(r,c)][digit] = true;
            }
        }
    }


    Fill(board, 0, 0, rowExist, colExist, boxExist);
}



//bool Fill(vector<vector<char>>& board, int r, int c){
//    // reach the final solution
//    if(r==BOARD_SIZE){
//        return true;
//    }
//
//    int next_c = (c+1) % BOARD_SIZE;
//    int next_r = (next_c == 0)? r+1 : r;
//
//    // board(r,c) has number already. go fill next coordinate
//    if(board[r][c] != '.'){
//        return Fill(board, next_r, next_c);
//    }
//
//    // board(r,c) has empty number here. go fill this coordinate
//    for(auto num : number){ // for each number 1~9
//        // see if current number meets the constraint on row/col/box
//        if(!rowNumExist[r][num] && !colNumExist[c][num] && !boxNumExist[GetBoxKey(r,c)][num]){
//            // current number meets the constraint on row/col/box, go fill this number and set existence history
//            board[r][c] = num + '0';
//            rowNumExist[r][num] = true;
//            colNumExist[c][num] = true;
//            boxNumExist[GetBoxKey(r,c)][num] = true;
//
//            // then check if next coordinate can reach the final solution based on number just filled above
//            if(Fill(board, next_r, next_c)) return true;
//
//            // if next coordinate doesnt reach to final solution, it means we have filled the wrong number
//            // then remove it, and go loop try other number 1~9
//            board[r][c] = '.';
//            rowNumExist[r][num] = false;
//            colNumExist[c][num] = false;
//            boxNumExist[GetBoxKey(r,c)][num] = false;
//        }
//    }
//
//    // all the possibilities have been tried, it means there is no proper final solution
//    return false;
//}



