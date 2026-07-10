class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = speed.size(),fleet=0;
        priority_queue<pair<int,pair<int,double>>, vector<pair<int,pair<int,double>>>> pq;
        for(int i=0;i<n;i++) { //O(nlogn)
            double time = double(target-position[i])/speed[i];
            pq.push({position[i],{speed[i],time}});
        }
        while(true) { //O(nlogn)
            if(pq.size()==1) {
                fleet++;
                break;
            }
            auto ahead = pq.top();
            pq.pop();
            auto behind = pq.top();
            pq.pop();
            double ahead_time = ahead.second.second;
            double behind_time = behind.second.second;
            if(ahead_time>=behind_time) {
                pq.push(ahead);
            }
            else {
                fleet++;
                pq.push(behind);
            }
        }
        return fleet;
    }
};
//Time complexity: O(nlogn + nlogn)
//Space complexity: O(n)