#include<iostream>

class Solution {
public:
    int passThePillow(int n, int time) {
        time %= (2 * (n - 1));
        return std::min(time + 1, n - (time - (n - 1)));
    }
};

int main(){
    Solution test;
    std::cout << test.passThePillow(9, 4) << std::endl;
}