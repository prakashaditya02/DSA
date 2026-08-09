#include <vector>
#include <iostream>

using namespace std;

int maxProfit(vector<int>& prices){
    int p = 0;

    for (int i=0; i < prices.size()-1; i++){
        if (prices[i]<prices[i+1]) p += (prices[i+1] - prices[i]);
    }
    return p;
}

int main(){
    vector<int> v = {7, 6, 4, 3, 1};
    cout << maxProfit(v);
}