/*
在一个增序的整数数组里找到两个数，使它们的和为给定值。已知有且只有一对解。
(Easy)
*/
#include <vector>
#include <cstdio>

using namespace std;

vector<int> twoSum(vector<int> &numbers, int target)
{
    int l = 0, r = numbers.size() - 1, sum;
    while (l < r)
    {
        sum = numbers[l] + numbers[r];
        if (sum == target)
            break;
        if (sum < target)
            ++l;
        else
            --r;
    }
    return vector<int>{l + 1, r + 1};
}

int main()
{
    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = twoSum(numbers, target);
    printf("第%d个数字和第%d个数字的和等于给定值%d\n", result[0], result[1], target);
    return 0;
}
