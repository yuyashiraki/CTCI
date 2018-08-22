class Solution {
public:
    // Reverse + reverse words + 3 pointers
    // Time O(n)  Space O(1)
    void reverseWords(string &s) {
        reverse(s.begin(), s.end());
        int storeIndex = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') {
                if (storeIndex != 0) storeIndex++;
                int j = i;
                while (j < s.size() && s[j] != ' ') j++;
                //cout << storeIndex << " " << j << endl;
                reverse(s.begin() + storeIndex, s.begin() + j);
                storeIndex += j - i;
                i = j;
            }
        }
        s.erase(s.begin() + storeIndex, s.end());
    }

    // Reverse + reverse words
    // Time avg.O(n) worst.O(n^2)  Space O(1)
    // If string consists of spaces only, it have to copy rest of the string every time delete a space
    void reverseWords(string &s) {
        if (s.size() == 0) return;
        reverse(s.begin(), s.end());
        int i = 0, prev = 0;
        while (i < s.size()) {
            if (s[i] == ' ') {
                if (prev == i) {
                    s.erase(s.begin() + i);
                } else {
                    reverse(s.begin() + prev, s.begin() + i);
                    prev = i + 1;
                    i++;
                }
            } else {
                i++;
            }
        }
        if (s.size() == 0) return;
        if (prev != i) reverse(s.begin() + prev, s.begin() + i);
        else s.erase(s.begin() + i - 1);
    }
};
