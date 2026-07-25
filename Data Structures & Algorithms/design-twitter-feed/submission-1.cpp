class Twitter {
public:
    Twitter() {}

    map<int,set<int>> mpp;
    priority_queue<vector<int>> usertimeline;
    int curr = 0;
    
    void postTweet(int userId, int tweetId) {
        usertimeline.push({curr++,userId,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        int n = 0;
        vector<int> ans;
        priority_queue<vector<int>> timeline = usertimeline;
        while(!timeline.empty() && n< 10) { //O(nlogn)
            auto it = timeline.top();
            timeline.pop();
            if(userId == it[1] || mpp[userId].count(it[1])) {
                ans.push_back(it[2]);
                n++;
            }
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        mpp[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        mpp[followerId].erase(followeeId);
    }
};
//Time complexity: O(nlogn)
//Space complexity: O(2*n)