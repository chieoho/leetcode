/*
一群孩子站成一排，每一个孩子有自己的评分。现在需要给这些孩子发糖果，规则是如果一
个孩子的评分比自己身旁的一个孩子要高，那么这个孩子就必须得到比身旁孩子更多的糖果；所
有孩子至少要有一个糖果。求解最少需要多少个糖果。
(Hard)
*/
#include <vector>
#include <numeric>
#include <cstdio>

using namespace std;

int candy(vector<int> &ratings)
{
    int size = ratings.size();
    if (size < 2)
    {
        return size;
    }
    vector<int> num(size, 1);
    for (int i = 1; i < size; ++i)
    {
        if (ratings[i] > ratings[i - 1])
        {
            num[i] = num[i - 1] + 1; // 这里不用max，因为num[i]是1
        }
    }
    for (int i = size - 1; i > 0; --i)
    {
        if (ratings[i] < ratings[i - 1])
        {
            num[i - 1] = max(num[i - 1], num[i] + 1);
        }
    }
    // std::accumulate 可以很方便地求和
    return accumulate(num.begin(), num.end(), 0);
}

int main()
{
    vector<int> ratings = {1, 0, 2};
    int result = candy(ratings);
    printf("最少需要%d个糖果\n", result);
    return 0;
}
