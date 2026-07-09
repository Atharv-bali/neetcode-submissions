class Solution {
public:
    int solve(int mid, vector<int> &piles, int h) {
        int res,cnt=0;
        for(int i=0;i<piles.size();i++) {
            res = piles[i]/mid;
            if(piles[i]%mid!=0)
                res++;
            cnt+=res;
        }
        return cnt;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi=0,res=-1;
        for(int &pile:piles)
            maxi = max(maxi,pile);
        int l=1,r=maxi,mid;
        while(l<=r) { //O(logn)
            mid = l + (r-l)/2;
            int ans = solve(mid,piles,h); //O(n)
            if(ans>h) 
                l = mid+1;
            else {
                res = mid;
                r = mid - 1;
            }
        }
        return res;
    }
};
//Time complexity: O(nlogn)
//Space complexity: O(1)