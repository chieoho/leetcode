/*
给定多个区间，计算让这些区间互不重叠所需要移除区间的最少个数。起止相连不算重叠。
(Medium)
*/
#include <vector>
#include <algorithm>

using namespace std;

int eraseOverlapIntervals(vector<vector<int>> &intervals)
{
    if (intervals.empty())
    {
        return 0;
    }
    int n = intervals.size();
    sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b)
         { return a[1] < b[1]; });
    int removed = 0, prev = intervals[0][1];
    for (int i = 1; i < n; ++i)
    {
        if (intervals[i][0] < prev)
        {
            ++removed;
        }
        else
        {
            prev = intervals[i][1];
        }
    }
    return removed;
}