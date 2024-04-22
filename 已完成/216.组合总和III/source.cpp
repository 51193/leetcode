#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> ans;
        vector<int> path;
        function<void(int, int)> dfs = [&](int i, int t)
        {
            int d = k - path.size(); // 还要选 d 个数
            if (t < 0 or t > (i * 2 - d + 1) * d / 2)
            { // 剪枝
                return;
            }
            if (d == 0)
            { // 找到一个合法组合
                ans.emplace_back(path);
                return;
            }
            for (int j = i; j >= d; j--)
            {
                path.push_back(j);
                dfs(j - 1, t - j);
                path.pop_back();
            }
        };
        dfs(9, n);
        return ans;
    }
};
