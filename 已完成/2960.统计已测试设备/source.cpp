#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int countTestedDevices(vector<int> &batteryPercentages)
    {
        int ans = 0;
        for (auto &i : batteryPercentages)
        {
            if (i > ans)
            {
                ans++;
            }
        }
        return ans;
    }
};