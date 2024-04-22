#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int findChampion(int n, vector<vector<int>> &edges)
    {
        vector<bool> rank(n, true);
        int loser_cnt = 0;
        for (auto &i : edges)
        {
            if (rank[i[1]])
            {
                loser_cnt++;
            }
            rank[i[1]] = false;
        }
        if (loser_cnt != n - 1)
        {
            return -1;
        }
        else
        {
            auto ans = find(rank.begin(), rank.end(), true);
            return ans - rank.begin();
        }
    }
};