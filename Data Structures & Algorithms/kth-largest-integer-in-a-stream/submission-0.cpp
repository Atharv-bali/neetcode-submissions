class KthLargest {
public:
    int klarge;
    priority_queue<int,vector<int>, greater<int>> pq;
    KthLargest(int k, vector<int>& nums) {
        klarge = k;
        for(int i=0;i<nums.size();i++) { //O(nlogk)
            pq.push(nums[i]);
            if(pq.size()>klarge)
                pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>klarge) {
            pq.pop();
        }
        return pq.top();
    }
};
//Time complexity: O(nlogk)
//Space complexity: O(k)