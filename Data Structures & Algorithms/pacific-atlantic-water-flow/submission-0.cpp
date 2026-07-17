class Solution {
public:
    int row[4] = {-1,0,1,0};
    int col[4] = {0,1,0,-1};
    void dfs(vector<vector<int>>& heights, int i, int j, int prevCell, vector<vector<bool>>& vis) {
        if(i<0 || j<0 || i>=heights.size() || j>=heights[0].size())
            return;
        if(prevCell>heights[i][j] || vis[i][j])
            return;
        vis[i][j] = true;
        for(int ind=0;ind<4;ind++) {
            int newr = i+row[ind];
            int newc = j+col[ind];
            if(newr<0 || newc<0 || newr>=heights.size() || newc>=heights[0].size() || vis[newr][newc])
                continue;
            dfs(heights,newr,newc,heights[i][j],vis);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(),m=heights[0].size();
        vector<vector<int>> result;
        vector<vector<bool>> pacific(n,vector<bool> (m,false));
        vector<vector<bool>> atlantic(n,vector<bool> (m,false));
        for(int j=0;j<m;j++) { //O(m)
            dfs(heights,0,j,-1e8,pacific); //O(n)
            dfs(heights,n-1,j,-1e8,atlantic); //O(n)
        }
        for(int i=0;i<n;i++) { //O(n)
            dfs(heights,i,0,-1e8,pacific); //O(m)
            dfs(heights,i,m-1,-1e8,atlantic); //O(m)
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(pacific[i][j] && atlantic[i][j])
                    result.push_back({i,j});
            }
        }
        return result;
    }
};
//Time complexity: O(n*m)
//Space complexity: O(n*m)