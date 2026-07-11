class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size(), j=0, i=0, k=0;
        int size = m+n;
        int idx1=size/2-1,idx2=size/2,element1=-1,element2=-1;
        while(i<n && j<m) {  // O(min(n,m))
            if(nums1[i]>=nums2[j]) {
                if(idx1==k)
                    element1 = nums2[j];
                if(idx2==k)
                    element2 = nums2[j];
                j++;
            }
            else{
                if(idx2==k)
                    element2 = nums1[i];
                if(idx1==k)
                    element1 = nums1[i];
                i++;
            }
            k++;
        }
        while(i<n) {
            if(idx1==k) 
                element1 = nums1[i];
            if(idx2==k) 
                element2 = nums1[i];    
            i++;
            k++;
        }
        while(j<m) {
            if(idx1==k) 
                element1 = nums2[j];
            if(idx2==k) 
                element2 = nums2[j];    
            j++;
            k++;
        }
        if(size%2 == 1)
            return double(element2);
        return (element1+element2)/2.0;
    }
};
//Time complexity: O(max(n,m))
//Space complexity: O(1)