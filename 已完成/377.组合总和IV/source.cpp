#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int combinationSum4(vector<int> &nums, int target)
    {
        vector<unsigned long long int> dp;
        dp.push_back(1);
        for (int i{1}; i <= target; i++)
        {
            dp.push_back(0);
            for (auto &j : nums)
            {
                if (j <= i)
                {
                    dp[i] += dp[i - j];
                }
            }
        }
        return dp[target];
    }
};