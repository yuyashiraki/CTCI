class Solution {
public:
    // Sliding Window
    // Time: O(2N)  Space: O(N)
    int lengthOfLongestSubstring(string s) {
        if (s.size() < 2) return s.size();
        unordered_set<char> st;
        int i = 0, j = 0, rt = 0;
        while (j < s.size()) {
            if (st.find(s[j]) != st.end()) {
                rt = max(rt, j - i);
                cout << j << " " << i << endl;
                while (1) {
                    st.erase(st.find(s[i]));
                    if (s[i++] == s[j]) break;
                }
            }
            st.insert(s[j]);
            j++;
        }
        rt = max(rt, j - i);
        return rt;
    }
    // Sliding Windows
    // Time: O(N)  Space: O(N)
    int lengthOfLongestSubstring(string s) {
        if (s.size() < 2) return s.size();
        unordered_map<char, int> mp;
        int rt = 0;
        for (int i = 0, j = 0; j < s.size(); j++) {
            if (mp.find(s[j]) != mp.end()) {
                i = max(i, mp[s[j]]);
            }
            rt = max(rt, j - i + 1);
            mp[s[j]] = j + 1;
        }
        return rt;
    }
};
