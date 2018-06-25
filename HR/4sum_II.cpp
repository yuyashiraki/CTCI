class Solution {
public:
    // Time O(n^2) Space O(n^2)
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> mp;
        int cnt = 0;
        for (int aidx = 0; aidx < A.size(); aidx++) {
            for (int bidx = 0; bidx < B.size(); bidx++)
                if (mp.find(A[aidx] + B[bidx]) == mp.end()) mp[A[aidx] + B[bidx]] = 1;
                else mp[A[aidx] + B[bidx]]++;
        }
        for (int cidx = 0; cidx < C.size(); cidx++) {
            for (int didx = 0; didx < D.size(); didx++) {
                if (mp.find(-(C[cidx] + D[didx])) != mp.end()) cnt += mp[-(C[cidx] + D[didx])];
            }
        }
        return cnt;
    }
};
