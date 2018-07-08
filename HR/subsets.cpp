#define ll long long

class Solution {
public:
    set<ll> memo;
    void recur(vector<int>& nums, ll bits, int length) {
        //cout << bits << " " << length << endl;
        if (length > nums.size()) {
            return;
        }
        if (memo.find(bits) != memo.end()) {
            return;
        }
        memo.insert(bits);
        for (int i = 0; i < nums.size(); i++) {
            recur(nums, bits | (1 << i) , length + 1);
        }

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        recur(nums, 0, 0);
        for (auto itr = memo.begin(); itr != memo.end(); ++itr) {
            vector<int> tmp;
            int cnt = 0, num = *itr;
            while (num) {
                if (num % 2) {
                    tmp.push_back(nums[cnt]);
                }
                num /= 2;
                cnt++;
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};
