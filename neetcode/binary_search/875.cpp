#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int eat(vector<int>& piles, int k){
    int time = 0;
    for (auto& c : piles) time += (c+k-1)/k;
    return time;
}

int minEatingSpeed(vector<int>& piles, int h){
    int low = 1, high = *max_element(piles.begin(), piles.end());
    while (low < high){
        int mid = (low+high)/2;
        int e = eat(piles, mid);
        if (e <= h) high = mid;
        if (e > h) low = mid+1;
    }
    return low;
}

int main(){
    vector<int> v = {30, 11, 23, 4, 20};
    cout << minEatingSpeed(v, 5);
}