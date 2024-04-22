#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution
{
public:
    bool isValidSerialization(string preorder)
    {
        string temp;
        stack<int> stk;
        bool is_fin = false;
        stk.push(0);
        for (size_t i{0}; i < preorder.size(); i++)
        {
            if (preorder[i] != ',')
            {
                temp.append(1, preorder[i]);
            }
            else
            {
                if (temp == "#")
                {
                    stk.pop();
                    if (stk.empty())
                        is_fin = true;
                }
                else
                {
                    if (is_fin)
                        return false;
                    stk.push(0);
                }
                temp.clear();
            }
        }
        if (temp == "#")
        {
            stk.pop();
            if (stk.empty())
                is_fin = true;
        }
        else
        {
            if (is_fin)
                return false;
            stk.push(0);
        }
        temp.clear();
        return stk.empty();
    }
};