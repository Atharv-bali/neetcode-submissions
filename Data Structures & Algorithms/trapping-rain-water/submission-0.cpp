class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), sum = 0;
        vector<int> left(n,0),right(n,0);
        left[0] = height[0];
        right[n-1] = height[n-1];
        for(int i=1;i<n;i++) //O(n)
            left[i] = max(left[i-1],height[i]);
        for(int i=n-2;i>=0;i--) //O(n)
            right[i] = max(right[i+1],height[i]);
        for(int i=1;i<n-1;i++) { //O(n)
            if(height[i]<right[i+1] && height[i]<left[i-1]) {
                sum += min(abs(height[i]-right[i+1]),abs(height[i]-left[i-1]));
            }
        }
        return sum;
    }
};
//Time complexity: O(n)
// Space complexity: O(n)