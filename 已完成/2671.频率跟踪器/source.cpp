#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;


//答案只需要数量，不需要知道频率内的内容是什么，所以没必要这么写，但是这样写得也不慢
class FrequencyTracker
{
public:
    unordered_map<int, vector<int>> frequency;
    unordered_map<int, int> num_frequency;

    FrequencyTracker()
    {
    }

    void add(int number)
    {
        if (num_frequency[number] && num_frequency[number] != 0)
        {
            int temp = num_frequency[number];
            frequency[temp].erase(find(frequency[temp].begin(), frequency[temp].end(), number));
            temp++;
            num_frequency[number] = temp;
            frequency[temp].push_back(number);
        }
        else
        {
            num_frequency[number] = 1;
            frequency[1].push_back(number);
        }
    }

    void deleteOne(int number)
    {
        if (num_frequency[number] && num_frequency[number] != 0)
        {
            int temp = num_frequency[number];
            frequency[temp].erase(find(frequency[temp].begin(), frequency[temp].end(), number));
            temp--;
            num_frequency[number] = temp;
            frequency[temp].push_back(number);
        }
    }

    bool hasFrequency(int frequency)
    {
        return !(this->frequency[frequency].empty());
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */

int main()
{
    FrequencyTracker f;
    f.add(1);
    f.add(2);
    f.add(2);
    f.add(3);
    f.add(3);
    f.add(3);
    for (auto &i : f.num_frequency)
    {
        cout << i.first << " " << i.second << endl;
    }
}