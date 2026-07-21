class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        int power = 31;
        while(n>0) {
            if(n%2) 
                res += pow(2,power);
            power--;
            n/=2;
        }
        return res;
    }
};
