class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>> pq;
        int n = stones.size();
        for(int i=0;i<n;i++) { //O(nlogn)
            pq.push(stones[i]);
        }
        while(pq.size()>1) { //O(n)
            int first = pq.top();
            pq.pop();
            int second = pq.top();
            pq.pop();
            pq.push(first-second);
        }
        return pq.top();
    }
};
//Time complexity: O(nlogn)
//Space complexity: O(n)