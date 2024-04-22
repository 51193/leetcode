#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//这个写法复杂度太高，超时了
class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int n = nums.size();

        sort(nums.begin(), nums.end());
        auto m = unique(nums.begin(), nums.begin() + n);

        vector<int> unique_vec(nums.begin(), m);

        int b = unique_vec.size();
        int a = n - b;

        int min = unique_vec[0];
        int max = min + n - 1;

        int l = unique_vec[b - 1];

        bool x = true;

        int temp = b;
        while (x && min <= l)
        {
            int cnt = 0;
            for (size_t i{0}; i < b; i++)
            {
                if (unique_vec[i] < min)
                {
                    cnt++;
                }
                else
                {
                    break;
                }
            }
            if (cnt >= temp)
            {
                x = false;
                break;
            }
            for (size_t i{(size_t)b - 1}; i >= 0; i--)
            {
                if (unique_vec[i] > max)
                {
                    cnt++;
                }
                else
                {
                    break;
                }
            }
            if (cnt < temp)
            {
                temp = cnt;
            }
            min++;
            max++;
        }

        return a + temp;
    }
};

//这个写法牛
class Solution {
public:
    int minOperations(vector<int> &nums) {
        ranges::sort(nums);
        int n = nums.size();
        int m = unique(nums.begin(), nums.end()) - nums.begin(); // 原地去重
        int ans = 0, left = 0;
        for (int i = 0; i < m; i++) {
            while (nums[left] < nums[i] - n + 1) { // nums[left] 不在窗口内
                left++;
            }
            ans = max(ans, i - left + 1);
        }
        return n - ans;
    }
};
