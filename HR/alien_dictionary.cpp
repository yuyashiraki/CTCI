// Using Topological Sort (Kahn's algorithm)
// Time O(n^2) where n = letters,  Space O(n^2)
class Solution {
public:
    string alienOrder(vector<string> &words) {
        string ans;
        if (!words.size()) return ans;

        vector<vector<int>> graph(26, vector<int>());  // DAG
        unordered_map<int, int> degree;  // incoming degree
        if (!buildGraph(words, graph, degree)) return "";
        // topological sort
        queue<int> Que;
        for (auto elem: degree) {
            if (!elem.second) Que.push(elem.first);
        }
        while (!Que.empty()) {
            int v = Que.front(); Que.pop();
            ans.push_back(v + 'a');
            for (auto vv: graph[v]) {
                degree[vv]--;
                if (!degree[vv]) Que.push(vv);
            }
        }
        for (auto d: degree) {
            if (d.second > 0) return "";
        }
        return ans;
    }

    bool buildGraph(vector<string> &words, vector<vector<int>> &graph, unordered_map<int, int> &degree) {
        for (auto w: words) {
            for (auto c: w) {
                degree[c - 'a'] = 0;
            }
        }
        for (int i = 1; i < (int)words.size(); i++) {
            string pre = words[i - 1], cur = words[i];
            int pre_sz = (int)pre.size(), cur_sz = (int)cur.size(), j = 0;
            while (j < pre_sz && j < cur_sz && pre[j] == cur[j]) {
                j++;
            }
            if (j < pre_sz && j == cur_sz) return false;
            if (j < cur_sz && j < pre_sz) {
                graph[pre[j] - 'a'].push_back(cur[j] - 'a');
                degree[cur[j] - 'a']++;
            }
        }
        return true;
    }
};
