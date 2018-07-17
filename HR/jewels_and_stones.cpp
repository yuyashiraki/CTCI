class Solution {
public:
    int numJewelsInStones(string J, string S) {
        set<char> st;
        int ans = 0;
        for (int i = 0; i < J.size(); i++) {
            st.insert(J[i]);
        }
        for (int i = 0; i < S.size(); i++) {
            if (st.find(S[i]) != st.end()) {
                ans++;
            }
        }
        return ans;
    }
};
