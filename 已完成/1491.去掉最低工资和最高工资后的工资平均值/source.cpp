#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution
{
public:
    double average(vector<int> &salary)
    {
        int n = salary.size();
        sort(salary.begin(), salary.end());
        long long total = accumulate(salary.begin() + 1, salary.end() - 1, 0);
        return static_cast<double>(total) / static_cast<double>(n - 2);
    }
};