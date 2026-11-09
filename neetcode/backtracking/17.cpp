#include <bits/stdc++.h>
using namespace std;

vector<string> dict = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void backtrack(int start, string& digits, string& current, vector<string>& result){
    if (start == digits.size()){
        result.push_back(current);
        return;
    }

    for (char s : dict[digits[start]-'2']){
        current += s;
        backtrack(start+1, digits, current, result);
        current.pop_back();
    }
}

vector<string> letterCombinations(string digits){
    string s;
    vector<string> res;
    backtrack(0, digits, s, res);
    return res;
}