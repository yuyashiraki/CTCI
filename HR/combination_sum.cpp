class Solution {
public:
    // Backtracking
    // Time O(canditates^target)  Space O(target)
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> combination;
        int begin = 0;
        combinationSum(ans, combination, candidates, target, 0);
        return ans;
    }
    void combinationSum(vector<vector<int>>& ans, vector<int>& combination, vector<int>& candidates, int target, int begin) {
        if (0 == target) {
            ans.push_back(combination);
            return;
        }
        for (int i = begin; i < candidates.size() && candidates[i] <= target; i++) {
            combination.push_back(candidates[i]);
            combinationSum(ans, combination, candidates, target - candidates[i], i);
            combination.pop_back();
        }
    }

    // DP
    // Time O(candidates * target)  Space O(target)
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<set<vector<int>>> dp(target + 1);
        sort(candidates.begin(), candidates.end());
        for (int i = 1; i <= target; i++) {
            for (int j = 0; j < candidates.size(); j++) {
                if (candidates[j] > i) break;
                else if (candidates[j] == i) dp[i].insert(vector<int>{i});
                else if (!dp[i - candidates[j]].empty()) {
                    for (auto x = dp[i - candidates[j]].begin(); x != dp[i - candidates[j]].end(); ++x) {
                        vector<int> y = *x;
                        y.push_back(candidates[j]);
                        sort(y.begin(), y.end());
                        dp[i].insert(y);
                    }
                }
            }
        }
        vector<vector<int>> ans;
        for (auto x = dp[target].begin(); x != dp[target].end(); ++x) {
            ans.push_back(*x);
        }
        return ans;
    }};
