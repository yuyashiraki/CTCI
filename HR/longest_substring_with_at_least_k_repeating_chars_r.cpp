class Solution {
public:
    // Number of Unique Character Iteration
    // Time O(n)  Space O(1)
    int longestSubstring(string s, int k) {
        int h,i,j,idx,ans = 0,uniq,noLessThanK;
        for (h = 1; h <= 26; h++) {
            vector<int> counts(26,0);
            i = 0,j = 0,uniq = 0,noLessThanK = 0;
            while (j < s.size()) {
                if (uniq <= h) {
                    idx = s[j] - 'a';
                    if (counts[idx] == 0) uniq++;
                    counts[idx]++;
                    if (counts[idx] == k) noLessThanK++;
                    j++;
                } else {
                    idx = s[i] - 'a';
                    if (counts[idx] == k) noLessThanK--;
                    counts[idx]--;
                    if (counts[idx] == 0) uniq--;
                    i++;
                }
                if (uniq == h && uniq == noLessThanK) ans = max(j - i, ans);
            }
        }
        return ans;
    }


    // Divide and Conquer
    // Time O(nlog(n))  Space O(log(n))
    int longestSubstring(string s, int k) {
        if (s.size() <= 0) return 0;
        int ans = 0;
        vector<int>  counter(26);
        unordered_set<char> ST;
        for (int i = 0; i < s.size(); i++) {
            if (++counter[s[i] - 'a'] < k) {
                ST.insert(s[i]);
            } else {
                ST.erase(s[i]);
            }
        }
        if (ST.empty()) {
            return s.size();
        }
        int lastidx = 0, len;
        for (int i = 0; i <= s.size(); i++) {
            if (i == s.size() || ST.count(s[i])) {
                cout << s[i] << endl;
                if ((len = i - lastidx) >= k) {
                    ans = max(ans, longestSubstring(s.substr(lastidx, len), k));
                }
                lastidx = i + 1;
            }
        }
        return ans;
    }
};
