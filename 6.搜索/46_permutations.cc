/*
给定一个无重复数字的整数数组，求其所有的排列方式。
*/
#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> res; // 存储结果的数组
        backtrack(nums, res, 0); // 回溯算法
        return res;
    }

private:
    void backtrack(vector<int> &nums, vector<vector<int>> &res, int start)
    {
        if (start == nums.size() - 1)
        {
            res.push_back(nums); // 将这种排列方式加入结果数组
            return;
        }
        for (int i = start; i < nums.size(); i++) // 从开始位置遍历数组
        {
            swap(nums[start], nums[i]);      // 交换开始位置和当前位置的元素
            backtrack(nums, res, start + 1); // 递归调用，开始位置后移
            swap(nums[start], nums[i]);      // 恢复数组，以便进行下一次交换
        }
    }
};

int main()
{
    vector<int> nums = {1, 2, 3};
    Solution solution;
    vector<vector<int>> res = solution.permute(nums);
    for (auto &vec : res)
    {
        for (auto &num : vec)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}