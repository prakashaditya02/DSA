#include <bits/stdc++.h>
using namespace std;

void backtrack(vector<int>& current, vector<bool>& freq, vector<int>& nums, vector<vector<int>>& result){
    if (current.size() == nums.size()){
        result.push_back(current);
        return;
    }

    for (int i = 0; i < nums.size(); i++){
        if (freq[i]) continue;
        freq[i] = true;
        current.push_back(nums[i]);

        backtrack(current, freq, nums, result);
        
        freq[i] = false;
        current.pop_back();
    }
}

vector<vector<int>> permute(vector<int>& nums){
    vector<int> current;
    vector<bool> used(nums.size(), false);
    vector<vector<int>> result;

    backtrack(current, used, nums, result);
    return result;
}