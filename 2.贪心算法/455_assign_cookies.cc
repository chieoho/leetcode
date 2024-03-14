/*
有一群孩子和一堆饼干，每个孩子有一个饥饿度，每个饼干都有一个大小。每个孩子只能吃
一个饼干，且只有饼干的大小不小于孩子的饥饿度时，这个孩子才能吃饱。求解最多有多少孩子
可以吃饱。
(Easy)
*/

#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int findContentChildren(vector<int> &children, vector<int> &cookies)
{
    sort(children.begin(), children.end());
    sort(cookies.begin(), cookies.end());
    int child = 0, cookie = 0;
    while (child < children.size() && cookie < cookies.size())
    {
        if (children[child] <= cookies[cookie])
            ++child;
        ++cookie;
    }
    return child;
}

int main()
{
    vector<int> children = {1, 2};
    vector<int> cookies = {1, 2, 3};
    int result = findContentChildren(children, cookies);
    printf("最多有%d个孩子可以吃饱\n", result);
    return 0;
}
