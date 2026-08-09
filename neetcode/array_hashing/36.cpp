#include <iostream>
#include <vector>
#include <array>

using namespace std;

bool isValidSudoku(vector<vector<char>>& board){
    for (vector<char> row : board){
        array<int, 10> rowArr = {0};
        for (char c : row){
            if (c != '.'){
                int element  = c-'0';
                if (rowArr[element] != 1) rowArr[element] = 1;
                else return false;
            }
        }
    }

    for (int i=0; i<9; i++){
        array<int, 10> colArr = {0};
        for (int j = 0; j<9; j++) {
            char c = board[j][i];
            if (c != '.'){
                int element = c-'0';
                if (colArr[element] != 1) colArr[element] = 1;
                else return false;
            }
        }
    }
    array<array<int, 10>, 3> block = {0};
    for (int i=0; i<9; i++){
        if (i%3 == 0) for (auto& row: block) row.fill(0);
        for (int j=0; j<9; j++){
            char c = board[j][i];
            if (c != '.'){
                int element = c-'0';
                if (block[j/3][element] != 1) block[j/3][element] = 1;
                else return false;
            }
        }
    }
    return true;
}