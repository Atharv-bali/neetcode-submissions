class Solution {
public:
    int countDays(int mid, vector<int> &weights) {
        int daysRequired = 1, currentLoad = 0;
        for(int &weight:weights) {
            if((currentLoad + weight) > mid) {
                daysRequired++;
                currentLoad = weight;
            }
            else
                currentLoad += weight;
        }
        return daysRequired;
    } 
    int shipWithinDays(vector<int>& weights, int days) {
        int sum = 0, n = weights.size(), ans = -1, maxi = 0;
        for(int &weight:weights) {
            sum += weight;
            maxi = max(maxi,weight);
        }
        int l = maxi, r = sum;
        while(l<=r) {
            int mid = l+(r-l)/2;
            if(countDays(mid,weights)<=days) {
                ans = mid;
                r = mid-1;
            }
            else
                l = mid+1;
        }
        return ans;
    }
};
//Time complexity: O(nlogn)
//Space complexity: O(1)