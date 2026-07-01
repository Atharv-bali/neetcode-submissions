class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(),n=matrix[0].size();
        int l=0,r=m-1,row=-1,mid;
        while(l<=r) { //O(logm)
            mid = l+(r-l)/2;
            if(matrix[mid][0]==target)
                return true;
            else if(matrix[mid][0]<target)  {
                row=mid;
                l=mid+1;
            }
            else
                r=mid-1;
        }
        if(row==-1)
            row=0;
        l=0,r=n-1;
        while(l<=r) { //O(logn)
            mid = l+(r-l)/2;
            if(matrix[row][mid]==target)
                return true;
            else if(matrix[row][mid]<target)
                l=mid+1;
            else
                r=mid-1;
        }
        return false;
    }
};
//Time complexity: O(log(m)+log(n))
//Space complexity: O(1)