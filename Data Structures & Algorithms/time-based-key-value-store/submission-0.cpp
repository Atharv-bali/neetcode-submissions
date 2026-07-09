class TimeMap {
public:
    vector<pair<string,int>> vec;
    unordered_map<string,vector<pair<string,int>>> mpp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mpp[key].push_back({value,timestamp});
    }

    static bool comp(const pair<string,int> &a, const pair<string,int> &b) {
        return a.second<b.second;
    }
    
    string get(string key, int timestamp) {
        if(mpp.find(key)==mpp.end())
            return "";
        vec = mpp[key];
        sort(vec.begin(),vec.end(),comp); //O(nlogn)
        string ans="";
        for(int i=0;i<vec.size();i++) { //O(n)
            if(timestamp>=vec[i].second)
                ans = vec[i].first;
        }
        return ans;
    }
};
//Time complexity: O(nlogn+n)
//Space complexity: O(n)