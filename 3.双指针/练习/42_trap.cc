/*
给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
*/
#include <vector>
#include <cstdio>
using namespace std;

int trap(vector<int> &height)
{
    // 获取高度数组的长度
    int n = height.size();
    // 如果长度小于等于2，那么无法积水，直接返回0
    if (n <= 2)
    {
        return 0;
    }

    // 初始化左右指针
    int left = 0, right = n - 1;
    // 初始化左右两边的最大高度
    int leftMax = 0, rightMax = 0;
    // 初始化结果
    int ans = 0;

    // 当左指针小于右指针时，进行循环
    while (left < right)
    {
        // 如果左边的高度小于右边的高度
        if (height[left] < height[right])
        {
            // 如果当前的高度大于等于左边的最大高度，更新左边的最大高度
            if (height[left] >= leftMax)
            {
                leftMax = height[left];
            }
            else
            {
                // 否则，积水量等于左边的最大高度减去当前的高度
                ans += leftMax - height[left];
            }
            // 左指针向右移动
            left++;
        }
        else
        {
            // 如果当前的高度大于等于右边的最大高度，更新右边的最大高度
            if (height[right] >= rightMax)
            {
                rightMax = height[right];
            }
            else
            {
                // 否则，积水量等于右边的最大高度减去当前的高度
                ans += rightMax - height[right];
            }
            // 右指针向左移动
            right--;
        }
    }

    // 返回积水量
    return ans;
}

int main()
{
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    printf("下雨后能接%d个单位的雨水\n", trap(height));
    return 0;
}
