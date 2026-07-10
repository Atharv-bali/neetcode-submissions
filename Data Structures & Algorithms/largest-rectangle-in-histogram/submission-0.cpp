class Solution {
public:
    vector<int> next(vector<int> &heights) {
        int n = heights.size();
        stack<int> st;
        vector<int> nse(n,n);
        for(int i=n-1;i>=0;i--) { //O(n)
            while(!st.empty() && heights[st.top()]>=heights[i]) //O(n)
                st.pop();
            
            nse[i] = st.empty()?n:st.top();
            st.push(i);
        }
        return nse;
    }
    vector<int> previous(vector<int> &heights) {
        int n = heights.size();
        stack<int> st;
        vector<int> pse(n,-1);
        for(int i=0;i<n;i++) { //O(n)
            while(!st.empty() && heights[st.top()]>=heights[i])  //O(n)
                st.pop();
            
            pse[i] = st.empty()?-1:st.top();
            st.push(i);
        }
        return pse;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(),maxArea = -1e7;
        vector<int> pse(n,-1);
        vector<int> nse(n,n);
        pse = previous(heights);
        nse = next(heights);
        for(int i=0;i<n;i++) //O(n)
            maxArea = max(maxArea,(heights[i])*(nse[i]-pse[i]-1));
        return maxArea;
    }
};
// Time complexity: O(6*n)
// Space complexitY: O(2*n)