#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> findOriginalArray(vector<int> &changed)
    {
        vector<int> ans;
        if (changed.size() % 2 != 0)
        {
            return ans;
        }
        ans.reserve(changed.size() / 2);

        sort(changed.begin(), changed.end(), [](int a, int b)
             { return a < b; });

        unordered_map<int, int> map;

        for (auto &i : changed)
        {
            if (i % 2 == 0 && map[i / 2])
            {
                ans.push_back(i / 2);
                map[i / 2]--;
            }
            else
            {
                map[i]++;
            }
        }
        if (ans.size() != changed.size() / 2)
        {
            ans.clear();
        }
        return ans;
    }
};