#include <bits/stdc++.h>
using namespace std;

void backtrack(int n, int open, int close, string& current, vector<string>& result){
    if (current.size() == 2*n){
        result.push_back(current);
        return;
    }

    if (open < n){
        current += "(";
        backtrack(n, open+1, close, current, result);
        current.pop_back();
    }

    if (close < open){
        current += ")";
        backtrack(n, open, close + 1, current, result);
        current.pop_back(); 
    }
}

vector<string> generateParenthesis(int n){
    string current = "";
    vector<string> result;
    backtrack(n, 0, 0, current, result);
    return result;
}

int main(){
    int n = 3;
    vector<string> final = generateParenthesis(n);
    for (auto& i : final){
        cout << i << endl;
    } 
}