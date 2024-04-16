/*
假设有一个很长的花坛，一部分地块种植了花，另一部分却没有。可是，花不能种植在相邻的地块上，它们会争夺水源，两者都会死去。
*/
#include <vector>
#include <iostream>

using namespace std;

bool canPlaceFlowers(vector<int> &flowerbed, int n)
{
    int count = 0;
    for (int i = 0; i < flowerbed.size(); i++)
    {
        if (flowerbed[i] == 0)
        {
            int pre = i == 0 ? 0 : flowerbed[i - 1];
            int next = i == flowerbed.size() - 1 ? 0 : flowerbed[i + 1];
            if (pre == 0 && next == 0)
            {
                flowerbed[i] = 1;
                count++;
            }
        }
    }
    return count >= n;
}

int main()
{
    vector<int> flowerbed = {1, 0, 0, 0, 1};
    int n = 1;
    bool result = canPlaceFlowers(flowerbed, n);
    cout << boolalpha << result << endl;
    return 0;
}