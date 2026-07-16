class Solution {
public:
    int bfs(int i, int j, vector<vector<int>> &grid) {
        queue<pair<int,int>> q;
        int count = 0;
        q.push({i,j});
        grid[i][j] = 0;
        int row[4] = {-1,1,0,0};
        int col[4] = {0,0,1,-1};
        while(!q.empty()) {
            count++;
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int ind=0;ind<4;ind++) {
                int newr = r+row[ind];
                int newc = c+col[ind];
                if(newr<0 || newc<0 || newr>=grid.size() || newc >= grid[0].size() || grid[newr][newc]==0)
                    continue;
                q.push({newr,newc});
                grid[newr][newc]=0;
            }
        }
        return count;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(),m=grid[0].size(),count=0;

        for(int i=0;i<n;i++) { //O(N)
            for(int j=0;j<m;j++) { //O(M)
                if(grid[i][j]==1) {
                    count = max(count,bfs(i,j,grid));
                }
            }
        }
        return count;
    }
};
//Time complexity: O(N*M*4)
//Space complexitY: O(N)