class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(),m=grid[0].size(),maxt=0;
        int row[4] = {-1,0,1,0};
        int col[4] = {0,-1,0,1};
        queue<pair<int,pair<int,int>>> q;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j]==2) {
                    q.push({0,{i,j}});
                    grid[i][j] = 0;
                }
            }
        }
        while(!q.empty()) {
            int time = q.front().first;
            int r = q.front().second.first;
            int c = q.front().second.second;
            maxt = max(maxt,time);
            q.pop();
            for(int ind=0;ind<4;ind++) {
                int newr = r+row[ind];
                int newc = c+col[ind];
                if(newr<0 || newc<0 || newr>=grid.size() || newc>=grid[0].size() || grid[newr][newc]!=1)
                    continue;
                q.push({time+1,{newr,newc}});
                grid[newr][newc] = 0;
            }
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j]==1) 
                    return -1;
            }
        }
        return maxt;
    }
};
//Time complexity: O(n*m)
//Space complexity: O(n*m)