/**
* Leetcode 34
* https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
*/

#include <vector>

using namespace std;

class Solution {
private:
    int left_bound = -1, right_bound = -1;

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (!nums.empty())
            search(nums, target, 0, nums.size()-1);
        if (nums.size() == 1 && nums[0] == target) {
            left_bound = 0, right_bound = 0;
        }
        
        return vector<int> {left_bound, right_bound};
    }

    void search(vector<int>& nums, int target, int left, int right) {
        if (target < nums[left]) return;
        if (target > nums[right]) return;
        if (left >= right) return;

        // meet the target
        if (target == nums[left] && target <= nums[right]) {
            for (size_t i = left; i <= right && nums[i] == target; i++) {
                right_bound = i;
            }
            if (left_bound == -1) left_bound = left;
            return;
        }
        if (target == nums[right] && target >= nums[left]) {
            for (size_t i = right; i >= left && nums[i] == target; i--) {
                left_bound = i;
            }
            if (right_bound == -1) right_bound = right;
            return;
        }
        
        if (right == left+1) return;
        
        int mid = left + (right - left)/2;
        search(nums, target, left, mid);
        search(nums, target, mid, right);
    }
};

int main() {
    // vector<int> test = {5,7,7,8,8,10};
    vector<int> test = {1, 3};
    int target = 1;
    Solution().searchRange(test, target);

    return 0;
}