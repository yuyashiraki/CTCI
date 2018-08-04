class WordDictionary {
public:
    class TrieNode {
    public:
        bool end;
        vector<TrieNode*> next;
        TrieNode() {
            next = vector<TrieNode*>(26, NULL);
            end = false;
        }
    };
    TrieNode *root;

    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode *cur = root;
        for (int i = 0; i < word.size(); i++) {
            if (NULL == cur->next[word[i] - 'a']) {
                cur->next[word[i]-'a'] = new TrieNode();
            }
            cur = cur->next[word[i]-'a'];
        }
        cur->end = true;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search(word, 0, root);
    }
    bool search(string word, int pos, TrieNode *cur) {
        if (word.size() == pos) {
            if (cur->end) return true;
            else return false;
        }
        bool ans = false;
        if ('.' == word[pos]) {
            for (int i = 0; i < 26; i++) {
                if (cur->next[i]) ans |= search(word, pos+1, cur->next[i]);
            }
        } else {
            if (cur->next[word[pos]-'a']) ans = search(word, pos+1, cur->next[word[pos] - 'a']);
        }
        return ans;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
