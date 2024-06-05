/*
给定一个只包含加、减和乘法的数学表达式，求通过加括号可以得到多少种不同的结果。
*/
#include <vector>
#include <string>
#include <cstdio>

using namespace std;

// 递归函数，用于计算不同加括号方式的结果
vector<int> diffWaysToCompute(string expression)
{
    vector<int> result;

    // 遍历输入字符串，找到运算符位置
    for (int i = 0; i < expression.size(); i++)
    {
        char c = expression[i];

        // 如果当前字符是运算符，则将左右两边的表达式分别计算结果
        if (c == '+' || c == '-' || c == '*')
        {
            vector<int> left = diffWaysToCompute(expression.substr(0, i));
            vector<int> right = diffWaysToCompute(expression.substr(i + 1));

            // 将左右两边的结果进行组合运算，并将结果存入结果集中
            for (int l : left)
            {
                for (int r : right)
                {
                    switch (c)
                    {
                    case '+':
                        result.push_back(l + r);
                        break;
                    case '-':
                        result.push_back(l - r);
                        break;
                    case '*':
                        result.push_back(l * r);
                        break;
                    }
                }
            }
        }
    }

    // 如果结果集为空，说明输入字符串是一个数字，直接将其转为整数并存入结果集中
    if (result.empty())
    {
        result.push_back(stoi(expression));
    }

    return result;
}

int main()
{
    string input = "2-1-1+2*3-1+6-3*5-8";
    vector<int> result = diffWaysToCompute(input);

    printf("一共有 %d 种不同的结果：\n", result.size());
    // for (int i : result)
    // {
    //     printf("%d ", i);
    // }
    // printf("\n");
    return 0;
}
