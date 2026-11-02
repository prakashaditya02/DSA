#include <bits/stdc++.h>
using namespace std;

void backtrack(int start, vector<int>& current, vector<int>& nums, vector<vector<int>>& result){
    result.push_back(current);
    for (int i = start; i < nums.size(); i++){
        current.push_back(nums[i]);
        backtrack(i+1, current, nums, result);
        current.pop_back();
    }
}

vector<vector<int>> subsets(vector<int>& nums){
    vector<vector<int>> res;
    vector<int> current;
    backtrack(0, current, nums, res);
    return res;
}

int main(){
    vector<int> set {1, 2, 3};
    vector<vector<int>> res = subsets(set);
    for (auto& x : res) {
        for (auto& element : x) {
            cout << element << " ";
        }
        cout << endl;
    }
}