class Solution {
public:
    int count_bits(int n) {
        int sum = 0;
        while(n>0) {
            sum += n%2;
            n /= 2;
        }
        return sum;
    }
    vector<int> countBits(int n) {
        int sum=0;
        vector<int> res;
        for(int i=0;i<=n;i++) 
            res.push_back(count_bits(i));
        return res;
    }
};
