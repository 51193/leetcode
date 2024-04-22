#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, 0x7777777);

        dp[0] = 0;

        for (size_t i{1}; i < amount + 1; i++)
        {
            for (auto &j : coins)
            {
                if (j <= i)
                {
                    dp[i] = min(dp[i], dp[i - j] + 1);
                }
            }
        }

        return (*(dp.rbegin()) == 0x7777777) ? -1 : *(dp.rbegin());
    }
};

int main()
{
    vector<int> coins{1, 2, 5};
    Solution s;
    cout << s.coinChange(coins, 11);
}