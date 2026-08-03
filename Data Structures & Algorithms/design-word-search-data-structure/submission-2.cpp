class WordDictionary {
public:
    WordDictionary() {
        
    }
    
    struct TrieNode {
        bool isWord;
        TrieNode* child[26];
    };

    TrieNode* newnode() {
        TrieNode* temp = new TrieNode();
        temp->isWord = false;
        for(int i=0;i<26;i++)
            temp->child[i] = nullptr;
        return temp;
    }
    TrieNode* root = newnode();
    void addWord(string word) {
        TrieNode* curr = root;
        int n = word.size();
        for(int i=0;i<n;i++) {
            int ind = word[i]-'a';
            if(!curr->child[ind])
                curr->child[ind] = newnode();
            curr = curr->child[ind];
        }
        curr->isWord = true;
    }
    
    bool dfs(int i, string &word, TrieNode* curr) {
        // if(curr == nullptr)
        //     return false;
        if(i==word.size())
            return curr->isWord;
        if(word[i]=='.') {
            for(int ind=0;ind<26;ind++) {
                if(curr->child[ind]) {
                    if(dfs(i+1,word,curr->child[ind]))
                        return true;
                }
            }
            return false;
        }
        else {
            int ind = word[i]-'a';
            if(!curr->child[ind])
                return false;
            return dfs(i+1,word,curr->child[ind]);
        }
        return true;
    }

    bool search(string word) {
        TrieNode* curr = root;
        return dfs(0,word,curr);
    }
};
