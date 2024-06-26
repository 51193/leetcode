#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        vector<int> scan(n, 0);

        int temp{0};
        for (int i{0}; i < n; i++)
        {
            if (height[i] > temp)
            {
                temp = height[i];
            }
            scan[i] = temp;
        }

        temp = 0;
        int ans = 0;
        for (int i{n - 1}; i >= 0; i--)
        {
            if (height[i] > temp)
            {
                temp = height[i];
            }
            ans += min(temp, scan[i]) - height[i];
        }

        return ans;
    }
};