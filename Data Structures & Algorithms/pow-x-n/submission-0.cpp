class Solution {
public:
    double myPow(double x, int n) {
        double res=1;
        int m = n;
        if(n<0)
            n = -n;
        while(n>0) {
            res = res*x;
            n--;
        }
        if(m<0) 
            res = 1/res;
        return res;
    }
};
