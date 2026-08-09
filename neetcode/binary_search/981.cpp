#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;

class Timemap{
    public:
    unordered_map<string, vector<pair<int, string>>> umap;
    Timemap(){}

    void set(string key, string value, int timestamp){
        umap[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp){
        auto it = umap.find(key);
        if (it != umap.end()){
            int l = 0, h = it->second.size()-1;
            while (l<=h){
                int mid = (l+h)/2;
                if (it->second[mid].first == timestamp){
                    return it->second[mid].second;
                }
                if (it->second[mid].first > timestamp) h = mid-1;
                else l = mid+1;
            }
            if (l>0) return it->second[l-1].second;
            else return "";
        }
        else return "";
    }

};