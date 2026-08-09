#include <array>
#include <string>

using namespace std;

bool checkInclusion(string s1, string s2){
    if (s1.length() > s2.length()) return false;
    int l = 0, r = s1.length()-1;

    array <int, 26> s1freq = {};
    for (auto& c : s1) s1freq[c - 'a']++;

    array <int, 26> s2freq = {};
    for (int i = 0; i < s1.length(); i++) s2freq[s2[i] - 'a']++;
    
    int match = 0;
    for (int i = 0; i < 26; i++) if (s1freq[i] == s2freq[i]) match++;
    
    if (match == 26) return true;

    while (r + 1 < s2.length()){
         r++;
         if (s1freq[s2[r] - 'a'] == s2freq[s2[r] - 'a']) match--;
         s2freq[s2[r] - 'a']++;
         if (s1freq[s2[r] - 'a'] == s2freq[s2[r] - 'a']) match++;

         l++;
         if (s1freq[s2[l-1] - 'a'] == s2freq[s2[l-1] - 'a']) match--;
         s2freq[s2[l-1] - 'a']--;
         if (s1freq[s2[l-1] - 'a'] == s2freq[s2[l-1] - 'a']) match++;

         if (match == 26) return true;
    }
    return false;
}