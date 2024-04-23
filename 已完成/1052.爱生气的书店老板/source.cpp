#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes)
    {
        int n = customers.size();
        int total = 0;
        for (int i{0}; i < n; i++)
        {
            if (!grumpy[i])
            {
                total += customers[i];
            }
        }
        int temp = 0;
        for (int i{0}; i < minutes; i++)
        {
            if (grumpy[i])
            {
                temp += customers[i];
            }
        }
        int max_temp = temp;
        int ptr = 0;
        while (ptr + minutes < n)
        {
            if (grumpy[ptr])
            {
                temp -= customers[ptr];
            }
            if (grumpy[ptr + minutes])
            {
                temp += customers[ptr + minutes];
            }
            ptr++;
            max_temp = max(max_temp, temp);
        }

        return total + max_temp;
    }
};