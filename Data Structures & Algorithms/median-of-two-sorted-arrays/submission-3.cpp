class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size(),l=0,r=n;
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);
        while(l<=r) { //O(log(n+m))
            int px = l + (r-l)/2;
            int py = (m+n+1)/2-px;
            int x1 = px-1>=0 ? nums1[px-1]:-1e8;
            int x2 = px<n ? nums1[px]:1e8;
            int x3 = py-1>=0 ? nums2[py-1]:-1e8;
            int x4 = py<m ? nums2[py]:1e8;
            if(x1<=x4 && x3<=x2) {
                if((n+m)%2==1)
                    return max(x1,x3);
                return (min(x2,x4)+max(x1,x3))/2.0;
            }
            else if(x1>x4)
                r = px-1;
            else
                l = px+1;
        }
        return -1;
    }
};
//Time complexity: O(log(n+m))
//Space complexity: O(1)