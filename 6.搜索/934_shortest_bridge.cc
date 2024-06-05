/*
给定一个二维 0-1 矩阵，其中 1 表示陆地，0 表示海洋，每个位置与上下左右相连。
已知矩阵中有且只有两个岛屿，求最少要填海造陆多少个位置才可以将两个岛屿相连。
*/
#include <queue>
#include <vector>
#include <cstdio>

using namespace std;

// 定义四个方向
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

class Solution
{
public:
    int shortestBridge(vector<vector<int>> &A)
    {
        int n = A.size(), m = A[0].size();
        queue<pair<int, int>> q;
        bool flag = false; // 用于标记是否找到第一个岛屿

        // 先找到第一个岛屿，并进行标记
        for (int i = 0; i < n; ++i)
        {
            if (flag)
                break;
            for (int j = 0; j < m; ++j)
            {
                if (A[i][j] == 1)
                {
                    dfs(A, i, j, q);
                    flag = true;
                    break;
                }
            }
        }

        // 然后从第一个岛屿开始，扩展到第二个岛屿
        int step = 0;
        while (!q.empty())
        {
            int sz = q.size();
            while (sz--)
            {
                auto [x, y] = q.front();
                q.pop();
                for (int i = 0; i < 4; ++i)
                {
                    int tx = x + dx[i];
                    int ty = y + dy[i];
                    if (tx < 0 || tx >= n || ty < 0 || ty >= m || A[tx][ty] == 2)
                        continue;
                    if (A[tx][ty] == 1)
                        return step;
                    q.push({tx, ty});
                    A[tx][ty] = 2; // 标记为已访问
                }
            }
            step++;
        }
        return -1;
    }

private:
    void dfs(vector<vector<int>> &A, int x, int y, queue<pair<int, int>> &q)
    {
        if (x < 0 || x >= A.size() || y < 0 || y >= A[0].size() || A[x][y] != 1)
            return;
        A[x][y] = 2; // 标记为已访问
        q.push({x, y});
        for (int i = 0; i < 4; ++i)
        {
            dfs(A, x + dx[i], y + dy[i], q);
        }
    }
};

int main()
{
    vector<vector<int>> A = {{0, 1}, {1, 0}};
    Solution obj;
    int result = obj.shortestBridge(A);
    printf("最少要填海造陆%d个位置\n", result); 
    return 0;
}
