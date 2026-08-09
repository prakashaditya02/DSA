#include <vector>
#include <iostream>

using namespace std;

int findMin(vector<int>& nums){
    int l = 0, h = nums.size()-1;
    int minval = nums[0];
    while (l < h){
        int mid = (l+h)/2;
        if (nums[mid] > nums[h]) l = mid+1;
        else h = mid;
        minval = (minval > nums[l]) ? nums[l] : minval;
    }
    return nums[l];
}

int main(){
    vector<int> v = {17, 11, 13, 15};
    cout << findMin(v);
}