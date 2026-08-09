#include <string>
#include <array>
#include <unordered_map>

using namespace std;

string minWindow(string s, string t){
    if (s.length() < t.length()) return "";

    unordered_map<char, int> sfreq;
    unordered_map<char, int> tfreq;

    for (char& k : t) tfreq[k]++;
    int match = 0;
    int l = 0, r = 0;

    string res = "";

    while (r < s.length()){
        sfreq[s[r]]++;
        if (sfreq[s[r]] == tfreq[s[r]]) match++;
        
        while (match == tfreq.size()){
            if (res == "" || res.length() > r-l+1) for (int k = l; k <= r; k++) res += s[k];
            l++;
            sfreq[s[l-1]]--;
            if (sfreq[s[l-1]] != tfreq[s[l-1]]) match--;
        }
        r++;
    }
    return res;
}