class Solution {
public:
    // creating Graph + DFS
    // Time O(N + E)  Space O(N + E)
    bool recur(vector<int> &Color, vector<vector<int>> &Edge, int x, int color) {
        int nextcolor = color == 1 ? 2 : 1;
        if (Color[x] != 0 && Color[x] != color) {
            return false;
        }
        if (Color[x] == color) {
            return true;
        }
        Color[x] = color;
        for (int i = 0; i < Edge[x].size(); i++) {
            if (false == recur(Color, Edge, Edge[x][i], nextcolor)) {
                return false;
            }
        }
        return true;
    }
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<int> Color(N, 0);
        vector<vector<int>> Edge(N + 1, vector<int>());
        for (int i = 0; i < dislikes.size(); i++) {
            Edge[dislikes[i][0] - 1].push_back(dislikes[i][1] - 1);
            Edge[dislikes[i][1] - 1].push_back(dislikes[i][0] - 1);
        }
        for (int i = 0; i < N; i++) {
            if (Color[i] > 0) continue;
            if (false == recur(Color, Edge, i, 1)) return false;
        }
        return true;
    }
};
