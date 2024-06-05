/*
给定 n 节台阶，每次可以走一步或走两步，求一共有多少种方式可以走完这些台阶。
*/
#include <cstdio>

using namespace std;

/*
int climbStairs(int n)
{
    if (n <= 2)
        return n;
    vector<int> dp(n + 1, 1);
    for (int i = 2; i <= n; ++i)
    {
        dp[i] = dp[i - 1] + dp[i - 2]; // 状态转移方程，当前台阶的走法等于前两个台阶的走法之和
    }
    return dp[n];
}
*/

int climbStairs(int n)
{
    if (n <= 2)
        return n;
    int pre2 = 1, pre1 = 2, cur;
    for (int i = 2; i < n; ++i)
    {
        cur = pre1 + pre2;
        pre2 = pre1;
        pre1 = cur;
    }
    return cur;
}

int main()
{
    printf("一共有%d种方式\n", climbStairs(10));
    return 0;
}
