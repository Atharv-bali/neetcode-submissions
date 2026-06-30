class Solution {
public:
    int trap(vector<int>& height) {
        int res=0,h,w,n=height.size();
        stack<int> st;
        for(int i=0;i<n;i++) {
            while(!st.empty() && height[i]>=height[st.top()]) {
                int mid = height[st.top()];
                st.pop();
                if(!st.empty()) {
                    int right = height[i];
                    int left = height[st.top()];
                    int h = min(left,right)-mid;
                    int w = i-st.top()-1;
                    res += h*w;
                }
            }
            st.push(i);
        }
        return res;
    }
};
//Time complexity: O(n)
// Space complexity: O(n)