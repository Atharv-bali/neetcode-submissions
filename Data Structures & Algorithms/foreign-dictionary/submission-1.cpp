class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        int n = words.size();
        unordered_set<char> unique;
        for(string &s:words) {
            for(char &ch:s) 
                unique.insert(ch);
        }
        string res = "";
        vector<int> indegree(26,0);
        vector<vector<int>> adj(26);
        for(int ind=0;ind<n-1;ind++) {
            bool diff=false;
            string word1 = words[ind];
            string word2 = words[ind+1];
            for(int i=0;i<min(word1.size(),word2.size());i++) {
                if(word1[i]!=word2[i]) {
                    diff = true;
                    adj[word1[i]-'a'].push_back(word2[i]-'a');
                    indegree[word2[i]-'a']++;
                    break;
                }
            }
            if(!diff && word1.size()>word2.size())
                return "";
        }
        queue<int> q;
        string result = "";
        for(char c:unique) {
            if(indegree[c-'a']==0)
                q.push(c-'a');
        }
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            result = result + char(node+'a');
            for(int &it:adj[node]) {
                indegree[it]--;
                if(indegree[it]==0)
                    q.push(it);
            }
        }
        return result.size()==unique.size()?result:"";
    }
};
