class Solution {
public:
    // Sliding Window
    // Time O(n)  Space O(n)
    int kEmptySlots(vector<int>& flowers, int k) {
        int n = flower.size();
        if (n == 0) return -1;
        vector<int> days(flower.size());
        for (int i = 0; i < n; i++) days[flowers[i]] = i;
        int ans = INT_MAX, l = 0, r = k + 1;
        for (int i = 0; i < n; i++) {
            if (days[i] < days[l] || days[i] <= days[r]) {
                if (r == i) ans = min(ans, max(days[l], days[r]));
                l = i;
                r = i + k + 1;
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }

    // Using Binary Search Tree
    // Time O(nlog(n)) Space O(n)
    int kEmptySlots(vector<int>& flowers, int k) {
        set<int> ST;
        for (int i = 0; i < flowers.size(); i++) {
            ST.insert(flowers[i]);
            auto itr = ST.find(flowers[i]);
            if (itr != ST.begin()) {
                auto pred = itr;
                pred--;
                //cout << "pred:" << *pred << endl;
                if (*itr - *pred - 1 == k) return i + 1;
            }
            auto suc = itr;
            suc++;
            if (suc != ST.end() && *suc - *itr - 1 == k) return i + 1;
            //if (suc != ST.end()) cout << "suc:" << *suc << endl;
        }
        return -1;
    }
};
