class Trie {
    private:
    bool isEnd;
    Trie* next[26];
public:
    /** Initialize your data structure here. */
    Trie() {
        isEnd = false;
        memset(next,0,sizeof(next));
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* root = this;
        for (auto ch:word) {
            if (root->next[ch - 'a'] == 0) {
                root->next[ch - 'a'] = new Trie();
            }
            root = root->next[ch - 'a'];
        }
        root->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* root = this;
        for (auto ch:word) {
            if (root->next[ch - 'a'] == NULL) {
                return false;
            }
            root = root->next[ch -'a'];
        }
        return root->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* root = this;
        for (auto ch:prefix) {
            if (root->next[ch - 'a'] == NULL) {
                return false;
            }
            root = root->next[ch -'a'];
        }
        return true;
    }
};
