class Solution {
public:
    // using Hash table: Time O(n) Space O(1) because there is only 26 chars
    int firstUniqChar(string s) {
        unordered_map<char, pair<int, bool>> mp;
        for (int i = 0; i < s.size(); i++) {
            auto itr = mp.find(s[i]);
            if (itr != mp.end()) {
                itr->second.second = true;
            } else {
                mp[s[i]] = make_pair(i, false);
            }
        }
        int rt = INT_MAX;
        for (auto itr = mp.begin(); itr != mp.end(); itr++) {
            if (itr->second.second) continue;
            rt = min(rt, itr->second.first);
        }
        if (rt == INT_MAX) return -1;
        else return rt;
    }
};
