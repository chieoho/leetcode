/*
给定一个非负整数，求它的开方，向下取整。
*/
#include <iostream>

using namespace std;

int mySqrt(int x)
{
    if (x == 0)
    {
        return 0;
    }
    int left = 1, right = x, ans = 0;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;  
        if (mid <= x / mid) 
        {
            left = mid + 1;  // 注意这里是mid+1，因为mid已经判断过了
            ans = mid; // 更新结果（后面计算不符合条件不记录）
        }
        else
        {
            right = mid - 1;
        }
    }
    return ans;
}

int main()
{
    int a = 8;
    cout << "开方结果为：" << mySqrt(a) << endl;
    return 0;
}
