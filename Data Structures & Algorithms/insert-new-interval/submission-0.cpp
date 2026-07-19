class Solution {
public:
    static bool comp(const vector<int> &a, const vector<int> &b) {
        return a[0]<b[0];
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end(),comp);
        vector<vector<int>> res;
        int start = -1, end = -1, n = intervals.size();
        for(int i=0;i<=n;i++) {
            if(i==0) {
                start = intervals[i][0];
                end = intervals[i][1];
            }
            else if(i==n) {
                end = max(intervals[i-1][1],end);
                res.push_back({start,end});
            }
            else {
                if(intervals[i][0]>end) {
                    res.push_back({start,end});
                    end = max(end,intervals[i][1]);
                    start = intervals[i][0];
                }
                else 
                    end = max(end,intervals[i][1]);
            }
        }
        return res;
    }
};
