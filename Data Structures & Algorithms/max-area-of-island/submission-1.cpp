class Solution {
public:
    int dfs(int i, int j, vector<vector<int>> &grid) {
        if(i>=grid.size() || i<0 || j>=grid[0].size() || j<0 || grid[i][j]==0)
            return 0;
        grid[i][j]=0;
        int ans = 1;
        int row[4] = {-1,0,1,0};
        int col[4] = {0,-1,0,1};
        for(int ind=0;ind<4;ind++) {
            int newr = i + row[ind];
            int newc = j + col[ind];
            ans += dfs(newr,newc,grid);
        }
        return ans;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(),m=grid[0].size(),count=0;

        for(int i=0;i<n;i++) { //O(N)
            for(int j=0;j<m;j++) { //O(M)
                if(grid[i][j]==1) {
                    count = max(count,dfs(i,j,grid));
                }
            }
        }
        return count;
    }
};
//Time complexity: O(N*M*4)
//Space complexitY: O(N*M)