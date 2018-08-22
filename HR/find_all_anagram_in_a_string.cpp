class Solution {
public:
    // Sliding window
    // Time O(n)  Space O(26)
    vector<int> findAnagrams(string s, string p) {
        vector<int> counter(26,0);
        int count = 0;
        for (int i = 0; i < p.size(); i++) {
            if (0 == counter[p[i] - 'a']++) count++;
        }
        int l = 0, r = 0;
        vector<int> ans;
        while (r < s.size()) {
            //cout << l << " " << r << " " << count <<  endl;
            if (0 == counter[s[r] - 'a']--) count++;
            if (0 == counter[s[r] - 'a']) count--;
            r++;
            if (r - l > p.size()) {
                if (0 == counter[s[l] - 'a']++) count++;
                if (0 == counter[s[l] - 'a']) count--;
                l++;
            }
            if (count == 0) ans.push_back(l);
        }
        return ans;
    }
};
