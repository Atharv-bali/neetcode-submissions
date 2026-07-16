class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int u) {
        if(u==parent[u])
            return u;
        return find(parent[u]);
    }
    void Union(int u, int v) {
        int ulp_u = find(u);
        int ulp_v = find(v);
        if(rank[ulp_u]<rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v]<rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_u] = ulp_v;
            rank[ulp_v]++;
        }

    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto &it:edges) { //O(E)
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n,0);
        rank.assign(n,0);
        parent.resize(n);
        for(int i=0;i<n;i++) { //O(V)
            parent[i] = i;
        }
        for(int i=0;i<n;i++) { //O(V)
            for(auto &it:adj[i]) { //O(E)
                if(find(it)==find(i)) 
                    continue;
                Union(it,i);
            }
        }
        set<int> st;
        for(int i=0;i<n;i++) 
            st.insert(find(i));
        return st.size();
    }
};
//Time complexity: O(V+E)
//Space complexity: O(V)