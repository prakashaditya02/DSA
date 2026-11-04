#include <bits/stdc++.h>
using namespace std;

void backtrack(int start, vector<int>& current, vector<int>& nums, vector<vector<int>>& result){
    result.push_back(current);
    
    for (int i = start; i < nums.size(); i++){
        if (i > start && nums[i] == nums[i-1]) continue;

        current.push_back(nums[i]);
        backtrack(i+1, current, nums, result);
        current.pop_back();
    }
}

vector<vector<int>> subsetWithDup(vector<int>& nums){
    sort(nums.begin(), nums.end());
    vector<int> current;
    vector<vector<int>> result;
    backtrack(0, current, nums, result);
    return result;
}