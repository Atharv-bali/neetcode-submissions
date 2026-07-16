class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0);
        queue<int> q;
        int cnt=0;
        for(auto &it:prerequisites) { //O(V)
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }
        for(int i=0;i<numCourses;i++) { //O(V)
            if(indegree[i]==0)
                q.push(i);
        }
        while(!q.empty()) { //O(E)
            cnt++;
            int node = q.front();
            q.pop();
            for(auto &it:adj[node]) {
                indegree[it]--;
                if(indegree[it]==0)
                    q.push(it);
            }
        }
        return cnt==numCourses;
    }
};
//Time complexity: O(V+E)
//Space complexity: O(V+E)