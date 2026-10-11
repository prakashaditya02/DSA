#include <queue>
#include <vector>
#include <cmath>

using namespace std;

vector<vector<int>> kClosest(vector<vector<int>>& points, int k){
    priority_queue<pair<int, int>, vector<int>, greater<int>> pq;
    for (int i = 0; i < points.size(); i++){
        if (pq.size() < k){
            vector<int> point = points[i];
            int sq = pow(point[0], 2) + pow(point[1], 2); 
            pair<int, int> p = {sq, i};
            pq.push(p); 
        }
    }
}