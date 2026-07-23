class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int> mpp;
        int n = hand.size();
        if(n%groupSize != 0)
            return false;
        for(int &num:hand)
            mpp[num]++;
        while(!mpp.empty()) {
            int cont = mpp.begin()->first;
            for(int i=0;i<groupSize;i++) {
                if(mpp[cont+i]==0)
                    return false;
                mpp[cont+i]--;
                if(mpp[cont+i]==0)
                    mpp.erase(cont+i);
            }
        }
        return true;
    }
};
