#include <iostream>
#include <vector>
#include
using namespace std;

class Solution
{
public:
    int minSkips(vector<int> &dist, int speed, int hoursBefore)
    {
        int n = dist.size();
        vector<vector<long long int>> dp(n + 1, vector<long long int>(n + 1, -1));

        dp[0][0] = 0;

        for (int i{1}; i < n + 1; i++)
        {
            dp[i][0] = dp[i - 1][0] + (dist[i - 1] / speed + (int(bool(dist[i - 1] % speed)))) * speed;

            for (int j{1}; j < i; j++)
            {
                dp[i][j] = min(((dp[i - 1][j] + dist[i - 1]) / speed + (int(bool((dp[i - 1][j] + dist[i - 1]) % speed)))) * speed, (dp[i - 1][j - 1]) + dist[i - 1]);
            }

            dp[i][i] = dp[i - 1][i - 1] + dist[i - 1];
        }

        for (int i{0}; i < n + 1; i++)
        {
            if (dp[n][i] <= (long long int)hoursBefore * (long long int)speed)
            {
                return i;
            }
        }
        return -1;
    }
};