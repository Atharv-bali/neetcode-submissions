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
    int minMeetingRooms(vector<Interval>& intervals) {
        int sum=0,maxi=0;
        map<int,int> mpp;
        for(auto &it:intervals) {
            mpp[it.start]++;
            mpp[it.end]--;
        } 
        for(auto &it:mpp) {
            sum += it.second;
            maxi = max(maxi,sum);
        }
        return maxi;
    }
};
//Time complexitY: O(n)
//Space complexitY: O(n)