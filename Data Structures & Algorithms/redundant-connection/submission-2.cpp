class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int u) {
        if(u==parent[u])
            return u;
        return parent[u] = find(parent[u]);
    }
    void Union(int u, int v) {
        int ulp_u = find(u);
        int ulp_v = find(v);
        if(rank[ulp_u]<rank[ulp_v])
            parent[ulp_u] = ulp_v;
        else if(rank[ulp_v]<rank[ulp_u])
            parent[ulp_v] = ulp_u;
        else {
            parent[ulp_u] = ulp_v;
            rank[ulp_v]++;
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n);
        rank.resize(n+1,0);
        parent.resize(n+1,0);
        for(int i=0;i<n;i++) 
            parent[i] = i;
        for(auto &it:edges) {
            if(find(it[0])==find(it[1]))
                return {it[0],it[1]};
            Union(it[0],it[1]);
        }
        return {};
    }
};
//Time complexity: O(n*alpha(n))
//Space complexity: O(n)