class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int n = people.size(),cnt = 0;
        int l = 0, r = n-1;
        while(l<=r) {
            if((people[l] + people[r])<=limit) {
                cnt ++;
                l++;
                r--;
            }
            else {
                cnt++;
                r--;
            }
        }
        return cnt;
    }
};
//Time complexity: O(nlogn)
//Space complexity: O(1)