/**
* Leetcode 334
* https://leetcode.com/problems/increasing-triplet-subsequence/
*/ 

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool increasingTriplet_monostack(vector<int>& nums) {
        for (size_t i = 0; i < nums.size(); i++) {
            // find the increasing triplet
            vector<int> increasing_stack = {nums[i]};
            for (size_t j = i+1; j < nums.size(); j++) {
                if (nums[j] > increasing_stack.back()) {
                    increasing_stack.push_back(nums[j]);
                    
                    if (increasing_stack.size() >= 3)
                        return true;
                }
                // find the smaller middle element
                else if (increasing_stack.size() == 2 && nums[j] < increasing_stack[1] && nums[j] > increasing_stack[0]) {
                    increasing_stack.pop_back();
                    increasing_stack.push_back(nums[j]);
                }
            }
        }
        return false;
    }

    bool increasingTriplet(vector<int>& nums) {
        int min = INT32_MAX, mid = INT32_MAX;
        for (int n : nums) {
            if (n < min) min = n;
            else if (n != min && n < mid) mid = n;
            else if (n > mid) return true;
        }
        return false;
    }


};

int main() {
    vector<int> test = {1,5,0,4,1,3};
    Solution().increasingTriplet(test);
    
    return 0;
}