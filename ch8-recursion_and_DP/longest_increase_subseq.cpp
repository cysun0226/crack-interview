#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> curr_max(nums.size(), 1);
        for (size_t i = 1; i < nums.size(); i++) {
            for (size_t j = 0; j < i; j++) {
                if (nums[j] < nums[i] && curr_max[i] < curr_max[j]+1) {
                    curr_max[i] = curr_max[j]+1;
                }
            }
        }

        return *max_element(curr_max.begin(), curr_max.end());
    }
};