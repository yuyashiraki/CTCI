class Solution {
public:
    // using two pointers: Time O(n^2)
    int longestSubstring(string s, int k)
    {
        int max_len = 0;
        for (int first = 0; first+k <= s.size();) {
            int count[26] = {0};
            int mask = 0;   // reduce traversing 26 alphabets to 1
            int max_last = first;
            for (int last = first; last < s.size(); last++) {
                int i = s[last] - 'a';
                count[i]++;
                if (count[i] < k) {
                    mask |= (1 << i);
                } else {
                    mask &= (~(1 << i));
                }

                if (mask == 0) {  // If all the character appear no less than k
                    max_len = max(max_len, last - first + 1);
                    max_last = last;
                }
            }
            first = max_last + 1;
        }
        return max_len;
    }

    // divide and conquer: Time O(n^2)
    int longestSubstring(string s, int k) {
        int n = s.size();
        return helper(s, 0, n-1, k);
    }
    // looking for longest string within index range [l, r]
    int helper(string& s, int l, int r, int k) {
        vector<int> mp(26, 0);
        for (int i = l; i <= r; i++) mp[s[i]-'a']++;
       // check whether the whole string meets requirement
        bool pass = true;
        for (int i = 0; i < 26 && pass; i++) {
            if (mp[i] && mp[i] < k)
                pass = false;
        }
        if (pass) return r-l+1;
        // using all characters with occurrence > 0 && < k to divide the string
        int i = l, ans = 0;
        for (int j = l; j <= r; j++) {
            if (mp[s[j]-'a'] && mp[s[j]-'a'] < k) {
                ans = max(ans, helper(s, i, j-1, k));
                i = j+1;
            }
        }
        return max(ans, helper(s, i, r, k));
    }
};
