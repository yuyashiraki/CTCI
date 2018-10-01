class Solution {
public:
    // Brute Force
    // if s[0:n-i] == reversed[i:], then return rev[0:i] + s
    // Time O(n^2)  Space O(n)
    string shortestPalindrome(string s) {
        int n = s.size();
        string rev(s);
        reverse(rev.begin(), rev.end());
        for (int i = 0; i < s.size(); i++) {
            if (s.substr(0, n - i) == rev.substr(i)) return rev.substr(0,i) + s;
        }
        return rev + s;
    }

    // Two pointer
    // Time O(n^2)  Space O(1)
    string shortestPalindrome(string s) {
        for (int i = s.size() - 1; i >= 0; i--) {
            int l = 0, r = i;
            while (l < r) {
                //cout << i << " " << l << " " << r << endl;
                if (s[l] == s[r]) {
                    l++;
                    r--;
                } else {
                    break;
                }
            }
            if (l >= r) {
                string tmp = s.substr(i + 1, s.size() - i - 1);
                reverse(s.begin(), s.end());
                return s + tmp;
            }
        }
        return s;
    }};
