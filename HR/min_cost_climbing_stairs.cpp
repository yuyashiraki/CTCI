class Solution {
public:
    // DP
    // Time O(n)  Space O(n)
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> min_cost(cost.size() + 1, INT_MAX);
        min_cost[0] = cost[0]; min_cost[1] = cost[1]; cost.push_back(0);
        for (int i = 0; i < cost.size(); i++) {
            if (i < cost.size() - 1) {
                min_cost[i + 2] = min(min_cost[i + 2], min_cost[i] + cost[i + 2]);
                //cout << i + 2 << " " << min_cost[i + 2] << endl;
            }
            min_cost[i + 1] = min(min_cost[i + 1], min_cost[i] + cost[i + 1]);
            //cout << i + 1 << " " << min_cost[i + 1] << endl;
        }
        return min_cost[cost.size() - 1];
    }
};
