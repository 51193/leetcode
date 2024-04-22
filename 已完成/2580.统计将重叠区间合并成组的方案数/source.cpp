#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int countWays(vector<vector<int>> &ranges)
    {
        sort(ranges.begin(), ranges.end(), [](vector<int> &a, vector<int> &b)
             { return a[0] < b[0]; });

        int overlap_cnt{0};

        int n = ranges.size();
        for (size_t i{0}; i < n; i++)
        {
            int temp = ranges[i][1];

            for (size_t j{i + 1}; j < n; j++)
            {
                if (ranges[j][0] <= temp)
                {
                    temp = max(ranges[j][1], temp);
                    i++;
                    overlap_cnt++;
                }
                else
                {
                    break;
                }
            }
        }

        int m = ranges.size() - overlap_cnt;
        int ans = 1;

        for (size_t i{0}; i < m; i++)
        {
            ans *= 2;
            ans %= 1000000007;
        }

        return ans;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> vec{
        {34, 56},
        {28, 29},
        {12, 16},
        {11, 48},
        {28, 54},
        {22, 55},
        {28, 41},
        {41, 44}};
    cout << s.countWays(vec);
}