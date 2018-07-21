class Solution {
public:
    // Using Hash
    // Time O(n*k^2) where n: #words k: length of word
    // Space O(n*k)
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> ret;
        if (words.size() < 2) return ret;
        unordered_map<string, int> mp;
        for (int i = 0; i < words.size(); i++) mp.emplace(words[i], i);
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j <= words[i].size(); j++) {
                string str1 = words[i].substr(0, j);
                string str2 = words[i].substr(j, words[i].size() - j);
                //cout << str1 << " " << str2 << endl;
                if (isPalindrome(str1)) {
                    string str2rvs = str2;
                    reverse(str2rvs.begin(), str2rvs.end());
                    if (mp.count(str2rvs) && mp[str2rvs] != i) {
                        vector<int> retelem{mp[str2rvs], i};
                        ret.push_back(retelem);
                    }
                }
                if (isPalindrome(str2)) {
                    string str1rvs = str1;
                    reverse(str1rvs.begin(), str1rvs.end());
                    if (mp.count(str1rvs) && mp[str1rvs] != i && str2.size()) {
                        vector<int> retelem{i, mp[str1rvs]};
                        ret.push_back(retelem);
                    }
                }
            }
        }
        return ret;
    }
    bool isPalindrome(string str) {
        int left = 0, right = str.size() - 1;
        while (left <= right) {
            if (str[left++] != str[right--]) return false;
        }
        return true;
    }
};
