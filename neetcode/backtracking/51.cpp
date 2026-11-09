#include <bits/stdc++.h>
using namespace std;

bool check(vector<int>& state, int r, int c, int& n){
    for (int i = 0; i < r; i++){
        if (i == r || state[i] == c || (abs(i-r) == abs(state[i]-c))){
            return false;
        }
    }
    return true;
}

void backtrack(vector<int>& state, int row, int& n, vector<vector<int>>& result){
    if (row >= n){
        result.push_back(state);
        return;
    }

    for (int i = 0; i < n; i++){
        if (!check(state, row, i, n)){
            continue;
        }
        state[row] = i;
        backtrack(state, row+1, n, result);
        state[row] = -10;
    }
}

vector<vector<int>> solveNQueens(int n){
    vector<vector<int>> result;
    vector<int> state(n, -10);
    backtrack(state, 0, n, result);
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> result = solveNQueens(n);
    for (auto& i : result){
        for (auto& j : i){
            cout << j << " ";
        }
        cout << endl;
    }
}