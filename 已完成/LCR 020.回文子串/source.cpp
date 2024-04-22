#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    int countSubstrings(string s)
    {
        int n = s.size();
        int ans = 0;
        for (int i{0}; i < n; i++)
        {
            int j = 0;
            while (s[i - j] == s[i + j])
            {
                ans++;
                j++;
                if (i - j < 0 || i + j >= n)
                {
                    break;
                }
            }
            j = 0;
            while (i + j + 1 < n && s[i - j] == s[i + 1 + j])
            {
                ans++;
                j++;
                if (i - j < 0)
                {
                    break;
                }
            }
        }
        return ans;
    }
};