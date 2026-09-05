class Twitter {
private:
    // Global timestamp to determine which tweet is newer.
    int timestamp = 0;

    // Store tweets for each user.
    // userId -> vector of {timestamp, tweetId}
    unordered_map<int, vector<pair<int, int>>> tweets;

    // Store who each user follows.
    // followerId -> set of followeeIds
    unordered_map<int, unordered_set<int>> following;

public:
    Twitter() {
        // Constructor.
        // No special initialization is required because
        // the data structures are initialized automatically.
    }

    void postTweet(int userId, int tweetId) {

        // Store the tweet along with the current timestamp.
        tweets[userId].push_back({timestamp, tweetId});

        // Increase timestamp so the next tweet is newer.
        timestamp++;
    }

    vector<int> getNewsFeed(int userId) {

        // Max heap.
        // Each element contains:
        // {timestamp, tweetId}
        //
        // The newest tweet will always be at the top.
        priority_queue<pair<int, int>> maxHeap;

        // Add the user's own tweets to the heap.
        for (auto tweet : tweets[userId]) {
            maxHeap.push(tweet);
        }

        // Add tweets from every user that this user follows.
        for (int followeeId : following[userId]) {

            for (auto tweet : tweets[followeeId]) {
                maxHeap.push(tweet);
            }
        }

        // Store the final 10 most recent tweets.
        vector<int> result;

        // Extract at most 10 newest tweets.
        while (!maxHeap.empty() && result.size() < 10) {

            // Get the newest tweet.
            result.push_back(maxHeap.top().second);

            // Remove it from the heap.
            maxHeap.pop();
        }

        return result;
    }

    void follow(int followerId, int followeeId) {

        // A user follows another user.
        following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {

        // Remove the follow relationship.
        following[followerId].erase(followeeId);
    }
};