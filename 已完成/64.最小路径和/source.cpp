#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        stack<int> m_pos;
        stack<int> n_pos;

        vector<vector<int>> cnt(m, vector<int>(n, 0x7fffffff));

        m_pos.push(0);
        n_pos.push(0);

        cnt[0][0] = grid[0][0];

        while (!m_pos.empty())
        {
            int m_temp = m_pos.top();
            int n_temp = n_pos.top();

            m_pos.pop();
            n_pos.pop();

            int x = cnt[m_temp][n_temp];
            if (m_temp + 1 < m && cnt[m_temp + 1][n_temp] > x + grid[m_temp + 1][n_temp])
            {
                cnt[m_temp + 1][n_temp] = x + grid[m_temp + 1][n_temp];
                m_pos.push(m_temp + 1);
                n_pos.push(n_temp);
            }

            if (n_temp + 1 < n && cnt[m_temp][n_temp + 1] > x + grid[m_temp][n_temp + 1])
            {
                cnt[m_temp][n_temp + 1] = x + grid[m_temp][n_temp + 1];
                m_pos.push(m_temp);
                n_pos.push(n_temp + 1);
            }
        }

        return cnt[m - 1][n - 1];
    }
};