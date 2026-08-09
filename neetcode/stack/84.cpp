#include <stack>
#include <vector>

using namespace std;

int largestRectangleArea(vector<int>& heights){
    int n = heights.size();
    vector<int> leftAr(n);
    vector<int> rightAr(n);
    stack<int> leftSt, rightSt;

    for (int i=0; i < n; i++){
        while (!leftSt.empty() && heights[i] < heights[leftSt.top()]){
            leftAr[leftSt.top()] = heights[leftSt.top()] * (i - leftSt.top());
            leftSt.pop();
        }
        leftSt.push(i);
    }

    for (int i=n-1; i >= 0; i--){
        while (!rightSt.empty() && heights[i] < heights[rightSt.top()]){
            rightAr[rightSt.top()] = heights[rightSt.top()] * (i - rightSt.top());
            rightSt.pop();
        }
        rightSt.push(i);
    }
}