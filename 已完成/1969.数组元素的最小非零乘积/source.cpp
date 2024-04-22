#include <iostream>
#include <cmath>
using namespace std;

class Solution
{
public:
    int minNonZeroProduct(int p)
    {
        const unsigned int m = 1000000007;
        unsigned long long int x = (1LL << p) - 2;
        unsigned long long int y = x + 1;
        unsigned long long int t = y / 2;
        unsigned long long int ans = 1;

        x %= m;
        y %= m;

        while (t)
        {
            if (t & 1)
            {
                ans = (ans * x) % m;
            }
            t /= 2;
            x = (x * x) % m;
        }
        ans = (ans * y) % m;
        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.minNonZeroProduct(33);
}