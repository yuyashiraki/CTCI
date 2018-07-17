class Solution {
public:
    // Using DP
    // Time O(n^2)  Space O(n)
    bool wordBreak(string s, vector<string>& wordDict)
    {
        set<string> st;
        for (auto itr = wordDict.begin(); itr != wordDict.end(); ++itr) {
            st.insert(*itr);
        }
        bool dp[s.size() + 1] = {false};
        dp[0] = true;
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && st.find(s.substr(j, i - j)) != st.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }


    // Using Trie + BFS + Memoization
    // Time O(nm), Size of recursion tree <= n^2
    // Space O(m),  tree depth <= n
    // Using Trie + DFS + Memoization
    // Time O(nm), Size of recursion tree <= n^2
    // Space O(m),  tree width <= m
    class trieNode
    {
    public:
        string c;
        bool end = false;;
        map<char, trieNode *> child;
        trieNode(string x) {
            c = x;
        }
    };
    trieNode *buildTrie(vector<string>& wordDict)
    {
        trieNode *root = new trieNode("#");
        for (int i = 0; i < wordDict.size(); i++) {
            string s = wordDict[i];
            int s_cur = 0;
            trieNode *trie_cur = root;
            while (s_cur < s.size()) {
                //cout << trie_cur->c << endl;
                auto itr = trie_cur->child.find(s[s_cur]);
                if (itr == trie_cur->child.end()) {
                    trieNode *tmp = new trieNode(s.substr(0, s_cur + 1));
                    trie_cur->child[s[s_cur]] = tmp;
                    trie_cur = tmp;
                } else {
                    trie_cur = itr->second;
                }
                s_cur++;
            }
            //cout << trie_cur->c << endl;
            trie_cur->end = true;
        }
        return root;
    }
    bool wordBreak(string s, vector<string>& wordDict)
    {
        if (!s.size() || !wordDict.size()) return false;
        trieNode *root = buildTrie(wordDict);
        stack<pair<int, trieNode*>> qq;
        set<pair<int, trieNode*>> st;
        qq.emplace(0, root);
        //cout << "string size = " << s.size() << endl;

        while (!qq.empty()) {
            pair<int, trieNode*> pp = qq.top();
            qq.pop();
            if (st.find(pp) != st.end()) continue;
            st.insert(pp);
            int scur = pp.first;
            trieNode *trie_cur = pp.second;
            //cout << scur << trie_cur->c << endl;
            if (trie_cur->end) {
                //cout << "DEBUG" << endl;
                if (scur == s.size()) return true;
                qq.emplace(scur, root);
            }

            trieNode *tmp = NULL;
            if (scur < s.size())
                tmp = trie_cur->child[s[scur]];
            if (tmp != NULL) {
                if (++scur <= s.size()) {
                    qq.emplace(scur, tmp);
                }
            }
        }
        return false;
    }
};
