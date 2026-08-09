
#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

// int lenSub(string s){
//     array<int, 27> sub;
//     for (int z=0; z<27; z++) sub[z] = -1;
//     int l=0, r=0;
//     int maxlen = 0;
//     for (; r < s.length(); r++){
//         char k = s[r];
//         int ind = k-'a'+1;
//         if (sub[ind] >= l){
//             l = sub[ind] + 1;
//         }
//         sub[ind] = r;
//         maxlen = (maxlen > r-l+1) ? maxlen : r-l+1;
//     }
//     return maxlen;
// }

int lenSub(string s){
    unordered_map<char, int> map;
    int l = 0, r = 0;
    int maxlen = 0;

    for (; r < s.length(); r++){
        char k = s[r];
        auto it = map.find(k);
        if (it != map.end() && it->second >= l){
            l = it->second + 1;
        } else {
            map.insert({k, r});
        }
        map[k]= r;
        maxlen = (maxlen > r-l+1) ? maxlen : r-l+1;
    }
    return maxlen;
}


int main(){
    string s = "bbbbbb";
    cout << lenSub(s);
}