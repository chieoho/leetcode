/*
输入一个数组和一个目标值 k，输出第 k 大的数字。
*/
#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> &nums, int left, int right)
{
    int pivot = nums[left], l = left + 1, r = right;
    while (l <= r)
    {
        if (nums[l] < pivot && nums[r] > pivot)
        {
            swap(nums[l++], nums[r--]);
        }
        if (nums[l] >= pivot)
        {
            l++;
        }
        if (nums[r] <= pivot)
        {
            r--;
        }
    }
    swap(nums[left], nums[r]);
    return r;
}

int findKthLargest(vector<int> &nums, int k)
{
    int left = 0, right = nums.size() - 1;
    while (true)
    {
        int pos = partition(nums, left, right);
        if (pos == k - 1)
        {
            return nums[pos];
        }
        if (pos < k - 1)
        {
            left = pos + 1;
        }
        else
        {
            right = pos - 1;
        }
    }
}

int main()
{
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;
    cout << findKthLargest(nums, k) << endl;
    return 0;
}
