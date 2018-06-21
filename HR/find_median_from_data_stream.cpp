class MedianFinder {
private:
    vector<int> nums;
    priority_queue<int> lo;  // max heap
    priority_queue<int, vector<int>, greater<int>> hi;  // min heap
    multiset<int> data;
    multiset<int>::iterator lo_median, hi_median;
public:
    /** initialize your data structure here. */
    MedianFinder() {
        lo_median = hi_median = data.end();
    }
    void addNum(int num) {
        size_t n = data.size();
        data.insert(num);
        if (!n) {
            lo_median = hi_median = data.begin();
        } else if (n & 1) { // odd size before --> lo == hi, even size now
            if (num < *lo_median) {
                // num < lo
                lo_median--;
            } else {
                // num >= hi
                hi_median++;
            }
        } else { // even size before(i.e. hi == lo + 1) --> lo == hi, odd size now
            if (num > *lo_median && num < *hi_median) {
                lo_median++;
                hi_median--;
            } else if (num >= *hi_median) {
                lo_median++;
            } else {
                lo_median = --hi_median;
            }
        }
    }
    double findMedian() {
        return (double)(*lo_median + *hi_median) / 2;
    }

    // using two heaps
    void addNum2(int num) {
        lo.push(num);
        hi.push(lo.top());
        lo.pop();
        while (hi.size() > lo.size()) {
            lo.push(hi.top());
            hi.pop();
        }
    }
    double findMedian2() {
        if (lo.size() == hi.size()) {
            return (double) (lo.top() + hi.top()) / 2;
        } else {
            return lo.top();
        }
    }

    // Insertion Sort
    void addNum1(int num) {
        /*
        int l = 0, r = (int) nums.size();
        while (l < r) {
            int t = (l + r) / 2;
            if (nums[t] < num) {
                l = t + 1;
            } else {
                r = t;
            }
        }
        nums.insert(nums.begin() + r, num);
        */
        nums.insert(lower_bound(nums.begin(), nums.end(), num), num);
    }
    double findMedian1() {
        int n = (int) nums.size();
        if (n % 2) return (double) nums[n / 2];
        else {
            return (double) (nums[n / 2 - 1] + nums[n / 2]) / 2;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
