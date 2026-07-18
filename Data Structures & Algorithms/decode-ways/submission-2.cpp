class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+2,0);
        dp[n+1] = 1;
        dp[n] = 1;
        for(int i=n-1;i>=0;i--) {
            if(s[i]=='0')
                dp[i] = 0;
            else {
                int take_one = dp[i+1];
                int take_two=0;
                if(i+1<s.size() && (s[i]=='1' || s[i]=='2' && s[i+1]<='6')) 
                    take_two = dp[i+2];
                dp[i] = take_one + take_two;
            }
        } 
        return dp[0];
    }
};
//Time complexity: O(N+1)
//Space complexity: O(N+1)