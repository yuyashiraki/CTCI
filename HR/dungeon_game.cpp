class Solution {
public:
    // DP
    // hp[y][x] : HP needed to reach princess from cell (x,y)
    // if hp[y][x] <= 0, a knight doesn't need any HP to reach to princess from cell (x,y). So if a knight has HP 1, it's enough.
    // Since we visit each column by column, we just need to keep one DP array for one column
    // Time O(m*n)  Space O(m)
    int calculateMinimumHP(vector<vector<int> > &dungeon) {
        if (dungeon.size() == 0 || dungeon[0].size() == 0) return 1;
        int n = dungeon.size(), m = dungeon[0].size();
        vector<int> hp(m, INT_MAX);
        hp[m - 1] = 1;
        for (int y = n - 1; y >= 0; y--) {
            for (int x = m - 1; x >= 0; x--) {
                if (x + 1 < m) hp[x] = min(hp[x], hp[x + 1]);
                if (hp[x] - dungeon[y][x] <= 0) hp[x] = 1;
                else hp[x] -= dungeon[y][x];
            }
        }
        return hp[0];
    }
};
