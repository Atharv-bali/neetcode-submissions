class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totg=0,totc=0,curr=0,start=0;
        int n = cost.size();
        for(int i=0;i<n;i++) {
            totg += gas[i];
            totc += cost[i];
            curr += (gas[i]-cost[i]);
            if(curr<0) {
                start = i+1;
                curr = 0;
            }
        }
        return totg<totc?-1:start;
    }
};
//Time complexity: O(n)
//Space complexity: O(1)