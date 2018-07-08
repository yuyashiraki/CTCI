class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int num;
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (!cnt) {
                num = nums[i];
                cnt = 1;
            } else if (num == nums[i]) {
                cnt++;
            } else {
                cnt--;
            }
        }
        return num;
    }
};
