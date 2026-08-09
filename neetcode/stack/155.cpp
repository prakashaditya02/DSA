#include <vector>
#include <array>
#include <stack>

using namespace std;

// class Minstack {
//     public:
//         vector<pair<int, int>> arr;
//         int min;

//         Minstack(){
//         }
//         void push(int val){
//             if (arr.empty()) {
//                 min = val;
//                 arr.push_back({val, min});
//             }
//             else {
//                 min = (min < val) ? min : val;
//                 arr.push_back({val, min});
//             }
//         }
//         void pop(){
//             if (!arr.empty()){
//                 if (arr.size()-1 > 0) min = arr[arr.size()-1-1].second;
//             }
//             arr.pop_back();
//         }
//         int top(){
//             return arr[arr.size()-1].first;
//         }
//         int getMin(){
//             if (!arr.empty()){
//                 return arr[arr.size()-1].second;
//             }
//         }
// };

class MinStack {
public:
    vector<pair<int, int>> arr;
    int min;

    MinStack() {
    }
    
    void push(int val) {
        if (arr.empty()) min = val;
        else min = (min<val) ? min : val;
        arr.push_back({val, min});
    }
    
    void pop() {
        if (!arr.empty()){
            if (arr.size()-1 > 0) min = arr[arr.size()-1-1].second;
        }
        arr.pop_back();
    }
    
    int top() {
        return arr[arr.size()-1].first;
    }
    
    int getMin() {
        return arr.back().second;
    }
};
