#include <vector>
#include <queue>
#include <tuple>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Twitter {
    int timestamp = 0;

    unordered_map<int, vector<pair<int, int>>> Tweets;
    unordered_map<int, unordered_set<int>> Follows;

public:
    Twitter(){

    }

    void postTweet(int userId, int tweetId){
        if (Tweets.find(userId) != Tweets.end()){
            Tweets[userId].push_back(make_pair(tweetId, timestamp));
        } else {
            vector<pair<int, int>> v = {make_pair(tweetId, timestamp)};
            Tweets[userId] = v;
        }
        timestamp += 1;
    }

    void follow(int followerId, int followeeId){
        if (followerId == followeeId) return;
        
        if (Follows.find(followerId) != Follows.end()){
            Follows[followerId].insert(followeeId);
        } else {
            unordered_set<int> us = {followeeId};
            Follows[followerId] = us;
        }
    }

    void unfollow(int followerId, int followeeId){
        if (followerId == followeeId) return;

        if (Follows.find(followerId) != Follows.end()){
            Follows[followerId].erase(followeeId);
        } else return;
    }

    vector<int> getNewsfeed(int userId){
        vector<int> output;
        priority_queue<tuple<int, int, int, int>> pq; //timestamp, tweetId, userId, index
        for (int x : Follows[userId]){
            if (Tweets[x].empty()) continue;
            auto [a, b] = Tweets[x].back();
            tuple<int, int, int, int> t = {b, a, x, 1};
            pq.push(t);
        }

        if (!Tweets[userId].empty()){
            auto [a, b] = Tweets[userId].back();
            pq.push(make_tuple(b, a, userId, 1));
        }

        while(!(output.size() == 10) && !pq.empty()){
            auto [a, b, c, d] = pq.top();
            pq.pop();
            output.push_back(b);
            if (d < Tweets[c].size()){
                auto [twID, tstamp] = Tweets[c][Tweets[c].size() - d-1];
                pq.push(make_tuple(tstamp, twID, c, d+1));
            }
        }
        return output;
    }
};