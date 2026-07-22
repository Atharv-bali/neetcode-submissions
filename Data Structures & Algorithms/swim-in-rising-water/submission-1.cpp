class Solution {
public:
    bool dfs(int i, int j, int t, vector<vector<int>>& grid, vector<vector<bool>>& vis) {
        if(i>=grid.size() || j>=grid[0].size() || i<0 || j<0 || grid[i][j]>t || vis[i][j])
            return false;
        vis[i][j] = true;
        if(i==grid.size()-1 && j==grid[0].size()-1)
            return true;
        int row[4] = {-1,0,1,0};
        int col[4] = {0,1,0,-1};
        for(int ind=0;ind<4;ind++) {
            int newr = i+row[ind];
            int newc = j+col[ind];
            if(dfs(newr,newc,t,grid,vis))
                return true;
        }
        return false;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size(),ans=-1;
        int left=0,right=n*n-1;
        while(left<=right) {
            int mid = left + (right-left)/2;
            vector<vector<bool>> vis(n,vector<bool>(n,false));
            if(dfs(0,0,mid,grid,vis)) {
                ans = mid;
                right = mid-1;
            }
            else
                left = mid+1;
        }
        return ans;
    }
};
//Time complexity: O(n^2*logn)
//Time complexity: O(n*n) + auxillary space