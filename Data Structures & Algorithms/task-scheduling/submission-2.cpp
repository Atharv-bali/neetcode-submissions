class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> mp(26,0);
        int num = tasks.size();
        for(int i=0;i<num;i++) {
            mp[tasks[i]-'A']++;
        }
        sort(mp.begin(),mp.end()); //O(numlognum)
        int maxFreq = mp[25];
        int gaps = maxFreq-1;
        int idleslot = gaps*n;
        for(int i=24;i>=0;i--) {
            idleslot -= min(gaps,mp[i]);
        }
        if(idleslot > 0) 
            return idleslot + tasks.size();
        return tasks.size();
    }
};
//Time complexity: O(numlognum)
//Space complexity: O(26)