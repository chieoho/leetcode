/*
有一些球形气球贴在一堵用 XY 平面表示的墙面上。墙面上的气球记录在整数数组 points ，
其中points[i] = [xstart, xend] 表示水平直径在 xstart 和 xend之间的气球。
你不知道气球的确切 y 坐标。
一支弓箭可以沿着 x 轴从不同点 完全垂直地射出。在坐标 x 处射出一支箭，
若有一个气球的直径的开始和结束坐标为 xstart，xend， 且满足xstart ≤ x ≤ xend，
则该气球会被引爆 。可以射出的弓箭的数量没有限制 。 弓箭一旦被射出之后，可以无限地前进。
给你一个数组points，返回引爆所有气球所必须射出的最小弓箭数 。
*/

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int findMinArrowShots(vector<vector<int>> &points)
{
    if (points.empty())
    {
        return 0;
    }
    int n = points.size();
    sort(points.begin(), points.end(), [](vector<int> &a, vector<int> &b)
         { return a[1] < b[1]; });
    int count = 1, prev = points[0][1];
    for (int i = 1; i < n; ++i)
    {
        if (points[i][0] > prev)
        {
            ++count;
            prev = points[i][1];
        }
    }
    return count;
}

int main()
{
    vector<vector<int>> points = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};
    int result = findMinArrowShots(points);
    cout << "最少需要" << result << "支箭" << endl;
    return 0;
}