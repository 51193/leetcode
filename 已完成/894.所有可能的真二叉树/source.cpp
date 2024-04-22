#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<TreeNode *> allPossibleFBT(int n)
    {
        if (n % 2 == 0)
        {
            return {};
        }

        vector<vector<TreeNode *>> dp(n + 1);
        dp[1] = {new TreeNode(0)};
        for (int i = 3; i <= n; i += 2)
        {
            for (int j = 1; j < i; j += 2)
            {
                for (TreeNode *leftSubtree : dp[j])
                {
                    for (TreeNode *rightSubtrees : dp[i - 1 - j])
                    {
                        TreeNode *root = new TreeNode(0, leftSubtree, rightSubtrees);
                        dp[i].emplace_back(root);
                    }
                }
            }
        }
        return dp[n];
    }
};