#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> findColumnWidth(vector<vector<int>> &grid)
    {
        vector<int> ans;
        int size = grid[0].size();
        for (int i{0}; i < size; i++)
        {
            int temp = 0;
            for (auto &j : grid)
            {
                temp = max(int(to_string(j[i]).size()), temp);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};