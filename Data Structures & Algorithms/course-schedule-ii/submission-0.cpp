class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses,0);
        vector<vector<int>> adj(numCourses);
        queue<int> q;
        for(auto &it:prerequisites) { //O(E)
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
        for(int i=0;i<numCourses;i++) { //O(V)
            if(indegree[i]==0)
                q.push(i);
        } 
        vector<int> res;
        while(!q.empty()) { //O(V)
            int node = q.front();
            q.pop();
            res.push_back(node);
            for(int &it: adj[node]) { //O(E)
                indegree[it]--;
                if(indegree[it]==0) 
                    q.push(it);
            }
        } 
        if(numCourses == res.size())
            return res;
        return {};
    }
};
//Time complexity: O(V+E)
//Space complexity: O(V+E)