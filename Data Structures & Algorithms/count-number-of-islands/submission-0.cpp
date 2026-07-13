class Solution {
public:
    void dfs(int ind, int j, vector<vector<char>> &grid) {
        grid[ind][j] = '0';
        int row[4] = {-1,0,1,0};
        int col[4] = {0,1,0,-1};
        for(int i=0;i<4;i++) {
            if(ind+row[i]<grid.size() && ind+row[i]>=0 && j+col[i]<grid[0].size() && j+col[i]>=0 && grid[ind+row[i]][j+col[i]]=='1') 
                dfs(ind+row[i],j+col[i],grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(),m=grid[0].size(),count=0;
        for(int i=0;i<n;i++) { //O(N)
            for(int j=0;j<m;j++) { //O(M)
                if(grid[i][j] == '1') {
                    dfs(i,j,grid);
                    count++;
                }
            }
        }
        return count;
    }
};
//Time complexity: O(N*M*4)
//Space complexity: O(1)
