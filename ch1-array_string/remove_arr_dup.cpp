/**
* Leetcode 26
* https://leetcode.com/problems/remove-duplicates-from-sorted-array/ 
*/

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) 
            return 0;

        int curr = nums[0];
        vector<int> dup_idx;
        for (int i = 1; i < nums.size(); i++){
            if (nums[i] == curr) {
                dup_idx.push_back(i);
            }
            curr = nums[i];
        }

        // delete the duplicate indices from back
        for (int i = dup_idx.size()-1; i >= 0; i--) {
            nums.erase(nums.begin()+dup_idx[i]);
        }
        
        return nums.size();
    }
};

int main() {
    vector<int> test = {1, 1, 2};
    Solution().removeDuplicates(test);

    return 0;
}