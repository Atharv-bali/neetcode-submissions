class Solution {
public:
    int n;
    vector<string> result;
    unordered_map<string,vector<string>> adj;
    bool dfs(string fromAir, vector<string> &path) {
        path.push_back(fromAir);
        if(path.size() == n+1) {
            result = path;
            return true;
        }
        vector<string>& neighbors = adj[fromAir];
        for(int i=0;i<neighbors.size();i++) {
            string toAir = neighbors[i];
            neighbors.erase(neighbors.begin()+i);
            if(dfs(toAir,path))
                return true;
            neighbors.insert(neighbors.begin()+i,toAir);
        }
        path.pop_back();
        return false;
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        n = tickets.size();
        for(auto &it:tickets) {
            string u = it[0];
            string v = it[1];
            adj[u].push_back(v);
        }

        for(auto &it:adj) 
            sort(it.second.begin(),it.second.end());
        
        vector<string> path;
        dfs("JFK",path);
        return result;
    }
};
