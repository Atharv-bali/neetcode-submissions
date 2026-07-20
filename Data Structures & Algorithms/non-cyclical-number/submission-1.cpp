class Solution {
public:
    int product(int n) {
        int res=0;
        while(n>0) {
            res += ((n%10)*(n%10));
            n = n/10;
        }
        return res;
    }
    bool isHappy(int n) {
        unordered_set<int> st;
        int squares = n;
        while(st.find(squares)==st.end()) {
            if(squares==1)
                return true;
            st.insert(squares);
            squares = product(squares);
        }
        return false;
    }
};
