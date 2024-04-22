#include <vector>
#include <iostream>

using std::vector;

class Solution
{
public:
    long long maxArrayValue(vector<int> &nums)
    {
        long long temp = *(nums.rbegin());
        for (int i{(int)nums.size() - 2}; i >= 0; i--)
        {
            if (nums[i] <= temp)
            {
                temp += nums[i];
            }
            else
            {
                temp = nums[i];
            }
        }
        return temp;
    }
};

int main()
{
    vector<int> i{2,3,7,9,3};
    Solution s;
    auto a = s.maxArrayValue(i);
    std::cout << a;
}