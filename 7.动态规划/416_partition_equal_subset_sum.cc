/*
给定一个正整数数组，求是否可以把这个数组分成和相等的两部分。
*/
#include <vector>
#include <numeric>
#include <cstdio>

using namespace std;

bool canPartition(vector<int> &nums)
{
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2)
        return false;
    int target = sum / 2, n = nums.size();
    vector<bool> dp(target + 1, false);
    dp[0] = true;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = target; j >= nums[i - 1]; --j)
        {
            dp[j] = dp[j] || dp[j - nums[i - 1]];
        }
    }
    return dp[target];
}

int main()
{
    vector<int> nums = {1, 5, 11, 5};
    printf("%s\n", canPartition(nums) ? "可以" : "不可以");
    return 0;
}
