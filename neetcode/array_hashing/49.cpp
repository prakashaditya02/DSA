#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <unordered_map>

using namespace std;

// bool isAnagram(string s, string t){
//     array<int, 26> a = {0};

//     for (char c: s) a[c - 'a'] += 1;
//     for (char c: t) a[c - 'a'] -= 1;

//     for (int i = 0; i < 26; i++){
//         if (a[i] != 0) return false;
//     }
//     return true;
// }

// vector<vector<string>> groupAnagrams(vector<string>& strs){
//     vector<vector<string>> out = {};
//     for (string str : strs){
//         int flag = 0;
//         for (int i = 0; i < out.size(); i++){
//             if (isAnagram(str, out[i][0])) {
//                 flag = 1;
//                 out[i].push_back(str);
//             }
//         }
//         if (flag == 0) out.push_back({str}); 
//     }
//     return out;
// }

string freqStr(const string& str){
    array<int, 26> a = {0};
    for (char c : str) a[c - 'a'] += 1;

    string s = "";
    for (int i : a){
        s += to_string(i);
        s += ' ';
    }
    return s;
}

vector<vector<string>> groupAnagrams(vector<string>& strs){
    unordered_map<string, vector<string>> map;
    for (const string& str : strs){
        string freq = freqStr(str);
        auto it = map.find(freq);
        if (it != map.end()) map[freq].push_back(str);
        else map.insert({freq, {str}});
    }
    vector<vector<string>> res;
    for (auto &pair : map) res.push_back(pair.second);
    return res;
}
