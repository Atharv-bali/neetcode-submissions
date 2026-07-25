class PrefixTree {
public:
    PrefixTree() {
        
    }

    struct TrieNode {
        bool isWord;
        TrieNode *child[26];
    };

    TrieNode* newnode() {
        TrieNode* temp = (TrieNode*)malloc(sizeof(TrieNode));
        temp->isWord = false;
        for(int i=0;i<26;i++) 
            temp->child[i] = nullptr;
        return temp;
    }
    TrieNode* curr = newnode();
    void insert(string word) {
        TrieNode* root = curr;
        int n = word.size();
        for(int i=0;i<n;i++) {
            int ind = word[i]-'a';
            if(!root->child[ind])
                root->child[ind] = newnode();
            root = root->child[ind];
        }
        root->isWord = true;
    }
    
    bool search(string word) {
        int n = word.size();
        TrieNode* root = curr;
        for(int i=0;i<n;i++) {
            int ind = word[i]-'a';
            if(!root->child[ind])
                return false;
            root = root->child[ind];
        }
        return root->isWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* root = curr;
        int n = prefix.size();
        for(int i=0;i<n;i++) {
            int ind = prefix[i]-'a';
            if(!root->child[ind])
                return false;
            root = root->child[ind];
        }
        return true;
    }
};
