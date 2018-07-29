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
    // One pass
    // Time O(n)  Space O(n)
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> ans;
        int i, j;
        bool flg = true;
        for (i = 0; i < intervals.size(); i++) {
            if (intervals[i].end < newInterval.start) {
                //cout << "DEBUG1 " << i << endl;
                ans.push_back(intervals[i]);
                //cout << intervals[i].start << " " << intervals[i].end << endl;
            }
            if (intervals[i].start <= newInterval.start && newInterval.start <= intervals[i].end) {
                newInterval.start = intervals[i].start;
            }
            if (intervals[i].start <= newInterval.end && newInterval.end <= intervals[i].end) {
                newInterval.end = intervals[i].end;
                //cout << "DEBUG2 " << i << endl;
                ans.push_back(newInterval);
                //cout << newInterval.start << " " << newInterval.end << endl;
                flg = false;
            }
            if (newInterval.end < intervals[i].start) {
                if (flg) {
                    //cout << "DEBUG3 " << i << endl;
                    ans.push_back(newInterval);
                    //cout << newInterval.start << " " << newInterval.end << endl;
                    flg = false;
                }
                //cout << "DEBUG4 " << i << endl;
                ans.push_back(intervals[i]);
                //cout << intervals[i].start << " " << intervals[i].end << endl;
            }
        }
        if (flg) {
            ans.push_back(newInterval);
        }
        return ans;
    }
};
