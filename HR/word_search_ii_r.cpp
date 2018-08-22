class Solution {
public:
    // Trie + Backtracking
    // Time O(3^(max len of words))  Space O(max len of words)
    class TrieNode {
    public:
        bool end;
        string word;
        unordered_map<char, TrieNode*> children;
        TrieNode() {
            end = false;
            word = "";
        }
        ~TrieNode() {
            for (auto itr = children.begin(); itr != children.end(); ++itr) {
                delete itr->second;
            }
        }
    };
    void search(set<string> &ans, TrieNode *root, vector<vector<char>> &board, int x, int y) {
        if (!root->children.count(board[y][x])) return;
        //cout << x << " " << y << " " << board[y][x] << endl;
        char tmp = board[y][x];
        TrieNode *cur = root->children[board[y][x]];
        board[y][x] = '#';
        if (cur && cur->end) {
            ans.insert(cur->word);
        }
        if (x > 0) search(ans, cur, board, x - 1, y);
        if (x + 1 < board[0].size()) search(ans, cur, board, x + 1, y);
        if (y > 0) search(ans, cur, board, x, y - 1);
        if (y + 1 < board.size()) search(ans, cur, board, x, y + 1);
        board[y][x] = tmp;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        set<string> ans;
        vector<string> ansv;
        for (int i = 0; i < words.size(); i++) {
            string word = words[i];
            TrieNode* cur = root;
            for (int j = 0; j < word.size(); j++) {
                if (!cur->children.count(word[j])) {
                    cur->children[word[j]] = new TrieNode();
                }
                cur = cur->children[word[j]];
            }
            cur->end = true;
            cur->word = word;
        }
        int n = board.size();
        if (!n) return ansv;
        int m = board[0].size();
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < m; x++) {
                //cout << "DEBUG" << endl;
                search(ans, root, board, x, y);
            }
        }
        for (auto itr = ans.begin(); itr != ans.end(); ++itr) {
            ansv.push_back(*itr);
        }
        return ansv;
    }
};
