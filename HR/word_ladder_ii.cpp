class Solution {
public:
    // BFS with Hash + Pruning
    // Time O(n^2)  Space O(n)
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ans;
        queue<vector<string>> paths;
        //wordList.push_back(endWord);
        paths.push({beginWord});
        int level = 1, minLevel = INT_MAX;
        unordered_set<string> visited;
        while (!paths.empty()) {
            vector<string> path = paths.front();
            paths.pop();
            if (path.size() > level) {
                for (string w : visited) wordList.erase(find(wordList.begin(), wordList.end(), w));
                visited.clear();
                if (path.size() > minLevel) break;
                else level = path.size();
            }
            string last = path.back();
            for (int i = 0; i < last.size(); ++i) {
                string news = last;
                for (char c = 'a'; c <= 'z'; ++c) {
                    news[i] = c;
                    if (find(wordList.begin(), wordList.end(), news) != wordList.end()) {
                        vector<string> newpath = path;
                        newpath.push_back(news);
                        visited.insert(news);
                        if (news == endWord) {
                            minLevel = level;
                            ans.push_back(newpath);
                        } else {
                            paths.push(newpath);
                        }
                    }
                }
            }
        }
        return ans;
    }

    // Using Dijkstra with priority queue  ERROR, not working
    // Time O((n + e)log(n)), n:#nodes e:#edges
    // Space O(n + e)
    class Node {
    public:
        int cost = INT_MAX;
        vector<int> neighbors;
        set<pair<int, int>> prev;
    };
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int i, j, c, n = wordList.size(), s = wordList[0].size();
        int begin = -1, end = -1;
        vector<Node> wordNodes(n);
        for (i = 0; i < n; i++) {
            if (-1 == begin && beginWord == wordList[i]) begin = i;
            else if (-1 == end && endWord == wordList[i]) end = i;
            if (begin != -1 && end != -1) break;
        }
        if (-1 == begin) {
            wordList.push_back(beginWord);
            begin = n++;
        }
        if (-1 == end) {
            wordList.push_back(endWord);
            end = n++;
        }
        // Create graph
        for (i = 0; i < n; i++) {
            for (j = i + 1; j < n; j++) {
                int diff_cnt = 0;
                for (c = 0; c < s; c++) {
                    diff_cnt += wordList[i][c] == wordList[j][c];
                }
                if (1 == diff_cnt) {
                    wordNodes[i].neighbors.push_back(j);
                    wordNodes[j].neighbors.push_back(i);
                }
            }
        }
        assert(0);
        // Dijkstra
        int end_cost = INT_MAX;
        priority_queue<pair<int, int>> qq;
        qq.emplace(0, begin);
        while (!qq.empty()) {
            int cost = qq.top().first, idx = qq.top().second;
            qq.pop();
            if (cost > end_cost) break;
            if (idx == end) {
                end_cost = cost;
            }
            if (wordNodes[idx].cost < cost) continue;
            wordNodes[idx].cost = cost;
            cost++;
            for (i = 0; i < wordNodes[idx].neighbors.size(); i++) {
                int neighbor = wordNodes[idx].neighbors[i];
                qq.emplace(cost, neighbor);
                wordNodes[neighbor].prev.emplace(cost, idx);
            }
        }
        assert(0);
        // generate result
        queue<vector<int>> q;
        vector<int> qe{end};
        q.push(qe);
        vector<vector<string>> ans;
        while (!q.empty()) {
            vector<int> elem = q.front();
            q.pop();
            int idx = elem[0];
            if (idx == begin) {
                vector<string> anss;
                for (j = elem.size() - 1; j >= 0; j--) {
                    anss.push_back(wordList[elem[j]]);
                }
                ans.push_back(anss);
            }
            for (i = 0; i < wordNodes[idx].neighbors.size(); i++) {
                int neighbor = wordNodes[idx].neighbors[i];
                vector<int> nextelem = elem;
                nextelem.push_back(neighbor);
            }
        }
        return ans;
    }
};
