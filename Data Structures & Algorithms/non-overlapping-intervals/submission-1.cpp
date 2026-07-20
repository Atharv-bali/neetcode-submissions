class Solution {
public:
    static bool comp (const vector<int>& a, const vector<int>& b) {
        return a[1]<b[1];
    }
    int solve(int i, int prev, vector<vector<int>> &intervals, vector<vector<int>> &dp) {
        if(i>=intervals.size())
            return 0;
        if(dp[i][prev+1]!=-1)
            return dp[i][prev];
        int take=1e8,nottake=1e8;
        if(prev==-1 || intervals[i][0]>=intervals[prev][1])
            take = solve(i+1,i,intervals,dp);
        else if (intervals[i][0]<intervals[prev][1])
            nottake = 1+solve(i+1,prev,intervals,dp);
        return dp[i][prev+1] = min(take,nottake);
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        int n = intervals.size(),m=intervals[0].size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(0,-1,intervals,dp);
    }
};
