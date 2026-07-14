class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        int num = tasks.size(),res=0;
        vector<int> mp(26,0);  

        for(int i=0;i<num;i++) //O(num)
            mp[tasks[i]-'A']++;

        for(int i=0;i<26;i++) { //O(26log26)
            if(mp[i]>0)
                pq.push(mp[i]);
        }

        while(!pq.empty()) { 
            vector<int> temp;
            for(int i=1;i<=n+1;i++) {
                if(!pq.empty()) {
                    int freq = pq.top();
                    pq.pop();
                    freq--;
                    temp.push_back(freq);
                }
            }
            for(int &f:temp) {
                if(f>0)
                    pq.push(f);
            }

            if(pq.empty()) {
                res += temp.size();
            }
            else
                res += n+1;
        }
        return res;
    }
};
//Time complexity: O(numlognum)
//Space complexity: O(26)