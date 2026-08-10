class Solution {
public:
    struct TrieNode {
        TrieNode* child[26];
    };
    TrieNode* newnode() {
        TrieNode* temp = new TrieNode();
        for(int i=0;i<26;i++)
            temp->child[i] = NULL;
        return temp;
    }
    void insert(TrieNode* root, string str) {
        TrieNode* curr = root;
        for(int i=0;i<str.size();i++) {
            int ind = str[i]-'a';
            if(curr->child[ind] == NULL)
                curr->child[ind] = newnode();
            curr = curr->child[ind];
        }
    }
    string longestCommonPrefix(vector<string>& strs) {
        TrieNode* root = newnode();
        TrieNode* curr = root;
        int mini = 1e7;
        for(string &str:strs) {
            if(str == "")
                return "";
            insert(root,str);
            mini = min(mini,(int)str.size());
        }
        
        string res = strs[0];
        string st = "";
        for(int i=0;i<mini;i++) {
            int mark = 0;
            int cnt = 0;
            int ind = res[i]-'a';
            for(int in=0;in<26;in++) {
                if(curr->child[in]) {
                    cnt++;
                    mark = in;
                }
                if(cnt>=2)
                    return st;
            }
            if(cnt == 0)
                return st;
            else if(cnt==1) {
                st += res[i];
                curr = curr->child[mark];
            }
        }
        return st;
    }
};