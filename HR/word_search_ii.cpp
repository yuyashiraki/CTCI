class Solution {
public:
    // Trie
    class trieNode
    {
    public:
        char val;
        trieNode *parent;
        map<char, trieNode *> childs;
        trieNode(char v, trieNode *p)
        {
            parent = p;
            val = v;
        }
        string rebuildString()
        {
            // This is overhead, better way is just holding a word in each end
            trieNode *p = this;
            string rst;
            while (p) {
                if (p->val == '{') break;
                rst.insert(rst.begin(), p->val);
                p = p->parent;
            }
            return rst;
        }
    };
    trieNode *buildTrie(vector<string> &words)
    {
        trieNode *root = new trieNode('{', (trieNode *)NULL);
        for (int i = 0; i < words.size(); i++) {
            string ss = words[i];
            trieNode *cur = root;
            for (int j = 0; j <= ss.size(); j++) {
                char v;
                if (j == ss.size()) {
                    v = '}';
                } else {
                    v = ss.at(j);
                }
                if (cur->childs.find(v) == cur->childs.end()) cur->childs[v] = new trieNode(v, cur);
                cur = cur->childs[v];
            }
        }
        return root;
    }

    // using DFS
    // Time O(3^(max length of words)) Space O(max length of words)
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // construct Trie
        trieNode *root = buildTrie(words);
        set<trieNode *> rt;
        vector<string> rst;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                dfs(board, i, j, root, rt);
            }
        }
        for (auto itr = rt.begin(); itr != rt.end(); itr++) {
            // non-optimized method
            rst.push_back((*itr)->rebuildString());
        }
        return rst;
    }
    void dfs(vector<vector<char>>& board, int i, int j, trieNode *p, set<trieNode *>& rt)
    {
        char c = board[i][j];
        if (c == '#' || p->childs.empty() || p->childs.find(c) == p->childs.end()) return;
        p = p->childs[c];
        if (p->childs.find('}') != p->childs.end()) {
            rt.insert(p);
        }
        board[i][j] = '#';
        if (i > 0) dfs(board, i - 1, j, p, rt);
        if (j > 0) dfs(board, i, j - 1, p, rt);
        if (i + 1 < board.size()) dfs(board, i + 1, j, p, rt);
        if (j + 1 < board[0].size()) dfs(board, i, j + 1, p, rt);
        board[i][j] = c;
    }



    // Using BFS: failed because we need to keep track of which node has visited but it's too much work
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // construct Trie
        trieNode *root = buildTrie(words);

        vector<vector<set<trieNode *>>> bb(board.size(), vector<set<trieNode *>>(board[0].size(), set<trieNode *>()));
        int cnt = 0;
        vector<trieNode *> rt;
        vector<string> rtstr;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board.size(); j++) {
                if (root->childs.find(board[i][j]) != root->childs.end()) {
                    bb[i][j].insert(root->childs[board[i][j]]);
                    cnt++;
                }
            }
        }
        while (cnt) {
            cnt = 0;
            vector<vector<set<trieNode *>>> bbtmp(board.size(), vector<set<trieNode *>>(board[0].size(), set<trieNode *>()));
            for (int i = 0; i < board.size(); i++) {
                for (int j = 0; j < board[0].size(); j++) {
                    if (bb[i][j].empty()) continue;
                    cout << i << " " << j << endl;
                    cnt++;
                    for (auto itr = bb[i][j].begin(); itr != bb[i][j].end(); itr++) {
                        if (i > 0 && (*itr)->childs.find(board[i-1][j]) != (*itr)->childs.end()) {
                            bbtmp[i-1][j].insert((*itr)->childs[board[i-1][j]]);
                        }
                        if (i + 1 < board.size() && (*itr)->childs.find(board[i + 1][j]) != (*itr)->childs.end()) {
                            bbtmp[i + 1][j].insert((*itr)->childs[board[i+1][j]]);
                        }
                        if (j > 0 && (*itr)->childs.find(board[i][j-1]) != (*itr)->childs.end()) {
                            bbtmp[i][j - 1].insert((*itr)->childs[board[i][j-1]]);
                        }
                        if (j + 1 < board[0].size() && (*itr)->childs.find(board[i][j+1]) != (*itr)->childs.end()) {
                            bbtmp[i][j+1].insert((*itr)->childs[board[i][j+1]]);
                        }
                        if ((*itr)->childs.find('}') != (*itr)->childs.end()) rt.push_back(*itr);
                    }
                }
            }
            bb = bbtmp;
            cout << cnt << endl;
        }
        for (int i = 0; i < rt.size(); i++) {
            string rst;
            trieNode *n = rt[i];
            while (n) {
                if (n->val == '{') break;
                rst.insert(rst.begin(), n->val);
                n = n->parent;
            }
            rtstr.push_back(rst);
        }
        return rtstr;
    }
};
