#include <stack>
#include <vector>
#include <string>

using namespace std;

bool isValid(string s){
    stack<char> st;
    for (char c : s){
        if (c == '(' || c == '{' || c == '[') st.push(c);
        else {
            if (st.empty()) return false;
            char k = st.top();
            st.pop();
            if ((c == ')' && k != '(') || (c == '}' && k != '{') || (c == ']' && k != '[')) return false;
        }
    }
    if (st.empty()) return true;
    else return false;
}