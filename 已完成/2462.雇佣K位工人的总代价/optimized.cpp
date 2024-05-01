#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;

// 优化了一下，好像SB的是我，题没毛病
struct employee
{
    int val;
    int pos;

    const bool operator<(const employee &x) const
    {
        if (val != x.val)
        {
            return val < x.val;
        }
        else
        {
            return pos < x.pos;
        }
    }
    const bool operator>(const employee &x) const
    {
        if (val != x.val)
        {
            return val > x.val;
        }
        else
        {
            return pos > x.pos;
        }
    }
};

class Solution
{
public:
    long long totalCost(vector<int> &costs, int k, int candidates)
    {
        long long ans = 0;

        priority_queue<employee, vector<employee>, greater<employee>> pque;

        int n = costs.size();

        int front_pos = 0;
        int back_pos = n - 1;

        int temp = max(candidates, n - candidates);
        for (; front_pos < candidates; front_pos++)
        {
            pque.push(employee(costs[front_pos], front_pos));
        }
        for (; back_pos >= temp; back_pos--)
        {
            pque.push(employee(costs[back_pos], back_pos));
        }

        while (k--)
        {
            auto var = pque.top();
            ans += var.val;
            pque.pop();
            if (front_pos <= back_pos)
            {
                if (var.pos < front_pos)
                {
                    pque.push(employee(costs[front_pos], front_pos++));
                }
                else
                {
                    pque.push(employee(costs[back_pos], back_pos--));
                }
            }
        }
        return ans;
    }
};