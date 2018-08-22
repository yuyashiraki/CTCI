/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool comp(Interval &a, Interval &b) {
    return a.start < b.start;
}
class Solution {
public:
    // using Sort
    // Time O(nlog(n))  Space O(1)
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> ans;
        if (intervals.size() == 0) return ans;
        sort(intervals.begin(), intervals.end(), comp);
        ans.push_back(intervals[0]);
        for (int i = 0; i < intervals.size(); i++) {
            if (ans.back().end < intervals[i].start) {
                ans.push_back(intervals[i]);
            } else if (ans.back().end < intervals[i].end) {
                ans.back().end = intervals[i].end;
            }
        }
        return ans;
    }
};
