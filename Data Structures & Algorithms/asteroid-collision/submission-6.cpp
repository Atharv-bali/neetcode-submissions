class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        for(int &asteroid:asteroids) {
            if(asteroid>=0) 
                s.push(asteroid);
            else {
                if(s.empty() || s.top()<0)
                    s.push(asteroid);
                else {
                    if(s.top()==abs(asteroid)) 
                        s.pop();
                    else if(s.top()<=abs(asteroid)) {
                        while(!s.empty() && s.top()>=0 && s.top()<abs(asteroid))
                            s.pop();
                        if(!s.empty() && s.top() == abs(asteroid))
                            s.pop();
                        else if(s.empty() || s.top()<0)
                            s.push(asteroid);
                    }
                }
            }
        }
        int n = s.size();
        if(n==0)
            return {};
        vector<int> res(n);
        while(!s.empty()) {
            res[n-1] = s.top();
            s.pop();
            n--;
        }
        return res;
    }
};
//Time complexity: O(2*n)
//Space complexity: O(2*n)