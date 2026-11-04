#include <bits/stdc++.h>
using namespace std;

void backtrack(int start, int sum, int target, vector<int>& current, vector<int>& candidates, vector<vector<int>>& result){
    if (sum == target) {
        result.push_back(current);
        return;
    }

    if (sum > target) return;

    for (int i = start; i < candidates.size(); i++){
        current.push_back(candidates[i]);
        sum += candidates[i];

        backtrack(i, sum, target, current, candidates, result);

        sum -= candidates[i];
        current.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<int> current;
    vector<vector<int>> result;
    backtrack(0, 0, target, current, candidates, result);
    return result;     
}