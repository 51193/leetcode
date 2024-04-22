#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int findChampion(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<bool> rank(n, true);
        for (int i{0}; i < n; i++)
        {
            for (int j{0}; j < i; j++)
            {
                if (grid[i][j])
                {
                    rank[j] = false;
                }
            }
        }
        auto ans = find(rank.begin(), rank.end(), true);
        return ans - rank.begin();
    }
};