/**
* Leetcode 1748
* https://leetcode.com/problems/sum-of-unique-elements/
*/ 

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        map<int,int> num_count;
        for (size_t i = 0; i < nums.size(); i++){
            // if not in the map
            if (num_count.find(nums[i]) == num_count.end())
                num_count[nums[i]] = 1;
            else
                num_count[nums[i]]++;
        }

        int sum = 0;
        auto iter = num_count.begin();
        while (iter != num_count.end()){
            if (iter->second == 1)
                sum += iter->first;
            iter++;
        }
        return sum;
    }
};

int main(){
    std::vector<int> input1{1,1,1,2,2,3,4,4,5,5,5,5};
    cout << Solution().sumOfUnique(input1) << endl;

    return 0;
}