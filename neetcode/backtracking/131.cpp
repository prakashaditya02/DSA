#include <bits/stdc++.h>
using namespace std;

bool palindrome(const string& s){
    string rev = s;
    reverse(rev.begin(), rev.end());
    return s == rev;
}

void backtrack(int start, string& s, vector<string>& current, vector<vector<string>>& result){
    if (start >= s.size()){
        result.push_back(current);
        return;
    }
    string c = "";
    for (int i = start; i < s.length(); i++){
        c += s[i];
        if (!palindrome(c)){
            continue;
        }
        current.push_back(c);
        backtrack(i+1, s, current, result);
        current.pop_back();
    }
}

vector<vector<string>> partition(string s){
    vector<vector<string>> result;
    vector<string> current;
    backtrack(0, s, current, result);
    return result;
}

int main(){
    string s;
    cin >> s;
    vector<vector<string>> res = partition(s);
    for (auto& i : res){
        for (auto& j : i){
            cout << j << "  ";
        }
        cout << endl;
    }
}