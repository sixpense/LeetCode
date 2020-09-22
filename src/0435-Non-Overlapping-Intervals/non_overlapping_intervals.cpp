/* non overlapping intervals
 *
 */

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n <= 1) return 0;
        auto myCmp [&](const auto& a, const auto& b) {
            return a[1] < b[1];
        };
        sort(interval.begin(), intervals.end(), myCmp);
        int cnt = 1;
        int end = intervals[0][1];      //  区间动态最小值
    }
}
