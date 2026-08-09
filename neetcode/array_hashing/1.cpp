#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target){
	vector<int> res;
	unordered_map<int, int> map;
	for (int i = 0; i < nums.size(); i++){
		int ind = -1;
		auto it = map.find(target-nums[i]);
		if (it != map.end()){
			ind = it->second;
		}
		if (ind != -1){
			res = {i, ind};
			return res;
		}
		else {
			map.insert({nums[i], i});
		}
	}
	return res;
}

int main(){
}
