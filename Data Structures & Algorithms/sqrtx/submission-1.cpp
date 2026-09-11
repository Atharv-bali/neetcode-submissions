class Solution {
public:
    int mySqrt(int x) {
        if(x == 0)
            return x;
        int l = 1, r = x, ans = 0;
        while(l<=r) {
            int mid = l+(r-l)/2;
            if(mid == x/mid) 
                return mid;
            else if(mid > x/mid) 
                r = mid-1;
            else {
                ans = mid;
                l = mid+1;
            }
        }
        return ans;
    }
};
//Time complexity: O(logn)
//Space complexity: O(1)