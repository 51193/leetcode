#include <iostream>
#include <stack>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target)
    {
        stack<TreeNode *> cloned_stk;
        cloned_stk.push(cloned);
        while (!cloned_stk.empty())
        {
            TreeNode *temp = cloned_stk.top();
            cloned_stk.pop();
            if (temp->val == target->val)
                return temp;
            if (temp->left != NULL)
            {
                cloned_stk.push(temp->left);
            }
            if (temp->right != NULL)
            {
                cloned_stk.push(temp->right);
            }
        }
        return NULL;
    }
};