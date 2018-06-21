class Solution {
public:
    // BFS & Set: Time O(N*M)  Space(queue) ??
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        set<pair<int, int> > lands;
        for (int x = 0; x < grid.size(); x++) {
            for (int y = 0; y < grid[x].size(); y++) {
                if (grid[x][y] == '1') lands.insert(make_pair(x, y));
            }
        }
        queue<pair<int, int> > cur;
        while (!lands.empty()) {
            cnt++;
            cur.push(*lands.begin());
            lands.erase(lands.begin());
            while (!cur.empty()) {
                pair<int, int> n = cur.front();
                cur.pop();
                auto a = lands.find(make_pair(n.first - 1, n.second));
                if (a != lands.end()) {
                    cur.push(*a);
                    lands.erase(a);
                }
                auto b = lands.find(make_pair(n.first, n.second - 1));
                if (b != lands.end()) {
                    cur.push(*b);
                    lands.erase(b);
                }
                auto c = lands.find(make_pair(n.first + 1, n.second));
                if (c != lands.end()) {
                    cur.push(*c);
                    lands.erase(c);
                }
                auto d = lands.find(make_pair(n.first, n.second + 1));
                if (d != lands.end()) {
                    cur.push(*d);
                    lands.erase(d);
                }
            }
        }
        return cnt;
    }

    // DFS: Time O(N*M)  Space O(N*M)
    int dfs(vector<vector<char>>& grid, int x, int y) {
        if (grid[x][y] == '0') {
            return 0;
        }
        grid[x][y] = '0';
        if (x > 0) dfs(grid, x - 1, y);
        if (y > 0) dfs(grid, x, y - 1);
        if (x < grid.size() - 1) dfs(grid, x + 1, y);
        if (y < grid[x].size() - 1) dfs(grid, x, y + 1);
        return 1;
    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        for (int x = 0; x < grid.size(); x++) {
            for (int y = 0; y < grid[x].size(); y++) {
                if (dfs(grid, x, y)) cnt++;
            }
        }
        return cnt;
    }

    // UnionFind
    class UnionFinde {
    private:
        vector<int> parent;
//        vector<int> rank;
        int count;

    public:
        UnionFinde(vector<vector<char>>& grid) {
            count = 0;
            int m = grid.size();
            int n = grid[0].size();
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (grid[i][j] == '1') {
                        parent.push_back(i * n + j);
                        ++count;
                    } else {
                        parent.push_back(-1);
                    }
//                    rank.push_back(0);
                }
            }
        }
        int find(int i) {
            if (parent[i] != i) parent[i] = find(parent[i]);
            return parent[i];
        }
        void Union(int x, int y) {
            int rootx = find(x);
            int rooty = find(y);
/*            if (rootx != rooty) {
                if (rank[rootx] > rank[rooty]) parent[rooty] = rootx;
                else if (rank[rootx] < rank[rooty]) parent[rootx] = rooty;
                else { parent[rooty] = rootx; rank[rootx] += 1;}
                --count;
            } */
            if (rootx != rooty) count--;
            if (rootx > rooty) {
                parent[rooty] = rootx;
            } else {
                parent[rootx] = rooty;
            }
        }
        int getCount() const {
            return count;
        }
    };
    int numIslands(vector<vector<char>>& grid) {
        int nr = grid.size();
        if (!nr) return 0;
        int nc = grid[0].size();

        UnionFinde uf(grid);
        int num_islands = 0;
        for (int r = 0; r < nr; ++r) {
            for (int c = 0; c < nc; ++c) {
                if (grid[r][c] == '1') {
                    grid[r][c] = '0';
                    if (r - 1 >= 0 && grid[r-1][c] == '1') uf.Union(r * nc + c, (r-1) * nc + c);
                    if (r + 1 < nr && grid[r+1][c] == '1') uf.Union(r * nc + c, (r + 1) * nc + c);
                    if (c - 1 >= 0 && grid[r][c-1] == '1') uf.Union(r * nc + c, r * nc + c - 1);
                    if (c + 1 < nc && grid[r][c+1] == '1') uf.Union(r * nc + c, r * nc + c + 1);
                }
            }
        }
        return uf.getCount();
    }
};
