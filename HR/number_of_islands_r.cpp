class Solution {
public:
    // Using Union Find
    // Time O(n*m) since total compression time takes constant time
    // Space O(n*m)
    class UnionFind {
    public:
        vector<int> data;
        int count;
        UnionFind(vector<vector<char>>& grid) {
            int n = grid.size();
            count = 0;
            if (!n) return;
            int m = grid[0].size();
            for (int y = 0; y < n; y++) {
                for (int x = 0; x < m; x++) {
                    if (grid[y][x] == '1') {
                        data.push_back(y*m + x);
                        count++;
                    } else {
                        data.push_back(-1);
                    }
                }
            }
        }
        void Union(int x, int y) {
            x = find(x); y = find(y);
            if (x != y) {
                count--;
                if (x > y) data[x] = y;
                else data[y] = x;
            }
        }
        int find(int x) {
            if (data[x] == x) return x;
            else {
                return data[x] = find(data[x]);
            }
        }
        int getcount() {
            return count;
        }
    };
    int numIslands(vector<vector<char>>& grid) {
        UnionFind uf(grid);
        int n = grid.size();
        if (!n) return 0;
        int m = grid[0].size();
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < m; x++) {
                if (grid[y][x] == '0') continue;
                if (y > 0 && grid[y - 1][x] == '1') uf.Union(y*m+x, (y-1)*m+x);
                if (x > 0 && grid[y][x - 1] == '1') uf.Union(y*m+x, y*m+x-1);
            }
        }
        return uf.getcount();
    }
};
