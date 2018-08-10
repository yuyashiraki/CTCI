class Solution {
public:
    // Binary Search
    // Time O(log(n))  Space O(1)
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int lo = 0, hi = arr.size();
        vector<int> ans;
        if (!k) ans;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (arr[mid] < x) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
            //cout << lo << ' ' << hi << endl;
        }
        int left, right;
        if (lo < arr.size() && arr[lo] == x) {
            left = lo - 1; right = lo + 1;
            k--;
        } else {
            left = lo - 1;
            right = lo;
        }
        while (k--) {
            if (left >= 0 && (right >= arr.size() || x - arr[left] <= arr[right] - x)) {
                left--;
                continue;
            } else {
                right++;
                continue;
            }
        }
        return vector<int>(&arr[left + 1], &arr[right]);
    }
};
