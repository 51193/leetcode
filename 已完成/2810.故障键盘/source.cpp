#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string finalString(string s)
    {
        string ans;
        for (auto &i : s)
        {
            if (i == 'i')
            {
                reverse(ans.begin(), ans.end());
            }
            else
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};