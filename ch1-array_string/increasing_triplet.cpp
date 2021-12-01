/**
* Leetcode 334
* https://leetcode.com/problems/increasing-triplet-subsequence/
*/ 

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        // find the smallest
        int smallest = INT32_MAX, smallest_idx = 0;
        for (size_t i = 0; i < nums.size(); i++) {
            if (nums[i] < smallest) {
                smallest = nums[i];
                smallest_idx = i;
            }
        }

        // find the increasing triplet
        vector<int> increasing_stack = {smallest};
        for (size_t i = smallest_idx; i < nums.size(); i++) {
            if (nums[i] > increasing_stack.back()) {
                increasing_stack.push_back(nums[i]);
            }
        }

       return (increasing_stack.size() >= 3);
    }
};