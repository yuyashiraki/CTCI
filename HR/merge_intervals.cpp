/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    // Using sort
    // Time O(nlog(n))  Space O(n)
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), compare_);
        vector<Interval> ans;
        for (int i = 0; i < intervals.size(); i++) {
            //cout << intervals[i].start << endl;
            if (!ans.size()) {
                ans.push_back(intervals[i]);
            } else {
                Interval& prv = ans.back(), cur = intervals[i];
                if (prv.start <= cur.start && cur.start <= prv.end) {
                    prv.end = max(prv.end, cur.end);
                } else {
                    ans.push_back(cur);
                }
            }
        }
        return ans;
    }

    // Using Sweeping line
    // Time O(nlog(n))  Space O(n)
    vector<Interval> merge(vector<Interval>& intervals) {
        set<tuple<int, bool, int>> St;  // true:end, false:start
        for (int i = 0; i < intervals.size(); i++) {
            St.emplace(intervals[i].start, false, i);
            St.emplace(intervals[i].end, true, i);
        }
        int start = INT_MAX, end = INT_MAX, count = 0;
        vector<Interval> ans;
        if (!intervals.size()) {
            return ans;
        }
        for (auto itr = St.begin(); itr != St.end(); ++itr) {
            if (!get<1>(*itr)) {
                if (!count)
                    start = get<0>(*itr);
                count++;
            } else {
                count--;
                if (!count) {
                    end = get<0>(*itr);
                    Interval elm(start, end);
                    ans.push_back(elm);
                }
            }
        }
        return ans;
    }
};
