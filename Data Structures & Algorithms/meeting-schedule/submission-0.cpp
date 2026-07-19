/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        map<int,int> mpp;
        for(auto &it:intervals) {
            mpp[it.start]++;
            mpp[it.end]--;
        }
        int sum = 0;
        for(auto &it: mpp) {
            sum += it.second;
            if(sum>1)
                return false;
        }
        return true;
    }
};
//Time complexity: O(n)
//Space complexity: O(n)