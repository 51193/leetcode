#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    string maximumBinaryString(string binary)
    {
        int n = binary.size();
        int cnt = 0;
        int cnt_total = 0;
        bool a = false;
        for (size_t i{0}; i < n; i++)
        {
            if (binary[i] == '1')
            {
                cnt_total++;
                if (a)
                    cnt++;
            }
            else
            {
                a = true;
            }
        }

        string ans(n, '1');
        if (cnt_total < n)
            ans[n - cnt - 1] = '0';
        return ans;
    }
};