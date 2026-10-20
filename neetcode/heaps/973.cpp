#include <queue>
#include <vector>

using namespace std;

vector<vector<int>> kClosest(vector<vector<int>>& points, int k){
    vector<vector<int>> result;
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < points.size(); i++){
        vector<int> point = points[i];
        int sq = point[0]*point[0] + point[1]*point[1]; 
        pair<int, int> p = {sq, i};
        pq.push(p);

        if (pq.size() > k){
            pq.pop();
        }
    }
    while (!pq.empty()){
        auto x = pq.top();
        pq.pop();
        result.push_back(points[x.second]);
    }
    return result;
}