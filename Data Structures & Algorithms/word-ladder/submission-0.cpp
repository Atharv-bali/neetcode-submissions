class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());
        queue<pair<int,string>> q;
        q.push({1,beginWord});
        while(!q.empty()) { //O(n)
            int steps = q.front().first;
            string word = q.front().second;
            st.erase(word);
            q.pop();
            if(endWord == word)
                return steps;
            for(int i=0;i<word.size();i++) { //O(no of char)
                char original = word[i];
                for(char ch='a';ch<='z';ch++) { //O(26)
                    word[i] = ch;
                    if(st.find(word)!=st.end())
                        q.push({steps+1,word});
                }
                word[i] = original;
            }
        }
        return 0;
    }
};
//Time complexity: O(N*L^2*26)
//Space complexity: O(N*L)