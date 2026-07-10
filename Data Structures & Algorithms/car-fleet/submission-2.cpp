class Solution {
public:
    static bool comp(const pair<int,pair<int,double>> &a, const pair<int,pair<int,double>> &b) {
        return a.first>b.first;
    }
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = speed.size(),fleet=0;
        double prev=0;
        // priority_queue<pair<int,pair<int,double>>, vector<pair<int,pair<int,double>>>> pq;
        vector<pair<int,pair<int,double>>> vec;
        for(int i=0;i<n;i++) { //O(n)
            double time = double(target-position[i])/speed[i];
            vec.push_back({position[i],{speed[i],time}});
        }
        sort(vec.begin(),vec.end(),comp); //O(nlogn)
        for(int i=0;i<n;i++) { //O(n)
            if(vec[i].second.second>prev) {
                fleet++;
                prev = vec[i].second.second;
            }
        }
        return fleet;
    }
};
//Time complexity: O(nlogn + 2*n)
//Space complexity: O(n)