class Solution {
public:
    // DFS using Hash table
    // Time O(n)  Space O(n)
    void recur(vector<int> &ans, unordered_map<int, vector<int>> &tree, int kill) {
        //cout << kill << endl;
        ans.push_back(kill);
        for (int i = 0; i < tree[kill].size(); i++) {
            recur(ans, tree, tree[kill][i]);
        }
    }
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        vector<int> ans;
        if (pid.size() != ppid.size() || pid.size() == 0) return ans;
        unordered_map<int, vector<int>> tree;
        for (int i = 0; i < pid.size(); i++) tree[ppid[i]].push_back(pid[i]);
        recur(ans, tree, kill);
        return ans;
    }
};
