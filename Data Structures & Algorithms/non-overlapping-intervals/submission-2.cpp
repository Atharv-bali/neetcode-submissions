class Solution {
public:
    static bool comp (const vector<int>& a, const vector<int>& b) {
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        int n = intervals.size(),count=0;
        int prev=intervals[0][1];
        for(int i=1;i<n;i++) {
            if(prev<=intervals[i][0]) 
                prev = intervals[i][1];
            else
                count++;
        }
        return count;
    }
};
//Time complexity: O(n)
//Space complexity: O(n)