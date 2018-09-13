class Solution {
public:
    // DP
    // Time O(n^2)  Space O(n^2)
    bool canCross(vector<int>& stones) {
        int n = stones.size(), stone;
        if (n < 2) return true;
        unordered_map<int, unordered_set<int>> MP;
        for (int i = 0; i < n; i++) {
            MP[stones[i]] = unordered_set<int>();
        }
        MP[stones[0]].insert(1);
        for (int i = 0; i < n; i++) {
            stone = stones[i];
            for (auto itr = MP[stone].begin(); itr != MP[stone].end(); ++itr) {
                if (MP.count(stone + *itr)) {
                    MP[stone + *itr].insert(*itr);
                    MP[stone + *itr].insert(*itr + 1);
                    if (*itr - 1 > 0) MP[stone + *itr].insert(*itr - 1);
                }
            }
        }
        return MP[stone].size() > 0;
    }
};
