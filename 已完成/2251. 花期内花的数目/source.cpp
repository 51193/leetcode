#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<numeric>

//只击败10%，烂

class Solution {
public:
    std::vector<int> fullBloomFlowers(std::vector<std::vector<int>>& flowers, std::vector<int>& people) {

        std::vector<int> answer(people.size());

        std::vector<int> people_serial(people.size());
        std::iota(people_serial.begin(), people_serial.end(), 0);
        std::sort(people_serial.begin(), people_serial.end(),
        [&](int a, int b) {
            return people[a] < people[b];
        });

        std::map<int, int> diff;

        for(auto& i: flowers) {
            diff[i[0]]++;
            diff[i[1] + 1]--;
        }

        int cnt{0};
        auto p = diff.begin();
        for(auto& i: people_serial) {
            while(p != diff.end() && p->first <= people[i]) {
                cnt += p->second;
                p++;
            }
            answer[i] = cnt;
        }

        return answer;

    }
};

int main() {
    Solution test;

    std::vector<std::vector<int>> flowers{{1, 6}, {3, 7}, {9, 12}, {4, 13}};
    std::vector<int> people {2, 3, 7, 11};

    std::vector<int> answer = test.fullBloomFlowers(flowers, people);

    for(auto& i: answer) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}