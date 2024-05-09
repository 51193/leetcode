#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minimumRefill(vector<int> &plants, int capacityA, int capacityB)
    {
        int n = plants.size();
        int index = 0;
        int a = capacityA;
        int b = capacityB;
        int ans = 0;

        for (; index <= n - index - 1; index++)
        {
            if (index < n - index - 1)
            {
                if (a < plants[index])
                {
                    ans++;
                    a = capacityA - plants[index];
                }
                else
                {
                    a -= plants[index];
                }

                if (b < plants[n - index - 1])
                {
                    ans++;
                    b = capacityB - plants[n - index - 1];
                }
                else
                {
                    b -= plants[n - index - 1];
                }
            }
            else
            {
                int temp = max(a, b);
                if (temp < plants[index])
                {
                    ans++;
                }
            }
        }

        return ans;
    }
};