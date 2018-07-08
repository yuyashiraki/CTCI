class Solution {
public:
    // One pass algorithm
    // Time O(n)  Space O(1)
    int maxProfit(vector<int>& prices) {
        int smallest = INT_MAX, ans = 0;
        int n = prices.size();
        for (int i = 0; i < n; i++) {
            smallest = min(smallest, prices[i]);
            ans = max(ans, prices[i] - smallest);
        }
        return ans;
    }
};
