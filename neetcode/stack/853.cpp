#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int carFleet(int target, vector<int>& pos, vector<int>& speed){
    vector<pair<int, int>> p;
    stack<float> st;

    int len = pos.size();
    for (int i=0; i < len; i++){
        p.emplace_back(pos[i], speed[i]);
    }
    sort(p.begin(), p.end());
    reverse(p.begin(), p.end());

    for (int i=0; i < len; i++){
        float time = (target - p[i].first)/(float)p[i].second;
        if (st.empty() || time > st.top()) st.push(time);
    }
    return st.size();
}