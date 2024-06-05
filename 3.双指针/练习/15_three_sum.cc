/*
给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，
同时还满足 nums[i] + nums[j] + nums[k] == 0 。请你返回所有和为 0 且不重复的三元组。
*/

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> result;
    if (nums.size() < 3)
    {
        return result;
    }
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 2; ++i)  // 选取第一个数，后面两个数用双指针
    {
        if (i > 0 && nums[i] == nums[i - 1])  // 去重
        {
            continue;
        }
        int l = i + 1, r = nums.size() - 1;
        while (l < r)
        {
            int sum = nums[i] + nums[l] + nums[r];
            if (sum < 0)
            {
                ++l;
            }
            else if (sum > 0)
            {
                --r;
            }
            else
            {
                result.push_back({nums[i], nums[l], nums[r]});
                while (l < r && nums[l] == nums[l + 1]) // 去重
                {
                    ++l;
                }
                while (l < r && nums[r] == nums[r - 1]) // 去重
                {
                    --r;
                }
                ++l;
                --r;
            }
        }
    }
    return result;
}

int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = threeSum(nums);
    for (int i = 0; i < result.size(); ++i)
    {
        cout << "[";
        for (int j = 0; j < result[i].size(); ++j)
        {
            cout << result[i][j] << " ";
        }
        cout << "]" << endl;
    }
    return 0;
}