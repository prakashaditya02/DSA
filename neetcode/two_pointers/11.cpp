#include <vector>
#include <iostream>

using namespace std;

int maxArea(vector<int>& height){
    int i = 0, j = height.size()-1;
    int maxAr = 0;
    while (i<j){
        int h = (height[i] < height[j]) ? height[i] : height[j];
        if (maxAr < (h*(j-i))) maxAr = h*(j-i);

        if (height[i] < height[j]){
            i++;
        } else {
            j--;
        }
    }
    return maxAr;
}

int main(){
    vector<int> a {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << maxArea(a);
}