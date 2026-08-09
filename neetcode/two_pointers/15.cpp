#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums){
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int i = 0;
    vector<vector<int>> res;
    while (i+2 < n){
        if (i>0 && nums[i] == nums[i-1]){
            i++; continue;
        }
        int j = i + 1;
        int k = n-1;

        while (j<k){
            if ((j != i+1) && nums[j] == nums[j-1]){
                j++; continue;
            }
            if ((k != n-1) && nums[k] == nums[k+1]){
                k--; continue;
            }
            if (nums[i] + nums[j] + nums[k] == 0){
                res.push_back({nums[i], nums[j], nums[k]});
                j++; k--; continue;
            }
            if (nums[i] + nums[j] + nums[k] > 0){ 
                k--; continue;
            }
            else j++; 
        }
        i++;
    }
    return res;
}