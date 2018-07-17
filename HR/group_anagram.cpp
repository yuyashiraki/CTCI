class Solution {
public:
    // Time O(max(n^2, nk)),n:#input,k:size of string  Space O(n)
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<long long, vector<pair<vector<int>, int>>> mp;
        vector<vector<string>> ans;
        int i, j, x, y;
        for (i = 0; i < strs.size(); i++) {
            string cur = strs[i];
            long long hash = 0;
            vector<int> vv(26, 0);
            for (j = 0; j < cur.size(); j++) {
                long long num = cur[j] - 'a';
                hash += num;
                vv[num]++;
            }
            //cout << "hash:" << hash << endl;
            auto itr = mp.find(hash);
            bool create = true;
            if (itr != mp.end()) {
                //cout << "DEBUG1:" << cur << endl;
                 for (x = 0; x < mp[hash].size(); x++) {
                     vector<int> vvx = mp[hash][x].first;
                     create = false;
                     for (y = 0; y < vvx.size(); y++) {
                         //cout << "\t" <<(char) (y + 'a') << " " << vv[y] << " " << vvx[y] << endl;
                         if (vv[y] == vvx[y]) continue;
                         else {
                             create = true;
                             break;
                         }
                     }
                     if (!create) {
                         ans[mp[hash][x].second].push_back(cur);
                         break;
                     }
                 }
            }
            if (create) {
                //cout << "DEBUG2:" << cur << endl;
                mp[hash].push_back(make_pair(vv, ans.size()));
                vector<string> anss{cur};
                ans.push_back(anss);
            }
        }
        return ans;
    }
};
