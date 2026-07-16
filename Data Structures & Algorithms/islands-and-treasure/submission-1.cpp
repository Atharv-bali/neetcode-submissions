class Solution {
public:
    int row[4] = {-1,1,0,0};
    int col[4] = {0,0,1,-1};
    void dfs(int i, int j, vector<vector<int>>& grid, int steps) {
        for(int ind=0;ind<4;ind++) { //O(4)
            int newr = i+row[ind];
            int newc = j+col[ind];  
            if(newr<0 || newc<0 || newr>=grid.size() || newc>=grid[0].size() || grid[newr][newc]<=(1+steps))
                continue;
            grid[newr][newc] = 1+steps;
            dfs(newr,newc,grid,1+steps);
        }
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int,pair<int,int>>> q;
        int row[4] = {-1,0,1,0};
        int col[4] = {0,-1,0,1};
        int n = grid.size(), m = grid[0].size();
        for(int i=0;i<n;i++) { //O(n)
            for(int j=0;j<m;j++) { //O(m)
                if(grid[i][j]==0)
                    dfs(i,j,grid,0);
            }
        }
    }
};
//Time complexity: O(n*m)
//Space complexity: O(n*m)