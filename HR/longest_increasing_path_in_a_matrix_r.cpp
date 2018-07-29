class Solution {
public:
    // Using topological sort
    // Time O(mn)  Space O(mn)
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size(), ans = 0;
        if (n == 0) return ans;
        int m = matrix[0].size();
        vector<vector<int>> indegrees(n, vector<int>(m, 0));
        queue<tuple<int,int,int>> Q;
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < m; x++) {
                int indegree = 0;
                if (y > 0 && matrix[y][x] > matrix[y - 1][x]) indegree++;
                if (x > 0 && matrix[y][x] > matrix[y][x - 1]) indegree++;
                if (y < n - 1 && matrix[y][x] > matrix[y+1][x]) indegree++;
                if (x < m - 1 && matrix[y][x] > matrix[y][x+1]) indegree++;
                if (!indegree) Q.emplace(y,x,1);
                else indegrees[y][x] = indegree;
            }
        }
        while (!Q.empty()) {
            int y = get<0>(Q.front()), x = get<1>(Q.front());
            int level = get<2>(Q.front());
            //cout << x << " " << y << " " << level << endl;
            Q.pop();
            if (y > 0 && matrix[y][x] < matrix[y - 1][x]) {
                if (0 == --indegrees[y-1][x]) Q.emplace(y-1,x,level+1);
            }
            if (x > 0 && matrix[y][x] < matrix[y][x - 1]) {
                if (0 == --indegrees[y][x-1]) Q.emplace(y,x-1,level+1);
            }
            if (y < n - 1 && matrix[y][x] < matrix[y+1][x]) {
                if (0 == --indegrees[y+1][x]) Q.emplace(y+1,x,level+1);
            }
            if (x < m - 1 && matrix[y][x] < matrix[y][x+1]) {
                if (0 == --indegrees[y][x+1]) Q.emplace(y,x+1,level+1);
            }
            ans = max(ans, level);
        }
        return ans;
    }
};
