#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// 写得有点笨
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct Graph
{
    TreeNode *node;
    vector<int> near;
    int time = 0x7fffffff;
};

class Solution
{
public:
    int amountOfTime(TreeNode *root, int start)
    {
        vector<Graph> g;

        unordered_map<int, Graph> map;

        stack<TreeNode *> stk;
        stack<int> root_stk;

        Graph cur;
        cur.node = root;
        if (root->left)
        {
            stk.push(root->left);
            root_stk.push(root->val);
            cur.near.push_back(root->left->val);
        }
        if (root->right)
        {
            stk.push(root->right);
            root_stk.push(root->val);
            cur.near.push_back(root->right->val);
        }
        map[root->val] = cur;

        while (!stk.empty())
        {
            auto temp = stk.top();
            stk.pop();

            auto temp_root = root_stk.top();
            root_stk.pop();

            Graph x;
            x.node = temp;
            x.near.push_back(temp_root);
            if (temp->left)
            {
                stk.push(temp->left);
                root_stk.push(temp->val);
                x.near.push_back(temp->left->val);
            }
            if (temp->right)
            {
                stk.push(temp->right);
                root_stk.push(temp->val);
                x.near.push_back(temp->right->val);
            }
            map[temp->val] = x;
        }

        stack<int> scanner;
        int max_time = 0;

        scanner.push(start);
        map[start].time = 0;

        while (!scanner.empty())
        {
            auto a = scanner.top();
            scanner.pop();

            int b = map[a].time;

            for (auto &i : map[a].near)
            {
                if (map[i].time > b + 1)
                {
                    map[i].time = b + 1;
                    scanner.push(i);
                    max_time = max(max_time, b + 1);
                }
            }
        }

        return max_time;
    }
};