#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
using namespace std;

class Solution
{
public:
    string largestNumber(vector<int> &nums)
    {
        if (count(nums.begin(), nums.end(), 0) == nums.size())
        {
            return "0";
        }

        sort(nums.begin(), nums.end(), [](int a, int b)
             {
                string a_first;
                string b_first;
                a_first = to_string(a) + to_string(b);
                b_first = to_string(b) + to_string(a);

                return stoull(a_first) > stoull(b_first); });

        string ans;

        for (auto &i : nums)
        {
            ans += to_string(i);
        }

        return ans;
    }
};