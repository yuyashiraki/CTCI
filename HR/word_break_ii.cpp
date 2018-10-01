class Solution {
public:
    unordered_map<int, vector<string>> memo;
    vector<string> wordBreakII(string &s, int idx, vector<string>& wordDict) {
        if (memo.count(idx)) return memo[idx];
        vector<string> ans;
        for (int i = 0; i < wordDict.size(); i++) {
            string &word = wordDict[i];
            if (s.substr(idx, word.size()) == word) {
                if (idx + word.size() == s.size()) ans.push_back(word);
                else {
                    vector<string> tmp = wordBreakII(s, idx + word.size(), wordDict);
                    for (int j = 0; j < tmp.size(); j++) ans.push_back(word + " " + tmp[j]);
                }
            }
        }
        memo[idx] = ans;
        return ans;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        return wordBreakII(s, 0, wordDict);
    }
};
