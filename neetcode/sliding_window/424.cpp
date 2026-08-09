#include <string>
#include <array>

using namespace std;

int charReplace(string s, int k){
    int l=0, r =0;
    array <int, 26> freq = {};
    int maxFreq = 0;
    int maxlen = 0;

    while (r < s.length()){
        freq[s[r] - 'A'] += 1;
        int win_size = r-l+1;
        maxFreq = (maxFreq > freq[s[r] - 'A']) ? maxFreq : freq[s[r]- 'A'];

        if (win_size - maxFreq > k){
            freq[s[l] - 'A'] -= 1;
            l++;
        }
        maxlen = (maxlen > win_size) ? maxlen : win_size;
        r++;
    }
    return maxlen;
}