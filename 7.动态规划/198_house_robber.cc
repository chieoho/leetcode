/*
假如你是一个劫匪，并且决定抢劫一条街上的房子，每个房子内的钱财数量各不相同。
如果你抢了两栋相邻的房子，则会触发警报机关。求在不触发机关的情况下最多可以抢劫多少钱。
*/
#include <vector>
#include <cstdio>

using namespace std;

int rob(vector<int> &nums)
{
    if (nums.empty())
        return 0;
    int n = nums.size();
    if (n == 1)
        return nums[0];
    int pre2 = 0, pre1 = 0, cur;
    for (int i = 0; i < n; ++i)
    {
        cur = max(pre2 + nums[i], pre1);
        pre2 = pre1;
        pre1 = cur;
    }
    return cur;
}

int main()
{
    vector<int> nums = {2, 7, 9, 3, 1};
    printf("最多可以抢劫%d元\n", rob(nums));
    return 0;
}