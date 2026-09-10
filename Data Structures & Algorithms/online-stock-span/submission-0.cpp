class StockSpanner {
public:
    stack<pair<int,int>> s;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int count = 1;
        while(!s.empty() && s.top().first<=price) { //O(n)
            count += s.top().second;
            s.pop();
        }
        s.push({price,count});
        return count;
    }
};
//Time complexity: O(n)
//Space complexity: O(n)
/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */