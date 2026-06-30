class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l=0,r=heights.size()-1,mul,maxi=0;
        while(l<r) {
            mul=1;
            if(heights[l]>heights[r]) {
                mul = heights[r]*(r-l);
                r--;
            }
            else {
                mul = heights[l]*(r-l);
                l++;
            }
            maxi = max(maxi,mul);
        }
        return maxi;
    }
};
//Time complexity: O(n)
//Space complexity: O(1)