#include <bits/stdc++.h>
using namespace std;

void backtrack(vector<vector<bool>>& visited, string word, vector<vector<char>>& board, int x, int y, string& curr, bool& doesitexist){
    if (curr == word || doesitexist == true){
        doesitexist = true;
        return;
    }

    int m = board.size();
    int n = board[0].size();

    if (((x+1 < m) && board[x+1][y] == word[curr.size()]) && !(visited[x+1][y])){
        curr += board[x+1][y];
        visited[x+1][y] = true;
        backtrack(visited, word, board, x+1, y, curr, doesitexist);
        curr.pop_back();
        visited[x+1][y] = false;
    }

    if (((y+1 < n) && board[x][y+1] == word[curr.size()]) && !(visited[x][y+1])){
        curr += board[x][y+1];
        visited[x][y+1] = true;
        backtrack(visited, word, board, x, y+1, curr, doesitexist);
        curr.pop_back();
        visited[x][y+1] = false;
    }

    if (((x-1 >= 0) && board[x-1][y] == word[curr.size()]) && !(visited[x-1][y])){
        curr += board[x-1][y];
        visited[x-1][y] = true;
        backtrack(visited, word, board, x-1, y, curr, doesitexist);
        curr.pop_back();
        visited[x-1][y] = false;
    }

    if (((y-1 >= 0) && board[x][y-1] == word[curr.size()]) && !(visited[x][y-1])){
        curr += board[x][y-1];
        visited[x][y-1] = true;
        backtrack(visited, word, board, x, y-1, curr, doesitexist);
        curr.pop_back();
        visited[x][y-1] = false;
    }
}

bool exist(vector<vector<char>>& board, string word){
    bool doesitexist = false;
    for (int i = 0; i < board.size(); i++){
        for (int j = 0; j < board[0].size(); j++){
            if (doesitexist) return true;
            if (board[i][j] != word[0]) continue;
            vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
            visited[i][j] = true;
            string current;
            current += word[0];
            backtrack(visited, word, board, i, j, current, doesitexist);
        }
    }
    return doesitexist;
}