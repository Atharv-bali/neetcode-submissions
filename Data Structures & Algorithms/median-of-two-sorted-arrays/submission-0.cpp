class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size(), j=0, i=0, k=0;
        vector<int> temp(m+n);
        while(i<n && j<m) { //O(min(n,m))
            if(nums1[i]>=nums2[j])
                temp[k++] = nums2[j++];
            else
                temp[k++] = nums1[i++];
        }
        while(i<n) 
            temp[k++] = nums1[i++];
        while(j<m)
            temp[k++] = nums2[j++];
        int size = m+n;
        if(size%2 == 1)
            return double(temp[size/2]);
        return (temp[size/2]+temp[size/2-1])/2.0;
    }
};
//Time complexity: O(max(n,m))
//Space complexity: O(m+n)