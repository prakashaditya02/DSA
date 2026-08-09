#include <vector>
#include <iostream>

using namespace std;

bool bsearch (const vector<int>& nums, int l, int r, int t){
    if (l > r) return false;
    int mid = (l+r)/2;

    if (nums[mid] == t) return true;
    if (nums[mid] > t) return bsearch(nums, l, mid-1, t);
    if (nums[mid] < t) return bsearch(nums, mid+1, r, t);

    return false;
}

bool searchMatrix (vector<vector<int>>& matrix, int target){
    int row = matrix.size(), col = matrix[0].size();
    int low = 0, high = row-1;
    int mid = (high + low)/2;
    if (target < matrix[0][0]) return false;

    while (low <= high){
        mid = (high+low)/2;
        if (matrix[mid][0] == target) return true;
        if (matrix[mid][0] > target) high = mid-1;
        if (matrix[mid][0] < target) low = mid+1;
    }

    if (high >= 0 && high < row){
        return bsearch(matrix[high], 0, col-1, target);
    }
    return false;
}

int main(){
    vector<vector<int>> mat = {{1,3,5,7}, {10,11,16,20}, {23,30,34,60}};
    cout << searchMatrix(mat, 12);
}