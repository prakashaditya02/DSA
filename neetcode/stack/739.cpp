#include <vector>
#include <stack>

using namespace std;

vector<int> dailyTemperatures(vector<int>& temp){
    stack<int> st;
    vector<int> res(temp.size(), 0);

    for (int i=0; i < temp.size(); i++){
        while (!st.empty() && temp[i] > temp[st.top()]){
            res[st.top()] = i - st.top();
            st.pop();
        }
        st.push(i);
    }
    return res;
}