#include <queue>
#include <stdlib.h>

using namespace std;

class MedianFinder {
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;

public:
    MedianFinder() {

    }

    void addNum(int num){

        if (maxheap.empty() || maxheap.top() >= num){
            maxheap.push(num);
        } else {
            minheap.push(num);
        }

        int mins = (int)minheap.size();
        int maxs = (int)maxheap.size();

        if (abs(mins - maxs) > 1){
            if (mins > maxs){
                maxheap.push(minheap.top());
                minheap.pop();
            } else {
                minheap.push(maxheap.top());
                maxheap.pop();
            }
        }
    }

    double findMedian() {
        if (maxheap.size() == minheap.size()) {
            return ((double)maxheap.top() + minheap.top())/2;
        } else {
            if (maxheap.size() > minheap.size()){
                return (double)maxheap.top();
            } else {
                return (double)minheap.top();
            }
        }
    }
};