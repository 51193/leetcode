#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;

//SB模拟题，纯折磨人
struct employee
{
    int val;
    int pos;

    const bool operator<(const employee &x) const
    {
        if (val < x.val)
        {
            return true;
        }
        else if (val > x.val)
        {
            return false;
        }
        else
        {
            if (pos < x.pos)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
    const bool operator>(const employee &x) const
    {

        if (val > x.val)
        {
            return true;
        }
        else if (val < x.val)
        {
            return false;
        }
        else
        {
            if (pos > x.pos)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
};

class Solution
{
public:
    long long totalCost(vector<int> &costs, int k, int candidates)
    {
        long long ans = 0;

        int n = costs.size();
        priority_queue<employee, vector<employee>, greater<employee>> que_front;
        priority_queue<employee, vector<employee>, greater<employee>> que_back;
        int front_pos;
        int back_pos;
        unordered_map<int, bool> hired;

        int temp = max(candidates, n - candidates);
        for (front_pos = 0; front_pos < candidates; front_pos++)
        {
            que_front.push(employee(costs[front_pos], front_pos));
            hired[front_pos] = true;
        }
        for (back_pos = n - 1; back_pos >= temp; back_pos--)
        {
            que_back.push(employee(costs[back_pos], back_pos));
            hired[back_pos] = true;
        }

        for (int i{0}; i < k; i++)
        {
            employee x;
            employee y;

            if (!que_front.empty())
            {
                x = que_front.top();
            }
            else
            {
                x.val = 0x7fffffff;
                x.pos = 0x7fffffff;
            }
            if (!que_back.empty())
            {
                y = que_back.top();
            }
            else
            {
                y.val = 0x7fffffff;
                y.pos = 0x7fffffff;
            }

            if (x < y)
            {
                que_front.pop();
                ans += x.val;
                if (front_pos < n && !hired[front_pos])
                {
                    que_front.push(employee(costs[front_pos], front_pos));
                    hired[front_pos] = true;
                    front_pos++;
                }
            }
            else
            {
                que_back.pop();
                ans += y.val;
                if (back_pos >= 0 && !hired[back_pos])
                {
                    que_back.push(employee(costs[back_pos], back_pos));
                    hired[back_pos] = true;
                    back_pos--;
                }
            }
        }
        return ans;
    }
};