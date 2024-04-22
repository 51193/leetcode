#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        vector<int> vec(amount + 1, 0);

        vec[0] = 1;

        for (auto &i : coins)
        {
            for (int j{i}; j < amount + 1; j++)
            {
                vec[j] += vec[j - i];
            }
        }

        return *(vec.rbegin());
    }
};

int main()
{
    Solution s;
    vector<int> coins{1, 101, 102, 103};
    cout << s.change(100, coins);
}