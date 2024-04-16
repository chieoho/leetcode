/*
给定多个区间，计算让这些区间互不重叠所需要移除区间的最少个数。起止相连不算重叠。
(Medium)
*/
#include <vector>
#include <algorithm>
#include <iostream>

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
        if (intervals[i][0] < prev) // 重叠
        {
            ++removed; // 移除当前区间
        }
        else
        {
            prev = intervals[i][1]; // 更新prev
        }
    }
    return removed;
}

int main()
{
    vector<vector<int>> intervals = {{1, 2}, {2, 4}, {1, 3}};
    int result = eraseOverlapIntervals(intervals);
    cout << "最少需要移除" << result << "个区间" << endl;
    return 0;
}
