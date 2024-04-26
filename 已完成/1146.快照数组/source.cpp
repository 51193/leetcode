#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// 效率比较差，但是内存省
struct record
{
    int inst_id;
    int from;
    int to;
};

class SnapshotArray
{
public:
    unordered_map<int, vector<record>> memory;

    int inst_cnt;
    vector<int> snap_map;

    SnapshotArray(int length)
        : inst_cnt{0}
    {
    }

    void set(int index, int val)
    {
        record r;
        r.inst_id = inst_cnt++;
        if (memory[index].empty())
        {
            r.from = 0;
        }
        else
        {
            r.from = (memory[index].rbegin())->to;
        }
        r.to = val;
        memory[index].push_back(r);
    }

    int snap()
    {
        snap_map.push_back(inst_cnt);
        return snap_map.size() - 1;
    }

    int get(int index, int snap_id)
    {
        int inst = snap_map[snap_id];
        int value = 0;
        for (auto &i : memory[index])
        {
            if (i.inst_id < inst)
            {
                value = i.to;
            }
            else
            {
                break;
            }
        }
        return value;
    }
};