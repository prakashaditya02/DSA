#include <string>
#include <cctype>

using namespace std;

bool isPalindrome(string s){
    int i = 0;
    int j = s.size() -1;
    bool flag = true;
    while (i <= j){
        if (!isalnum(s[i])){
            i++; continue;
        }
        if (!isalnum(s[j])){
            j--; continue;
        }
        if (tolower(s[i]) == tolower(s[j])){
            i++; j--;
            continue;
        }
        else {
            flag = false;
            break;
        }
    }
    return flag;
}