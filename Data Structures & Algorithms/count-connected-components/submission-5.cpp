class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        int cnt=0;
        for(auto &it:edges) { //O(E)
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n,0);
        queue<int> q;
        for(int i=0;i<n;i++) { //O(V)
            if(!vis[i]) {
                cnt++;
                q.push(i);
                while(!q.empty()) { //O(E)
                    int node = q.front();
                    q.pop();
                    for(auto &it:adj[node]) {
                        if(!vis[it]) {
                            vis[it]=1;
                            q.push(it);
                        }
                    }
                }
            }
        }
        return cnt;
    }
};
//Time complexity: O(V+E)
//Space complexity: O(V+E)