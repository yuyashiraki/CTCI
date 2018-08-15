class Solution {
public:
    // 2 pass
    // Time O(max(n,m))  Space O(min(n,m))
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) return intersect(nums2, nums1);
        unordered_map<int, int> MP;
        vector<int> ans;
        for (int i = 0; i < nums1.size(); i++) {
            MP[nums1[i]]++;
        }
        for (int i = 0; i < nums2.size(); i++) {
            if (MP.count(nums2[i])) {
                ans.push_back(nums2[i]);
                if (0 == --MP[nums2[i]]) MP.erase(nums2[i]);
            }
        }
        return ans;
    }

    // Sorted using pointer
    // Time O(nlog(n))  Space O(1)
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int idx1 = 0, idx2 = 0;
        vector<int> ans;
        while (idx1 < nums1.size() && idx2 < nums2.size()) {
            if (nums1[idx1] == nums2[idx2]) {
                ans.push_back(nums1[idx1]);
                idx1++;
                idx2++;
            } else if (nums1[idx1] > nums2[idx2]) {
                idx2++;
            } else {
                idx1++;
            }
        }
        return ans;
    }};
