#include <vector>

using namespace std;

int findDuplicate(vector<int>& nums){
    int slow = nums[0];
    int fast = nums[nums[0]];

    while (slow != fast) {
        slow = nums[slow];
        fast = nums[nums[fast]];
    }

    int find = 0;
    while (find != slow) {
        find = nums[find];
        slow = nums[slow];
    }

    return find;
}