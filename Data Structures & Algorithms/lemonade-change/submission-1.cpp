class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int,int> mpp;
        for(int &bill:bills) {
            if(bill == 5)
                mpp[5]++;
            else if(bill == 10) {
                if(mpp[5]<=0)
                    return false;
                else {
                    mpp[5]--;
                    mpp[10]++;
                }
            }
            else if(bill == 20) {
                if(mpp[10]>0 && mpp[5]>0) {
                    mpp[10]--;
                    mpp[5]--;
                    mpp[20]++;
                }
                else if(mpp[5]>=3) {
                    mpp[5] -= 3;
                    mpp[20]++;
                }
                else
                    return false;
            }
        }
        return true;
    }
};
//Time complexity: O(n)
//Space complexity: O(n)