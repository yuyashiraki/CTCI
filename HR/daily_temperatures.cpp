class Solution {
public:
    // Stack
    // Time O(n)  Space O(n)
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> STK;
        vector<int> ans(temperatures.size());
        for (int i = 0; i < temperatures.size(); i++) {
            while (!STK.empty() && STK.top().first < temperatures[i]) {
                ans[STK.top().second] = i - STK.top().second;
                STK.pop();
            }
            STK.push(make_pair(temperatures[i], i));
        }
        while (!STK.empty()) {
            ans[STK.top().second] = 0;
            STK.pop();
        }
        return ans;
    }
};
