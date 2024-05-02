#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    double mincostToHireWorkers(vector<int> &quality, vector<int> &wage, int k)
    {
        int n = quality.size();
        vector<int> index(n, 0);

        for (int i{0}; i < n; i++)
        {
            index[i] = i;
        }

        sort(index.begin(), index.end(), [wage, quality](int a, int b)
             { return ((static_cast<double>(wage[a])) / (static_cast<double>(quality[a]))) < ((static_cast<double>(wage[b])) / (static_cast<double>(quality[b]))); });

        priority_queue<int, vector<int>, less<int>> que;
        int qua_sum = 0;
        double effi = 0;
        int pointer = 0;

        for (; pointer < k; pointer++)
        {
            int temp = index[pointer];
            que.push(quality[temp]);
            effi = (static_cast<double>(wage[temp])) / (static_cast<double>(quality[temp]));
            qua_sum += quality[temp];
        }

        double ans = effi * qua_sum;

        for (; pointer < n; pointer++)
        {
            int temp = index[pointer];
            if (que.top() > quality[temp])
            {
                qua_sum -= que.top();
                que.pop();
                que.push(quality[temp]);
                qua_sum += quality[temp];
                effi = (static_cast<double>(wage[temp])) / (static_cast<double>(quality[temp]));

                ans = min(ans, effi * qua_sum);
            }
        }

        return ans;
    }
};