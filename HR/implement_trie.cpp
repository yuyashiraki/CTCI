class Trie {
public:
    class Node {
    public:
        bool word;
        map<char, Node*> children;
        Node() {
            word = false;
        }
    };
    Node *head;
    /** Initialize your data structure here. */
    Trie() {
        head = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Node *cur = head;
        for (int i = 0; i < word.size(); i++) {
            if (!cur->children.count(word[i])) {
                cur->children[word[i]] = new Node();
            }
            cur = cur->children[word[i]];
        }
        cur->word = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node *cur = head;
        for (int i = 0; i < word.size(); i++) {
            if (!cur->children.count(word[i])) {
                return false;
            }
            cur = cur->children[word[i]];
        }
        return cur->word;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node *cur = head;
        for (int i = 0; i < prefix.size(); i++) {
            if (!cur->children.count(prefix[i])) {
                return false;
            }
            cur = cur->children[prefix[i]];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
