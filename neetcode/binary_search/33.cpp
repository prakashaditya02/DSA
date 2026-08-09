#include <vector>
#include <iostream>

using namespace std;

int search(vector<int>& nums, int target){
    int l = 0, h = nums.size()-1;
    while (l <= h){
        int mid = (l+h)/2;
        if (nums[mid] == target) return mid;
        if (nums[mid] < nums[h]){
            if (target <= nums[h] && target > nums[mid]) l = mid+1;
            else h = mid-1;
        }
        else {
            if ((target >= nums[l]) && target < nums[mid]) h = mid-1;
            else l = mid+1;
        }
    }
    return -1;
}

int main(){
    vector<int> v = {4, 5, 6, 7, 1, 2, 3};
    vector<int> k = {1, 3, 5, 7, 9};
    cout << search(k, 1);
}