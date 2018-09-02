#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Twitter {
private:
    struct Tweet {
        int id;
        int time;
        Tweet(int id, int time) : id(id), time(time) {}
    };

    int timeStamp = 0;
    unordered_map<int, vector<Tweet>> tweets;
    unordered_map<int, unordered_set<int>> following;
public:
    /** Initialize your data structure here. */
    Twitter() {
    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        tweets[userId].emplace_back(tweetId, timeStamp++);
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        struct compare {
            bool operator ()(const pair<Tweet *, Tweet *> &x, const pair<Tweet *, Tweet *> &y) {
                return x.second->time < y.second->time;
            }
        };
        priority_queue<pair<Tweet *, Tweet *>, vector<pair<Tweet *, Tweet *>>, compare> pq;
        for (auto &user: following[userId]) {
            auto &tweet = tweets[user];
            if (tweet.size() > 0)
                pq.emplace(tweet.data(), tweet.data()+tweet.size()-1);
        }
        if (tweets[userId].size() > 0)
            pq.emplace(tweets[userId].data(), tweets[userId].data()+tweets[userId].size()-1);
        int n = 10;
        vector<int> result;
        result.reserve(n);
        for (int i = 0; i < n && !pq.empty(); i++) {
            auto p = pq.top();
            pq.pop();
            result.push_back(p.second->id);
            if (p.first != p.second--)
                pq.push(p);
        }
        return result;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId)
            following[followerId].insert(followeeId);
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
            following[followerId].erase(followeeId);
    }
};

int main() {
    return 0;
}
