/*
给定两个字符串S和T ，求S中包含T所有字符的最短连续子字符串的长度，同时要求时间
复杂度不得超过O(n)。(Hard)

Input: S = "ADOBECODEBANC", T = "ABC"
Output: "BANC"
*/
#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

string minWindow(string s, string t)
{
    vector<int> map(128, 0);
    for (auto c : t)
    {
        map[c]++; // 记录t中每个字符出现的次数
    }
    int counter = t.size(), begin = 0, end = 0, d = INT_MAX, head = 0;
    while (end < s.size())
    {
        if (map[s[end++]]-- > 0)
        {
            counter--;
        }
        while (counter == 0)
        {
            if (end - begin < d) // 更短则更新（要点在这里）
            {
                d = end - begin;
                head = begin;
            }
            if (map[s[begin++]]++ == 0) // 移动begin指针
            {
                counter++;
            }
        }
    }
    cout << "end: " << end << endl;
    return d == INT_MAX ? "" : s.substr(head, d);
}

int main()
{
    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout << minWindow(s, t) << endl;
    return 0;
}
