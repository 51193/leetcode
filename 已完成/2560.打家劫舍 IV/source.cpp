#include<iostream>
#include<vector>
#include<algorithm>

using std::vector;

class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        
        int max{*max_element(nums.begin(), nums.end())};
        int min{*min_element(nums.begin(), nums.end())};

        while(max>=min){
            
            int mid{(max+min)/2};
            int cnt{0};

            bool flag{false};

            for(int i:nums){
                if(i<=mid&&!flag){
                    flag=true;
                    cnt++;
                }
                else{
                    flag=false;
                }
            }

            if(cnt<k){
                min=mid+1;
            }
            else{
                max=mid-1;
            }
        }

        return min; 
    }
};

int main(){
    vector<int>nums{2,7,9,3,1};
    int k=2;

    Solution s;

    std::cout<<s.minCapability(nums,k)<<std::endl;
}