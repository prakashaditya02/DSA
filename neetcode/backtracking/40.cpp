#include <bits/stdc++.h>
using namespace std;

void backtrack(int start, int sum, int target, vector<int>& current, vector<int>& candidates, vector<vector<int>>& result){
    if (sum == target){
        result.push_back(current);
        return;
    }
    if (sum > target) return;

    for (int i = start; i < candidates.size(); i++){
        if (i > start && candidates[i] == candidates[i-1]) continue;
        current.push_back(candidates[i]);
        backtrack(i+1, sum + candidates[i], target, current, candidates, result);
        current.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<int> current;
    vector<vector<int>> result;
    backtrack(0, 0, target, current, candidates, result);
    return result;
}