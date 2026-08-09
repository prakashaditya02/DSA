#include <vector>
#include <iostream>

using namespace std;

int bsearch(const vector<int>& nums, int l, int r, int t){
    int mid = (l+r)/2;
    if (l > r) return -1;
    if (nums[mid] == t) return mid;
    if (nums[mid] > t) return bsearch(nums, l, mid-1, t);
    if (nums[mid] < t) return bsearch(nums, mid+1, r, t);
    return -1;
}
int search(vector<int>& nums, int target){
    return bsearch(nums, 0, nums.size()-1, target);
}

int main(){
    vector<int> a = {1, 2, 3, 4, 5, 6};
    vector<int> b = {1, 3, 5, 7, 9, 11, 13};

    cout << search(a, 3);
    cout << search(b, 13);
}