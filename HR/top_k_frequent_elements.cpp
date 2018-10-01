class Solution {
public:
    // Hash Table + Bucket Sort
    // Time O(n)  Space O(n)
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> freq(n + 1, vector<int>());
        unordered_map<int, int> MP;
        for (int i = 0; i < n; i++) MP[nums[i]]++;
        for (auto itr = MP.begin(); itr != MP.end(); ++itr) {
            freq[itr->second].push_back(itr->first);
        }

        if (n < k) k = n;
        vector<int> ans;
        for (int i = n; i >= 1; i--) {
            for (int j = 0; j < freq[i].size() && k; j++) {
                ans.push_back(freq[i][j]);
                k--;
            }
        }
        return ans;
    }

    // Hash Table + Priority Queue
    // Time O(nlog(k))  Space O(n + k)
};
