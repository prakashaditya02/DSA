#include <queue>
#include <stdlib.h>

using namespace std;

int lastStoneWeight(vector<int>& stones){
    priority_queue<int> pq(stones.begin(), stones.end());
    while (pq.size() > 1){
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        if (a == b) continue;
        else {
            pq.push(a-b);
        }
    }
    if (pq.size() == 1) return pq.top();
    else return 0;
}