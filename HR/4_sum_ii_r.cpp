class Solution {
public:
    // using Hash
    // Time O(n^2)  Space O(n^2)
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int,int> mp;
        int n = A.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                mp[A[i]+B[j]]++;
            }
        }
        for (int k = 0; k < n; k++) {
            for (int l = 0; l < n; l++) {
                int key = -(C[k]+D[l]);
                if (mp.count(key)) {
                    ans += mp[key];
                }
            }
        }
        return ans;
    }
};
