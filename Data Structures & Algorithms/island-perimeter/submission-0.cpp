class Solution {
public:
    int count = 0;
    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>> &vis) {
        if(vis[i][j]==1)
            return;
        vis[i][j] = 1;
        int row[4] = {-1,0,1,0};
        int col[4] = {0,1,0,-1};
        for(int ind=0;ind<4;ind++) {
            int newr = i+row[ind];
            int newc = j+col[ind];
            if(newr<0 || newc<0 || newr>=grid.size() || newc>=grid[0].size() || grid[newr][newc]==0) {
                count++;
                continue;
            }
            dfs(newr,newc,grid,vis);
        }
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j] && !vis[i][j])
                    dfs(i,j,grid,vis);
            }
        }
        return count;
    }
};
//Time complexity: O(n*m)
// Space complexity: O(n*m)