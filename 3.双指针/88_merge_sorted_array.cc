/*
给定两个有序数组，把两个数组合并为一个。
88. Merge Sorted Array (Easy)
*/
#include <vector>
#include <iostream>

using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int pos = m-- + n-- - 1;
    while (m >= 0 && n >= 0)
    {
        nums1[pos--] = nums1[m] > nums2[n] ? nums1[m--] : nums2[n--];
    }
    while (n >= 0)
    {
        nums1[pos--] = nums2[n--];
    }
}

int main()
{
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    merge(nums1, 3, nums2, 3);
    cout << "合并后的数组为：";
    for (int i = 0; i < nums1.size(); ++i)
    {
        cout << nums1[i] << " ";
    }
    cout << endl;
    return 0;
}
