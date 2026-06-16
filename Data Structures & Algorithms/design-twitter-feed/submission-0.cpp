
class Twitter {
   int timestamp;
    
    // userId -> vector of pairs {timestamp, tweetId}
    std::unordered_map<int, std::vector<std::pair<int, int>>> userTweets;
    
    // userId -> set of userIds that this user follows
    std::unordered_map<int, std::unordered_set<int>> following;
public:
    Twitter() {
        timestamp = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        userTweets[userId].push_back({timestamp++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        // Max-heap stores: {timestamp, {tweetId, {user_tweet_vector_index, next_tweet_index}}}
        // Using a tuple-like structure via nested pairs, or a custom struct
        typedef std::pair<int, std::pair<int, std::pair<const std::vector<std::pair<int, int>>*, int>>> HeapNode;
        std::priority_queue<HeapNode> maxHeap;

        // A user always sees their own tweets in their news feed
        following[userId].insert(userId);

        // Gather the single latest tweet from the user and everyone they follow
        for (int followeeId : following[userId]) {
            const auto& tweets = userTweets[followeeId];
            if (!tweets.empty()) {
                int lastIdx = tweets.size() - 1;
                // Push: {timestamp, {tweetId, {&tweets_vector, index_in_vector}}}
                maxHeap.push({tweets[lastIdx].first, {tweets[lastIdx].second, {&tweets, lastIdx}}});
            }
        }

        std::vector<int> newsFeed;
        
        // Pull up to 10 of the most recent tweets
        while (!maxHeap.empty() && newsFeed.size() < 10) {
            auto topNode = maxHeap.top();
            maxHeap.pop();

            int tweetId = topNode.second.first;
            const auto* tweetVec = topNode.second.second.first;
            int currIdx = topNode.second.second.second;

            newsFeed.push_back(tweetId);

            // If this user has more tweets left, push their next most recent tweet into the heap
            if (currIdx > 0) {
                int nextIdx = currIdx - 1;
                maxHeap.push({(*tweetVec)[nextIdx].first, {(*tweetVec)[nextIdx].second, {tweetVec, nextIdx}}});
            }
        }

        return newsFeed;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            following[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
       if (followerId != followeeId) {
            following[followerId].erase(followeeId);
        } 
    }
};
