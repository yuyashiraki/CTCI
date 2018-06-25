class Solution {
public:
    // Topological Sorting on DAG(Directed Acyclic Graph)
    vector<vector<int>> dirs{{0,1},{1,0},{0,-1},{-1,0}};
    int longestIncreasingPath(vector<vector<int>>& matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        if (!m || !n) return 0;
        vector<vector<int>> outdegree(m, vector<int>(n, 0));
        queue<pair<int, int>> leaves;
        for (int y = 0; y < m; y++) {
            for (int x = 0; x < n; x++) {
                for (int dir = 0; dir < dirs.size(); dir++) {
                    int adjx = x + dirs[dir][0], adjy = y + dirs[dir][1];
                    if (adjx >= 0 && adjx < n && adjy >= 0 && adjy < m) outdegree[y][x] += matrix[adjy][adjx] > matrix[y][x];
                }
                if (!outdegree[y][x]) leaves.emplace(x,y);
            }
        }
        int height = 0;
        while (!leaves.empty()) {
            height++;
            queue<pair<int, int>> newleaves;
            while (!leaves.empty()) {
                pair<int, int> cur = leaves.front();
                leaves.pop();
                int adjx = cur.first, adjy = cur.second;
                for (int dir = 0; dir < dirs.size(); dir++) {
                    int x = adjx + dirs[dir][0], y = adjy + dirs[dir][1];
                    if (x >= 0 && x < n && y >= 0 && y < m && matrix[adjy][adjx] > matrix[y][x])
                        if (--outdegree[y][x] == 0)
                            newleaves.emplace(x, y);
                }
                swap(leaves, newleaves);
            }
        }
        return height;
    }

    // DFS: Time O(4^(n+m)) Space O(n*m)
    // DFS + memo: Time O(n*m) Space O(n*m)
    enum direction {
        I = 0, L = 1, R = 2, U = 3, D = 4,
    };
    map<pair<int, int>, int> mm;
    int dfs(int x, int y, vector<vector<int>>& matrix, enum direction from)
    {
        if (mm.find(make_pair(x, y)) != mm.end()) return mm[make_pair(x, y)];
        int rt = 1;
        if (x > 0 && matrix[x - 1][y] > matrix[x][y] && from != L) {
            rt = max(rt, dfs(x - 1, y, matrix, R) + 1);
        }
        if (x < matrix.size() - 1 && matrix[x + 1][y] > matrix[x][y] && from != R) {
            rt = max(rt, dfs(x + 1, y, matrix, L) + 1);
        }
        if (y > 0 && matrix[x][y - 1] > matrix[x][y] && from != D) {
            rt = max(rt, dfs(x, y - 1, matrix, U) + 1);
        }
        if (y < matrix[0].size() - 1 && matrix[x][y + 1] > matrix[x][y] && from != U) {
            rt = max(rt, dfs(x, y + 1, matrix, D) + 1);
        }
        mm[make_pair(x, y)] = rt;
        return rt;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix)
    {
        int rt = 0;
        for (int x = 0; x < matrix.size(); x++) {
            for (int y = 0; y < matrix[0].size(); y++) {
                rt = max(rt, dfs(x, y, matrix, I));
            }
        }
        return rt;
    }
};
