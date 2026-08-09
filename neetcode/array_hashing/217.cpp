#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

bool containsDuplicate(vector<int>& nums){
    unordered_set<int> set;
    for (int num : nums){
        auto it = set.find(num);
        if (it != set.end()) return true;
        else set.insert(num);
    }
    return false;
}

int main() {
    vector<int> nums = {1,2,3,1};
    cout << containsDuplicate(nums) << endl;
}