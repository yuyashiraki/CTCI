class Solution {
public:
    // Greedy
    // Time O(n)  Space O(1)
    int maxProfit(vector<int>& prices) {
        int buy1 = INT_MIN, sell1 = 0, buy2 = INT_MIN, sell2 = 0;
        for (int i = 0; i < prices.size(); i++) {
            buy2 = max(buy2, sell1 - prices[i]);
            sell2 = max(sell2, prices[i] + buy2);
            buy1 = max(buy1, -prices[i]);
            sell1 = max(sell1, prices[i]+buy1);
        }
        return sell2;
    }
};
