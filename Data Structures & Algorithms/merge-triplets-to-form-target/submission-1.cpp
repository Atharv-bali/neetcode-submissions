class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int n = triplets.size();
        vector<int> maxValues(target.size(),0);
        for(int i=0;i<n;i++) {
            if(target[0]>=triplets[i][0] && target[1]>=triplets[i][1] && target[2]>=triplets[i][2]) {
                maxValues[0] = max(maxValues[0],triplets[i][0]);
                maxValues[1] = max(maxValues[1],triplets[i][1]);
                maxValues[2] = max(maxValues[2],triplets[i][2]);
            }
        }
        return maxValues[0] == target[0] && maxValues[1] == target[1] && maxValues[2] == target[2];
    }
};