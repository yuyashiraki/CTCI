class Solution {
public:
    // using deque
    // Time O(n)  Space O(k)
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            if (!dq.empty() && dq.front() == i - k) dq.pop_front();
            while (!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();
            dq.push_back(i);
            if (i >= k - 1) ans.push_back(nums[dq.front()]);
        }
        return ans;
    }

    // Using Tree
    // Time O(nlog(k)) Space O(k)
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        map<int, int> mp;
        vector<int> ans;
        if (nums.size() < 1) return ans;
        for (int i = 0; i < k; i++) {
            mp[nums[i]]++;
        }
        for (int i = 0; i <= nums.size() - k; i++) {
            ans.push_back(mp.rbegin()->first);
            if (0 == --mp[nums[i]]) {
                mp.erase(mp.find(nums[i]));
            }
            mp[nums[i + k]]++;
        }
        return ans;
    }
};
