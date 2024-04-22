#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int minimumSum(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> vec(nums.size(), 0x7fffffff);
        vec[0] = nums[0];

        for (int i{1}; i < n; i++)
        {
            vec[i] = min(vec[i - 1], nums[i]);
        }

        int a = *(nums.rbegin());
        int ans = 0x7fffffff;
        for (int i{n - 2}; i >= 0; i--)
        {
            if (vec[i] < nums[i] && a < nums[i])
            {
                ans = min(ans, vec[i] + nums[i] + a);
            }

            a = min(nums[i], a);
        }

        if (ans == 0x7fffffff)
            return -1;

        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> v{8, 6, 1, 5, 3};
    cout << s.minimumSum(v);
}
