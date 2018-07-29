class Solution {
public:
    // Binary seach pivot
    // Time O(log(n))  Space O(1)
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) return -1;
        int l = 0, r = nums.size() - 1, mid, pivot;
        while (l < r) {
            mid = (l + r) / 2;
            if (nums[r] < nums[mid]) l = mid + 1;
            else r = mid;
        }
        pivot = l;
        cout << pivot << endl;
        l = 0, r = nums.size() - 1;
        while (l <= r) {
            mid = (l + r) / 2;
            int rmid = (mid + pivot) % nums.size();
            if (nums[rmid] == target) return rmid;
            if (nums[rmid] < target) l = mid + 1;
            else r = mid - 1;
        }
        return -1;
    }
};
