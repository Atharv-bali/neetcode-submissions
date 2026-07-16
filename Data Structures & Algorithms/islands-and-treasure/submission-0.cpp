class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int,pair<int,int>>> q;
        int row[4] = {-1,0,1,0};
        int col[4] = {0,-1,0,1};
        int n = grid.size(), m = grid[0].size();
        for(int i=0;i<n;i++) { //O(n)
            for(int j=0;j<m;j++) { //O(m)
                if(grid[i][j]==0)
                    q.push({0,{i,j}});
            }
        }
        while(!q.empty()) { 
            int step = q.front().first;
            int r = q.front().second.first;
            int c = q.front().second.second;
            q.pop();
            for(int i=0;i<4;i++) {
                int newr = r+row[i];
                int newc = c+col[i];
                if(newr<0 || newc<0 || newr>=n || newc>=m || grid[newr][newc]<=(1+step))
                    continue;
                grid[newr][newc] = 1+step;
                q.push({1+step,{newr,newc}});
            }
        }
    }
};
//Time complexity: O(n*m)
//Space complexity: O(n*m)