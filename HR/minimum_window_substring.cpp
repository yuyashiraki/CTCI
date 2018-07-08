class Solution {
public:
    // Two pointers
    // Time O(n)  Space O(n)
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;
        unordered_map<char, int> ansmp;
        for(int i = 0; i < t.size(); i++) {
            mp[t[i]]++;
            ansmp[t[i]] = 0;
        }
        string ans = "";
        bool satisfied = false;
        for (int l = 0, r = 0; r < s.size(); r++) {
            if (ansmp.find(s[r]) != ansmp.end()) {
                ansmp[s[r]]++;
                if (!satisfied) {
                    satisfied = true;
                    for (auto itr = ansmp.begin(); itr != ansmp.end(); ++itr) {
                        satisfied = satisfied && itr->second >= mp[itr->first];
                        //cout << "\t" << itr->first << " " << mp[itr->first] << " " << ansmp[itr->first] << endl;
                    }
                }
            }
            //cout << "mpsize:" << mp.size() << endl;
            if (satisfied) {
                while (l < r) {
                    //cout << "\tl: " << s[l] << endl;
                    if (ansmp.find(s[l]) == ansmp.end()) {
                        l++;
                    } else if (ansmp[s[l]] > mp[s[l]]) {
                        ansmp[s[l]]--;
                        l++;
                    } else {
                        break;
                    }
                }
                if (ans.empty() || r - l + 1 < ans.size()) {
                    ans = s.substr(l, r - l + 1);
                }
            }
            //cout << "(l, r): " << l  << " " << r << endl;
        }
        return ans;
    }
};
