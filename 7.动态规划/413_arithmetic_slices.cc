/*
给定一个数组，求这个数组中连续且等差的子数组一共有多少个。
*/
#include <vector>
#include <numeric>
#include <cstdio>

using namespace std;

int numberOfArithmeticSlices(vector<int> &nums)
{
    int n = nums.size();
    if (n < 3)
        return 0;
    vector<int> dp(n, 0);
    for (int i = 2; i < n; ++i)
    {
        if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2])
        {
            dp[i] = dp[i - 1] + 1;
        }
    }
    return accumulate(dp.begin(), dp.end(), 0);
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 6, 8, 10};
    printf("一共有%d个等差子数组\n", numberOfArithmeticSlices(nums));
    return 0;
}