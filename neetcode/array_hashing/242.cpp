#include <iostream>
#include <string>
#include <array>

using namespace std;

bool isAnagram(string s, string t){
    array<int, 26> a = {0};

    for (char c: s) a[c - 'a'] += 1;
    for (char c: t) a[c - 'a'] -= 1;

    for (int i = 0; i < 26; i++){
        if (a[i] != 0) return false;
    }
    return true;
}
int main(){
string s = "anagram", t = "nagaram";
cout << isAnagram(s, t) << endl;
}