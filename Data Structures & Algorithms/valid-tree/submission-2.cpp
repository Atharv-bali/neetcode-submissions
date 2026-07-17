class Solution {
public:
    bool cycle(int node, int parent, vector<vector<int>> &adj, vector<int> &vis) {
        vis[node] = 1;
        for(auto &it:adj[node]) {
            if(!vis[it]) {
                if(cycle(it,node,adj,vis))
                    return true;
            }
            else if(it!=parent)
                return true;
        }
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int> vis(n,0);
        vector<vector<int>> adj(n);
        for(auto &it:edges) { //O(E)
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        if(cycle(0,-1,adj,vis)) //O(E)
            return false;
        for(int i=0;i<n;i++) {
            if(!vis[i])
                return false;
        }
        return true;
    }
};
//Time complexity: O(V+E)
//Space complexity: O(n)