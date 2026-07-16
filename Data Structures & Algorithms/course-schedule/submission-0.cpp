class Solution {
public:
    bool dfs(int node, int numCourses, vector<vector<int>> &adj, stack<int> &st, vector<bool> &vis, vector<bool> &pathvis) {
        vis[node] = true;
        pathvis[node] = true;
        for(auto it:adj[node]) { //O(E)
            if(!vis[it]) {
                if(dfs(it,numCourses,adj,st,vis,pathvis))
                    return true;
            }
            else if(pathvis[it])
                return true;
        }
        pathvis[node] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> vis(numCourses,false);
        vector<bool> pathvis(numCourses,false);
        vector<vector<int>> adj(numCourses);
        stack<int> st;
        for(auto &it:prerequisites) {
            adj[it[0]].push_back(it[1]);
        }
        for(int i=0;i<numCourses;i++) { //O(V)
            if(!vis[i]) {
                if(dfs(i,numCourses,adj,st,vis,pathvis))
                    return false;
            }
        }
        return true;
    }
};
//Time complexity: O(V+E)
//Space complexity: O(V+E)