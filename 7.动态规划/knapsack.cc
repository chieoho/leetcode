#include <vector>
#include <cstdio>

using namespace std;

int knapsack1(vector<int> weights, vector<int> values, int N, int W)
{
    vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));
    for (int i = 1; i <= N; ++i)
    {
        int w = weights[i - 1], v = values[i - 1];
        for (int j = 1; j <= W; ++j)
        {
            if (j >= w)  // 可以装下第 i 个物品
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w] + v);  // 装或者不装
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[N][W];
}

int knapsack(vector<int> weights, vector<int> values, int N, int W)
{
    vector<int> dp(W + 1, 0);
    for (int i = 1; i <= N; ++i)
    {
        int w = weights[i - 1], v = values[i - 1];
        for (int j = W; j >= w; --j)
        {
            dp[j] = max(dp[j], dp[j - w] + v);
        }
    }
    return dp[W];
}

int main()
{
    vector<int> weights = {2, 1, 3, 2};
    vector<int> values = {3, 2, 4, 2};
    int N = 4, W = 5;
    int res = knapsack(weights, values, N, W);
    printf("%d\n", res);
    return 0;
}