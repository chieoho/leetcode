/*
给定一个二维的 0-1 矩阵，其中 0 表示海洋，1 表示陆地。单独的或相邻的陆地可以形成岛屿，
每个格子只与其上下左右四个格子相邻。求最大的岛屿面积。
*/
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

vector<int> direction{-1, 0, 1, 0, -1};

// 辅函数
int dfs(vector<vector<int>> &grid, int r, int c)
{
    if (grid[r][c] == 0) // 为水域或访问过则返回
        return 0;
    grid[r][c] = 0; // 标记为已访问
    int x, y, area = 1;
    for (int i = 0; i < 4; ++i) // 四个方向，深度优先
    {
        x = r + direction[i], y = c + direction[i + 1];
        if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size())
        {
            area += dfs(grid, x, y);
        }
    }
    return area;
}

// 主函数
int maxAreaOfIsland(vector<vector<int>> &grid)
{
    if (grid.empty() || grid[0].empty())
        return 0;
    int max_area = 0;
    for (int i = 0; i < grid.size(); ++i)
    {
        for (int j = 0; j < grid[0].size(); ++j)
        {
            if (grid[i][j] == 1) // 未访问过的陆地
            {
                max_area = max(max_area, dfs(grid, i, j));
            }
        }
    }
    return max_area;
}

int main()
{
    vector<vector<int>> grid{{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                             {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
                             {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};
    int area = maxAreaOfIsland(grid);
    cout << "最大岛屿面积是：" << area << endl;
    return 0;
}
