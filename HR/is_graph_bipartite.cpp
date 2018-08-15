class Solution {
public:
    // BFS
    // Time O(n)  Space O(n)
    enum group {
        UNKNOWN = 0,
        A,
        B,
    };
    bool isBipartite(vector<vector<int>>& graph) {
        if (graph.size() == 0) return true;
        vector<group> node(graph.size(), UNKNOWN);
        queue<int> Q;
        for (int idx = 0; idx < graph.size(); idx++) {
            if (node[idx] != UNKNOWN) continue;
            node[idx] = A;
            Q.push(idx);
            while (!Q.empty()) {
                int c = Q.front();
                Q.pop();
                group next = node[c] == A ? B : A;
                for (int i = 0; i < graph[c].size(); i++) {
                    if (node[graph[c][i]] == UNKNOWN) {
                        node[graph[c][i]] = next;
                        Q.push(graph[c][i]);
                    } else if (node[graph[c][i]] == next) {
                     continue;
                    } else {
                       return false;
                    }
                }
            }
        }
        return true;
    }
};
