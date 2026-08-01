class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;
        int n = nums.size(),l=0,r=0;
        while(r<n) {
            if(dq.empty() || nums[dq.back()]>nums[r])
                dq.push_back(r);
            else {
                while(!dq.empty() && nums[dq.back()]<=nums[r])
                    dq.pop_back();
                dq.push_back(r);
            }
            if(r-l+1 == k) {
                ans.push_back(nums[dq.front()]);
                l++;
                if(dq.front()<l)
                    dq.pop_front();
            }
            r++;
        }
        return ans;
    }
};
//Time complexity: O(n)
//Space complexity: O(k)