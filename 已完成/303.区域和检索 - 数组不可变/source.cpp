#include <iostream>
#include <vector>
using namespace std;

class NumArray
{
public:
    vector<int> vec;
    vector<int> nums;

    NumArray(vector<int> &nums)
    {
        vec.resize(nums.size() + 1);
        this->nums = nums;
        for (size_t i{0}; i < nums.size(); i++)
        {
            vec[i + 1] = vec[i] + nums[i];
        }

        // for (auto &i : vec)
        // {
        //     cout << i << ' ';
        // }
        // cout << endl;
    }

    int sumRange(int left, int right)
    {
        return vec[right + 1] - vec[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */

int main()
{
    vector<int> v{-2, 0, 3, -5, 2, -1};
    NumArray n(v);
    cout << n.sumRange(0, 2) << endl;
    cout << n.sumRange(2, 5) << endl;
    cout << n.sumRange(0, 5) << endl;
}