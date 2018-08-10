class Solution {
public:
    // Iterative
    // Time O(2^n)  Space O(1)
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans{vector<int>()};
        for (int i = 0; i < nums.size(); i++) {
            vector<vector<int>> tmp(ans.begin(), ans.end());
            for (int j = 0; j < tmp.size(); j++) {
                tmp[j].push_back(nums[i]);
            }
            ans.insert(ans.begin(), tmp.begin(), tmp.end());
        }
        return ans;
    }

    // Recursive
    // Time O(2^n)  Space O(n)
    void subsets(vector<int>& nums, int start, vector<int>& sub, vector<vector<int>>& res) {
        res.push_back(sub);
        for (int i = start; i < nums.size(); i++) {
            sub.push_back(nums[i]);
            subsets(nums, i+1, sub, res);
            sub.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> sub;
        subsets(nums, 0, sub, ans);
        return ans;
    }};
