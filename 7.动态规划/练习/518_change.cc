/*
给你一个整数数组 coins 表示不同面额的硬币，另给一个整数 amount 表示总金额。
请你计算并返回可以凑成总金额的硬币组合数。
*/

#include <vector>
#include <cstdio>

using namespace std;

int change(int amount, vector<int> &coins)
{
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;

    for (int coin : coins)
    {
        for (int x = coin; x <= amount; x++)
        {
            // 当前金额的组合数等于不使用当前硬币的组合数（即dp[x]）加上使用当前硬币的组合数（即dp[x - coin]）
            dp[x] += dp[x - coin];
        }
    }

    return dp[amount];
}

int main()
{
    vector<int> coins = {1, 2, 5};
    int amount = 5;
    int result = change(amount, coins);
    printf("硬币组合数为：%d\n", result);
    return 0;
}
