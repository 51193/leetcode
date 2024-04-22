#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        int ans_length = 0;
        string ans;
        for (int i{0}; i < n; i++)
        {
            int j = 0;
            int ans_length1 = -1;
            int ans_length2 = 0;
            while (s[i - j] == s[i + j])
            {
                ans_length1 += 2;
                if (ans_length1 > ans_length)
                {
                    ans_length = ans_length1;
                    ans = string(s.begin() + i - j, s.begin() + i + j + 1);
                }
                j++;
                if (i - j < 0 || i + j >= n)
                {
                    break;
                }
            }
            j = 0;
            while (i + j + 1 < n && s[i - j] == s[i + 1 + j])
            {
                ans_length2 += 2;
                if (ans_length2 > ans_length)
                {
                    ans_length = ans_length2;
                    ans = string(s.begin() + i - j, s.begin() + i + j + 2);
                }
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