class Solution {
public:
    // Binary Search
    // Time O(log(min(n, m)))
    // Space O(1)
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int l1 = nums1.size(), l2 = nums2.size();
        int lo = 0, hi = l1;
        while (lo <= hi) {
            int left1 = (lo + hi) / 2;
            int left2 = (l1 + l2 + 1) / 2 - left1;
            int maxleft1 = left1 == 0 ? INT_MIN : nums1[left1 - 1], minright1 = left1 == l1 ? INT_MAX : nums1[left1];
            int maxleft2 = left2 == 0 ? INT_MIN : nums2[left2 - 1], minright2 = left2 == l2 ? INT_MAX : nums2[left2];
            if (maxleft1 <= minright2 && maxleft2 <= minright1) {
                if ((l1 + l2) % 2 == 0) {
                    return ((double)max(maxleft1, maxleft2) + (double)min(minright1, minright2)) / 2;
                } else {
                    return (double)max(maxleft1, maxleft2);
                }
            } else if (maxleft1 > minright2) {
                hi = left1 - 1;
            } else {
                lo = left1 + 1;
            }
        }
    }
};
