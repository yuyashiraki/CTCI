class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> counter(26, 0), countercopy;
        int i = 0;
        for (i = 0; i < s1.size(); i++) {
            counter[s1[i] - 'a']++;
        }
        int begin = 0, end = 0;
        while (end < s2.size()) {
            if (counter[s2[end] - 'a'] > 0) {
                if (end == begin) {
                    countercopy = counter;
                }
                if (0 == countercopy[s2[end] - 'a'] || end - begin == s1.size()) {
                    countercopy[s2[begin++] - 'a']++;
                } else {
                    countercopy[s2[end++] - 'a']--;
                    for (i = 0; i <= 26; i++) {
                        if (i == 26) return true;
                        if (countercopy[i] > 0) break;
                    }
                }
            } else {
                begin = ++end;
            }
        }
        return false;
    }
};
