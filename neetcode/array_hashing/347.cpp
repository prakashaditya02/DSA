#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k){
    unordered_map<int, int> map;
    for (const int& num : nums){
        auto it = map.find(num);
        if (it != map.end()) map[num] += 1;
        else map.insert({num, 1});
    }
    priority_queue<pair<int, int>> pq;
    for (auto &pair : map) pq.push({pair.second, pair.first});
    vector<int> res;
    for (int i = 0; i < k; i++){
        auto top = pq.top();
        res.push_back(top.second);
        pq.pop();
    }
    return res;
}