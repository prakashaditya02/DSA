#include <bits/stdc++.h>
using namespace std;

void backtrack(int index, vector<int>& current, vector<int>& nums, vector<vector<int>>& result){
    if (index == nums.size()){
        result.push_back(current);
        return; 
    }

    current.push_back(nums[index]);
    backtrack(index + 1, current, nums, result);
    current.pop_back();

    backtrack(index + 1, current, nums, result);
}

vector<vector<int>> subsets(vector<int>& nums){
    vector<int> current;
    vector<vector<int>> res;
    backtrack(0, current, nums, res);
    return res;
}