class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mini=prices[0],profit=0;
        for(int i=0;i<n;i++) { //O(n)
            profit = max(profit,prices[i]-mini);
            mini = min(mini,prices[i]);
        }
        return profit;
    }
};
//Time complexity: O(n)
//Space complexity: O(n)