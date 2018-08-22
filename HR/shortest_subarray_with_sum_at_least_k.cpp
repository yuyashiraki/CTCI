class Solution {
public:
    // Sliding window using DeQueue
    // Time O(n)  Space O(n)
    int shortestSubarray(vector<int>& A, int K) {
        int sum = 0, ans = INT_MAX;
        vector<int> P;
        P.push_back(0);
        for (int i = 0; i < A.size(); i++) {
            sum += A[i];
            P.push_back(sum);
        }
        deque<int> Q;
        for (int i = 0; i <= A.size(); i++) {
            while (!Q.empty() && P[i] - P[Q.front()] >= K) {
                ans = min(ans, i - Q.front());
                Q.pop_front();
            }
            while (!Q.empty() && P[Q.back()] >= P[i]) {
                Q.pop_back();
            }
            Q.push_back(i);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
