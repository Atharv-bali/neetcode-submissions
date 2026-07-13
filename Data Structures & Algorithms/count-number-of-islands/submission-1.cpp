class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(),m=grid[0].size(),count=0;
        int row[4] = {-1,0,1,0};
        int col[4] = {0,-1,0,1};
    
        queue<pair<int,int>> q;

        for(int i=0;i<n;i++) { //O(N)
            for(int j=0;j<m;j++) { //O(M)
                if(grid[i][j] == '1') {
                    count++;
                    q.push({i,j});
                    grid[i][j]='0';
                    while(!q.empty()) {
                        int first = q.front().first;
                        int second = q.front().second;
                        q.pop();
                        for(int ind=0;ind<4;ind++) {
                            int newr = first+row[ind];
                            int newc = second+col[ind];
                            if(newr<n && newr>=0 && newc<m && newc>=0 && grid[newr][newc]=='1') {
                                grid[newr][newc] = '0';
                                q.push({newr,newc});
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
};
//Time complexity: O(N*M*4)
//Space complexity: O(N)
